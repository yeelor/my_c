#ifndef ALGO_MPIDISTRIBUTOR_H
#define ALGO_MPIDISTRIBUTOR_H

#include <vector>
#include "algo/include/common/uncopyable.h"
#include "algo/mpi_info.h"

namespace apsara {
namespace odps {
namespace algo {

class MpiDistributor : private veil::Uncopyable
{
public :
    MpiDistributor(MpiInfo* mpiInfo, int64_t totalSize);

    int64_t Size() const;
    int64_t LocalSize() const;
    int64_t LocalStart() const;

    const int64_t* Begin() const;
    int64_t* Begin();

    const int64_t* All() const;
    int64_t* All();

    const MpiInfo& Info() const;

private:
    void Init();

private:
    MpiInfo* mInfo;
    int64_t mTotalSize;
    std::vector<int64_t> mBegNum;//每个进程rankId开始的记录数
    std::vector<int64_t> mAllNum;//每个进程rankId处理的记录总数
};

} // namespace algo
} // namespace odps
} // namespace apsara

#endif // ALGO_MPIDISTRIBUTOR_H