// Copyright (c) 2016, Alibaba Inc.
// All right reserved.
//
// Author: Kai Zhang <dota.zk@alibaba-inc.com>
// Created: 2016/08/18 15:40:49
// Last Modified: 2016/08/19 14:17:26
// Description
#ifndef BASE_DATA_IO_TABLE_WRITER_H
#define BASE_DATA_IO_TABLE_WRITER_H

#include <stdint.h>
#include <string>
#include "base/common/uncopyable.h"

namespace pai_algo {
namespace base {

class TableSchema;
class TableRecord;

class TableWriter : private veil::Uncopyable
{
public:
    virtual ~TableWriter() {}

    /*
     * When write a common table, rankId means 'sequenceId'.
     * And multi instances may write a table in parallel.
     * It is ordered by 'sequenceId' when read a table.
     *
     * When write a shard table, rankId means 'shardId'.
     * And only one instance can write a given shard.
     */
    virtual void Open(int32_t rankId) = 0;
    virtual void Close() = 0;

    virtual void SetBufferRecord(TableRecord* record) = 0;
    virtual void Write() = 0;

    virtual const TableSchema& GetSchema() const = 0;
};

} // namespace base
} // namespace pai_algo


#endif // BASE_DATA_IO_TABLE_WRITER_H

