#include "algo/dup_table.h"
#include "algo/mpi_distributor.h"

namespace apsara {
namespace odps {
namespace algo {

void DupTable::Run(MPIContext* ctx)
{
    TableReader* tableReader = ctx->CreateTableReader("inputTable"); // inputTable 需在xflow中定义
    TableWriter* tableWriter = ctx->CreateTableWriter("outputTable"); // outputTable 需在xflow中定义

    Duplicate(tableReader, tableWriter);

    tableReader->Close();
    tableWriter->Close();
    ctx->ReleaseTableReader(tableReader);
    ctx->ReleaseTableWriter(tableWriter); 
}

void DupTable::Duplicate(TableReader* reader, TableWriter* writer)
{
    MpiInfo mpiInfo;
    reader->Open();
    writer->Open(mpiInfo.Rank());

    const TableSchema& readSchema = reader->GetSchema();
    const TableSchema& writeSchema = writer->GetSchema();
    if (readSchema != writeSchema) {
        ALGO_THROW(UserException, "Table schemas do not match.");
    }   

    MpiDistributor dist(&mpiInfo, tableReader->GetRowCount());   // 按行平分到各个mpi instance

    int64_t from = dist.LocalStart();                            // 计算当前instance读表的起止位置
    int64_t to = from + dist.LocalSize();

    reader->Seek(from); 

    TableRecord record(readSchema);
    reader->SetBufferRecord(&record);
    writer->SetBufferRecord(&record);

    while (reader->Read() && from < to) {
        writer->Write();
        ++from;
    }
}

} // namespace algo
} // namespace odps
} // namespace apsara

ALGO_REGISTER_MPI_WORKER(DupTable);