#include "algo/mpi_info.h"

namespace apsara {
namespace odps {
namespace algo {
/**
如果知道了总的并行机器数、自己所在的机器序号、表的总行数，要计算平均每个机器读多少行、自己该从第几行开始读，不难吧？特征的切片方式和样本类似，
只是被切分的是总的列数。因此，我们需要知道总的机器数和自己机器的序号，该MPI函数出场了。标准MPI库函数MPI_Comm_size和MPI_Comm_rank可以达到我们的目的
**/
MpiInfo::MpiInfo() {
  Comm(MPI_COMM_WORLD);
  MPI_Comm_size(MPI_COMM_WORLD, &mNRankId);
  MPI_Comm_rank(MPI_COMM_WORLD, &mRankId);
}

MpiInfo::MpiInfo(const MPI_Comm& comm) {
  Comm(comm);
  MPI_Comm_size(MPI_COMM_WORLD, &mNRankId);
  MPI_Comm_rank(MPI_COMM_WORLD, &mRankId);
}

const MPI_Comm& MpiInfo::Comm() const { return mComm; }

int MpiInfo::Rank() const { return mRankId; }

int MpiInfo::NRank() const { return mNRankId; }

}  // namespace algo
}  // namespace odps
}  // namespace apsara