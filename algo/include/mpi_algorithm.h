// Copyright (c) 2016, Alibaba Inc.
// All right reserved.
//
// Author: Kai Zhang <dota.zk@alibaba-inc.com>
// Created: 2016/08/18 16:31:02
// Last Modified: 2016/08/19 23:44:46
// Description
#ifndef BASE_WORKER_MPI_MPI_ALGORITHM_H
#define BASE_WORKER_MPI_MPI_ALGORITHM_H

namespace pai_algo {
namespace base {

/**
MPIContext定义了运行时上下文，可以获取环境参数、创建输入输出接口等。逻辑回归的输入数据位于ODPS表中，那么可以这样创建表的读接口：
**/

class MPIContext;

class MPIAlgorithm
{
public:
    virtual ~MPIAlgorithm() {}

    virtual void Run(MPIContext* context) = 0;
};


} /* base */
} /* pai_algo */


#endif // BASE_WORKER_MPI_MPI_ALGORITHM_H
