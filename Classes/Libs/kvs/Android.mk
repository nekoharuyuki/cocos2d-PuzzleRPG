LOCAL_PATH := $(call my-dir)/leveldb

include $(CLEAR_VARS)
LOCAL_MODULE_FILENAME := libleveldb
LOCAL_MODULE := leveldb_mirror_static
LOCAL_CFLAGS := -O3 -fno-builtin-memcmp -D_REENTRANT -DOS_ANDROID -DLEVELDB_PLATFORM_POSIX -DNDEBUG
LOCAL_CPP_EXTENSION := .cc
LOCAL_C_INCLUDES := $(LOCAL_PATH) \
                    $(LOCAL_PATH)/include \

LOCAL_SRC_FILES := db/builder.cc \
                   db/c.cc \
                   db/db_impl.cc \
                   db/db_iter.cc \
                   db/dbformat.cc \
                   db/filename.cc \
                   db/log_reader.cc \
                   db/log_writer.cc \
                   db/memtable.cc \
                   db/repair.cc \
                   db/table_cache.cc \
                   db/version_edit.cc \
                   db/version_set.cc \
                   db/write_batch.cc \
                   table/block.cc \
                   table/block_builder.cc \
                   table/filter_block.cc \
                   table/format.cc \
                   table/iterator.cc \
                   table/merger.cc \
                   table/table.cc \
                   table/table_builder.cc \
                   table/two_level_iterator.cc \
                   util/arena.cc \
                   util/bloom.cc \
                   util/cache.cc \
                   util/coding.cc \
                   util/comparator.cc \
                   util/crc32c.cc \
                   util/env.cc \
                   util/env_posix.cc \
                   util/filter_policy.cc \
                   util/hash.cc \
                   util/histogram.cc \
                   util/logging.cc \
                   util/options.cc \
                   util/status.cc \
                   port/port_posix.cc \
                   helpers/memenv/memenv.cc \

LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)/include

include $(BUILD_STATIC_LIBRARY)

