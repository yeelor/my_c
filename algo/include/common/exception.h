// Copyright (c) 2014, Alibaba Inc.
// All right reserved.
//
// Author: Kun ZHAO <kun.zhao@alibaba-inc.com>
// Created: 2014/12/2
// Description

#ifndef BASE_COMMON_EXCEPTION_H
#define BASE_COMMON_EXCEPTION_H

#include <exception>
#include <string>

#include "algo/include/common/exception.h"

namespace pai_algo {
namespace base {

#define PAI_THROW(ExClass, args...)                        \
    do                                                     \
    {                                                      \
        ExClass tmp_algo_internal_exception(args);         \
        tmp_algo_internal_exception.Init(                  \
            __FILE__, __PRETTY_FUNCTION__, __LINE__);      \
        throw tmp_algo_internal_exception;                 \
    } while (false)

#define PAI_DEFINE_EXCEPTION(ExClass, Base)           \
    ExClass() {}                                      \
    ExClass(const std::string& msg)                   \
        : Base(msg) {}                                \
                                                      \
    ~ExClass() throw() {}                             \
                                                      \
    /* override */ std::string GetClassName() const   \
    {                                                 \
        return #ExClass;                              \
    }                                                 \


typedef ::apsara::odps::algo::BaseException BaseException;

class SystemException : public BaseException
{
public:
    PAI_DEFINE_EXCEPTION(SystemException, BaseException)
};

class AlgoException : public BaseException
{
public:
    PAI_DEFINE_EXCEPTION(AlgoException, BaseException)
};

class UserException : public BaseException
{
public:
    PAI_DEFINE_EXCEPTION(UserException, BaseException)
};

class NotFoundException : public AlgoException
{
public:
    PAI_DEFINE_EXCEPTION(NotFoundException, AlgoException)
};

class AlreadyExistException : public AlgoException
{
public:
    PAI_DEFINE_EXCEPTION(AlreadyExistException, AlgoException)
};

class InvalidArgumentException : public AlgoException
{
public:
    PAI_DEFINE_EXCEPTION(InvalidArgumentException, AlgoException)
};

class InvalidOperationException : public AlgoException
{
public:
    PAI_DEFINE_EXCEPTION(InvalidOperationException, AlgoException)
};

class LockedException : public SystemException
{
public:
    PAI_DEFINE_EXCEPTION(LockedException, SystemException)
};

class NoPermissionException : public SystemException
{
public:
    PAI_DEFINE_EXCEPTION(NoPermissionException, SystemException)
};

class TimeoutException : public SystemException
{
public:
    PAI_DEFINE_EXCEPTION(TimeoutException, SystemException)
};

class OutOfResourceException : public SystemException
{
public:
    PAI_DEFINE_EXCEPTION(OutOfResourceException, SystemException)
};

class UnexpectedEndOfStreamException : public SystemException
{
public:
    PAI_DEFINE_EXCEPTION(UnexpectedEndOfStreamException, SystemException)
};

class StreamCorruptedException : public SystemException
{
public:
    PAI_DEFINE_EXCEPTION(StreamCorruptedException, SystemException)
};


} /* base */
} /* pai_algo */


#endif // BASE_COMMON_EXCEPTION_H

