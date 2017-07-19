#include "algo/mpi_distributor.h"
#include "algo/include/common/exception.h"

namespace apsara {
namespace odps {
namespace algo {

MpiDistributor::MpiDistributor(MpiInfo* mpiInfo, int64_t totalSize)
    : mInfo(mpiInfo),
      mTotalSize(totalSize)
{
    Init();//初始化
}

int64_t MpiDistributor::Size() const
{
    return mTotalSize;
}

int64_t MpiDistributor::LocalSize() const
{
    return mAllNum[mInfo->Rank()];
}

int64_t MpiDistributor::LocalStart() const
{
    return Begin()[mInfo->Rank()];
}

const int64_t* MpiDistributor::Begin() const
{
    return &mBegNum[0];
}

int64_t* MpiDistributor::Begin()
{
    return const_cast<int64_t*>(
            static_cast<const MpiDistributor&>(*this)
            .Begin()
            );
}

const int64_t* MpiDistributor::All() const
{
    return &mAllNum[0];
}

int64_t* MpiDistributor::All()
{
    return const_cast<int64_t*>(
            static_cast<const MpiDistributor&>(*this).All());
}

//初始化
void MpiDistributor::Init()
{
    if (Size() <= 0) {
        ALGO_THROW(SystemException, "size() <= 0");
    }

    //http://www.cnblogs.com/biyeymyhjob/archive/2013/05/11/3072893.html
    //reserver函数用来给vector预分配存储区大小
    mBegNum.reserve(mInfo->NRank()+1);
    mAllNum.reserve(mInfo->NRank());
    //resize函数重新分配大小，改变容器的大小，并且创建对象
    mBegNum.resize(mInfo->NRank()+1);
    mAllNum.resize(mInfo->NRank());

    int64_t avg = mTotalSize / mInfo->NRank();
    int64_t re = mTotalSize % mInfo->NRank();

    for (int i = 0; i < mInfo->NRank(); ++i) {
        if (i < re) {
            mAllNum[i] = avg + 1;
        } else {
            mAllNum[i] = avg;
        }
    }

    mBegNum[0] = 0;
    for (int i = 1; i <= mInfo->NRank(); ++i) {
        mBegNum[i] = mBegNum[i-1] + mAllNum[i-1];
    }
}

const MpiInfo& MpiDistributor::Info() const
{
    return *mInfo;
}

} // namespace algo
} // namespace odps
} // namespace apsara