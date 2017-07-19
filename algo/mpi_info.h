#ifndef ALGO_MPI_INFO_H
#define ALGO_MPI_INFO_H

#include "algo/include/common/uncopyable.h"
#include "mpi/mpi.h"

namespace apsara {
namespace odps {
namespace algo {

class MpiInfo : private veil::Uncopyable {
 public:
  MpiInfo();
  explicit MpiInfo(const MPI_Comm& comm);

  /** get communicator */
  const MPI_Comm& Comm() const;
  /** get rank */
  int Rank() const;
  /** get n-rank */
  int NRank() const;

 private:
  int mRankId;
  int mNRankId;
  MPI_Comm mComm;
};

}  // namespace algo
}  // namespace odps
}  // namespace apsara

#endif  // ALGO_MPI_INFO_H