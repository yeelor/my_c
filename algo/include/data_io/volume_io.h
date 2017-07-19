// Copyright (c) 2016, Alibaba Inc.
// All right reserved.
//
// Author: Kai Zhang <dota.zk@alibaba-inc.com>
// Created: 2016/08/22 18:20:10
// Last Modified: 2016/08/23 14:38:28
// Description
#ifndef BASE_DATA_IO_VOLUME_IO_H
#define BASE_DATA_IO_VOLUME_IO_H

#include "base/data_io/data_io_config.h"

#ifdef PAI_SUPPORT_VOLUME_IO

#include "algo/include/volume/file_reader.h"
#include "algo/include/volume/file_writer.h"
#include "algo/include/volume/volume_file_system.h"

namespace pai_algo {
namespace base {

using ::apsara::odps::algo::FileReader;
using ::apsara::odps::algo::FileWriter;
using ::apsara::odps::algo::VolumeFileSystem;

} /* base */
} /* pai_algo */

#endif

#endif // BASE_DATA_IO_VOLUME_IO_H
