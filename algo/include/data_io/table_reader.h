// Copyright (c) 2016, Alibaba Inc.
// All right reserved.
//
// Author: Kai Zhang <dota.zk@alibaba-inc.com>
// Created: 2016/08/18 14:19:24
// Last Modified: 2016/08/19 14:46:44
// Description
#ifndef BASE_DATA_IO_TABLE_READER_H
#define BASE_DATA_IO_TABLE_READER_H

#include <stdint.h>
#include <string>
#include <vector>
#include "base/common/uncopyable.h"
#include "base/data_io/table_record.h"

namespace pai_algo {
namespace base {

class TableSchema;
class TableRecord;

/**
通过表的读接口，可以获取输入表的总行数（样本数）、总列数（特征数）、跳转到指定行开始读等。具体定义如下：
**/
class TableReader : private veil::Uncopyable
{
public:
    virtual ~TableReader() {}

    /*
     * Read as common table by default.
     * A shard table can be read as common table.
     * If assign shardId, read as shard table.
     * If assign shardId, exception will be thrown when it is not a shard table.
     */
    virtual void Open(int32_t shardId = -1) = 0;
    virtual void Close() = 0;

    virtual const TableSchema& GetSchema() const = 0;
    virtual const std::vector<int32_t>& GetSelectedColumns() const = 0;
    virtual const std::vector<int32_t>& GetShardList() const = 0;
    virtual int64_t GetRowCount() const = 0;
    virtual int32_t GetColCount() const = 0;

    virtual void SetBufferRecord(TableRecord* record) = 0;
    virtual void Seek(int64_t recordIndex) = 0;

    /*
     * Return true if not to end.
     */
    virtual bool Read() = 0;
};

} // namespace base
} // namespace pai_algo


#endif // BASE_DATA_IO_TABLE_READER_H
