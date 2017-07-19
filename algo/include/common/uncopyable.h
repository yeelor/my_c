// Copyright (c) 2014, Alibaba Inc.
// All right reserved.
//
// Author: Kun ZHAO <kun.zhao@alibaba-inc.com>
// Created: 2014/10/29
// Description

#ifndef BASE_COMMON_UNCOPYABLE_H
#define BASE_COMMON_UNCOPYABLE_H

namespace pai_algo {
namespace base {
namespace veil {

class Uncopyable
{
protected:
    Uncopyable() {}
    virtual ~Uncopyable() {}

private:
    Uncopyable(const Uncopyable& o);
    Uncopyable& operator=(const Uncopyable& o);
};

} /* veil */
} /* base */
} /* pai_algo */


#endif // BASE_COMMON_UNCOPYABLE_H
