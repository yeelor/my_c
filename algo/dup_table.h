#ifndef ALGO_DUP_TABLE_H
#define ALGO_DUP_TABLE_H

#include "algo/include/data_io/table_reader.h"
#include "algo/include/data_io/table_writer.h"
#include "algo/include/mpi_algorithm.h"

namespace apsara {
namespace odps {
namespace algo {

class DupTable : public MPIAlgorithm
{
public:
    ~DupTable() {}
    /* override */ void Run(MPIContext* ctx);

private:
    void Duplicate(TableReader* reader, TableWriter* writer);
};

} // namespace algo
} // namespace odps
} // namespace apsara

#endif // ALGO_DUP_TABLE_H