// Copyright (c) 2016, Alibaba Inc.
// All right reserved.
//
// Author: Kai Zhang <dota.zk@alibaba-inc.com>
// Created: 2016/08/18 14:51:16
// Last Modified: 2016/09/13 19:50:08
// Description
#ifndef BASE_DATA_IO_TABLE_SCHEMA_H
#define BASE_DATA_IO_TABLE_SCHEMA_H

#include <stdint.h>
#include <map>
#include <string>
#include <vector>
#include "base/common/uncopyable.h"
#include "base/data_io/data_io_config.h"

namespace pai_algo {
namespace base {

enum ColumnType
{
    kInt,
    kDouble,
    kBool,
    kString,
    kDateTime,
#ifdef SUPPORT_MAP_COLUMN_TYPE
    kMap,
#endif
    kUnknown
};

class TableSchema
{
public:
    TableSchema();
    ~TableSchema();

    int32_t Size() const;
    std::string Name(int32_t index) const;
    ColumnType Type(int32_t index) const;
    
    void Get(int32_t index, std::string* name, ColumnType* type) const;
    void Append(const std::string& name, ColumnType type);
    void Clear();

    std::string SerializeTo() const;
    bool ParseFrom(const std::string& schema);

    bool operator == (const TableSchema& schema) const;
    bool operator != (const TableSchema& schema) const;

#ifdef SUPPORT_MAP_COLUMN_TYPE
    ColumnType MapKeyType(int32_t index) const;
    ColumnType MapValueType(int32_t index) const;
    void AppendMap(const std::string& name, ColumnType key, ColumnType value);
#endif

private:
    std::vector<std::string> mNames;
    std::vector<ColumnType> mTypes;

#ifdef SUPPORT_MAP_COLUMN_TYPE
    std::map<int32_t, ColumnType> mKeyTypes;
    std::map<int32_t, ColumnType> mValueTypes;
#endif
};


} // namespace base
} // namespace pai_algo

#endif // BASE_DATA_IO_TABLE_SCHEMA_H
