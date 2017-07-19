// Copyright (c) 2015, Alibaba Inc.
// All right reserved.
//
// Author: Kun ZHAO <kun.zhao@alibaba-inc.com>
// Created: 2015/12/18
// Description
// GLOBAL_NOLINT

#ifndef BASE_DATA_IO_MAP_COLUMN_WRAPPER_H
#define BASE_DATA_IO_MAP_COLUMN_WRAPPER_H

#include <stdint.h>
#include <map>
#include <list>
#include "base/data_io/map_column.h"

namespace pai_algo {
namespace base {

class MapColumnWrapperBase
{
public:
    explicit MapColumnWrapperBase(MapColumn* column)
        : mColumn(column)
    {
    }

    virtual ~MapColumnWrapperBase()
    {
    }

    ColumnType KeyType() const
    {
        return mColumn->KeyType();
    }

    ColumnType ValueType() const
    {
        return mColumn->ValueType();
    }

    int32_t Size() const
    {
        return mColumn->Size();
    }

protected:
    MapColumn* mColumn;
};

/*
 * Be sure that, when key or value type is kInt, use int64_t to init.
 */

template<class T1, class T2>
class MapColumnWrapper : public MapColumnWrapperBase
{
public:
    explicit MapColumnWrapper(MapColumn* column)
        : MapColumnWrapperBase(column)
    {
    }

    T1 Key(int32_t index) const
    {
        int32_t len = 0;
        void* key = mColumn->Key(index, &len);
        return *(static_cast<T1*>(key));
    }

    T2 Value(int32_t index) const
    {
        int32_t len = 0;
        void* value = mColumn->Value(index, &len);
        return *(static_cast<T2*>(value));
    }

    void Append(T1 key, T2 value)
    {
        typeof(mTmp.begin()) it = mTmp.insert(mTmp.begin(), std::make_pair(key, value));
        mColumn->Append(&(it->first), sizeof(key), &(it->second), sizeof(value));
    }

    void Clear()
    {
        mTmp.clear();
        mColumn->Clear();
    }

private:
    std::map<T1, T2> mTmp;
};

template<class T2>
class MapColumnWrapper<char*, T2> : public MapColumnWrapperBase
{
public:
    explicit MapColumnWrapper(MapColumn* column)
        : MapColumnWrapperBase(column)
    {
    }

    char* Key(int32_t index, int32_t* len) const
    {
        return static_cast<char*>(mColumn->Key(index, len));
    }

    T2 Value(int32_t index) const
    {
        int32_t len = 0;
        void* value = mColumn->Value(index, &len);
        return *(static_cast<T2*>(value));
    }

    void Append(const char* key, int32_t len, T2 value)
    {
        mTmp.push_back(value);
        mColumn->Append(key, len, &(mTmp.back()), sizeof(value));
    }

    void Clear()
    {
        mTmp.clear();
        mColumn->Clear();
    }

private:
    std::list<T2> mTmp;
};

template<class T1>
class MapColumnWrapper<T1, char*> : public MapColumnWrapperBase
{
public:
    explicit MapColumnWrapper(MapColumn* column)
        : MapColumnWrapperBase(column)
    {
    }

    T1 Key(int32_t index) const
    {
        int32_t len = 0;
        void* key = mColumn->Key(index, &len);
        return *(static_cast<T1*>(key));
    }

    char* Value(int32_t index, int32_t* len) const
    {
        return static_cast<char*>(mColumn->Value(index, len));
    }

    void Append(T1 key, const char* value, int32_t len)
    {
        mTmp.push_back(key);
        mColumn->Append(&(mTmp.back()), sizeof(key), value, len);
    }

    void Clear()
    {
        mTmp.clear();
        mColumn->Clear();
    }

private:
    std::list<T1> mTmp;
};

template<>
class MapColumnWrapper<char*, char*> : public MapColumnWrapperBase
{
public:
    explicit MapColumnWrapper(MapColumn* column)
        : MapColumnWrapperBase(column)
    {
    }

    char* Key(int32_t index, int32_t* len) const
    {
        return static_cast<char*>(mColumn->Key(index, len));
    }

    char* Value(int32_t index, int32_t* len) const
    {
        return static_cast<char*>(mColumn->Value(index, len));
    }

    void Append(const char* key, int32_t len1, const char* value, int32_t len2)
    {
        mColumn->Append(key, len1, value, len2);
    }

    void Clear()
    {
        mColumn->Clear();
    }
};

} // namespace base
} // namespace pai_algo



#endif // BASE_DATA_IO_MAP_COLUMN_WRAPPER_H
