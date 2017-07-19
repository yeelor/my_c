// Copyright (c) 2016, Alibaba Inc.
// All right reserved.
//
// Author: Kai Zhang <dota.zk@alibaba-inc.com>
// Created: 2016/08/18 14:49:06
// Last Modified: 2016/08/19 14:09:30
// Description
#ifndef BASE_DATA_IO_TABLE_RECORD_H
#define BASE_DATA_IO_TABLE_RECORD_H

#include <stdint.h>
#include <iostream>
#include "base/common/uncopyable.h"

namespace pai_algo {
namespace base {

class TableSchema;
class TableRecordUtil;

class TableRecord : private veil::Uncopyable
{
public:
    TableRecord();
    explicit TableRecord(const TableSchema& schema);
    ~TableRecord();

    const TableSchema& GetSchema() const;
    void SetSchema(const TableSchema& schema);

    /*
     * When column type is primitive, void* means type* and len is type bytes.
     * When column type is string, void* means char* and len is string length.
     * When column type is map, void* means MapColumn* and len is map size.
     */
    void* Get(int32_t index, int32_t* len);
    void Set(int32_t index, const void* value, int32_t len);
    void SetNull(int32_t index);

    void Serialize(std::ostream* os) const;
    void Deserialize(std::istream* is);
    void Copy(const TableRecord& from);

private:
    friend class TableRecordUtil;
    class TableRecordImpl;
    TableRecordImpl* mPtr;
};

} // namespace base
} // namespace pai_algo

#endif // BASE_DATA_IO_TABLE_RECORD_H
