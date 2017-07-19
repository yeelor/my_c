// Copyright (c) 2015, Alibaba Inc.
// All right reserved.
//
// Author: Kun ZHAO <kun.zhao@alibaba-inc.com>
// Created: 2015/11/11
// Description

#ifndef BASE_DATA_IO_MAP_COLUMN_H
#define BASE_DATA_IO_MAP_COLUMN_H

#include <stdint.h>
#include <iostream>
#include <vector>
#include "base/common/uncopyable.h"
#include "base/data_io/table_schema.h"

namespace pai_algo {
namespace base {

/*
 * When column type is map, use MapColumn to get or set data.
 * MapColumn should be used as a buffer. When writing data, be sure that
 * all appended pointers(void*) are available before TableRecord.Set();
 */
class MapColumn : private veil::Uncopyable
{
public:
    MapColumn(ColumnType keyType, ColumnType valueType)
        : mKeyType(keyType), mValueType(valueType)
    {
    }

    ~MapColumn()
    {
    }

    int32_t Size() const
    {
        return mKeys.size();
    }

    void* Key(int32_t index, int32_t* len) const
    {
        *len = mKeyLens[index];
        return mKeys[index];
    }

    void* Value(int32_t index, int32_t* len) const
    {
        *len = mValueLens[index];
        return mValues[index];
    }

    ColumnType KeyType() const
    {
        return mKeyType;
    }

    ColumnType ValueType() const
    {
        return mValueType;
    }

    void Clear()
    {
        mKeys.clear();
        mValues.clear();
        mKeyLens.clear();
        mValueLens.clear();
    }

    void Append(const void* key, int32_t keyLen,
                const void* value, int32_t valueLen)
    {
        mKeys.push_back(const_cast<void*>(key));
        mValues.push_back(const_cast<void*>(value));
        mKeyLens.push_back(keyLen);
        mValueLens.push_back(valueLen);
    }

private:
    ColumnType mKeyType;
    ColumnType mValueType;
    std::vector<void*> mKeys;
    std::vector<void*> mValues;
    std::vector<int32_t> mKeyLens;
    std::vector<int32_t> mValueLens;
};

} // namespace base
} // namespace pai_algo


#endif // BASE_DATA_IO_MAP_COLUMN_H
