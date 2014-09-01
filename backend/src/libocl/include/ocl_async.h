#ifndef __OCL_ASYNC_H__
#define __OCL_ASYNC_H__

#include "ocl_types.h"

#define DEFN(TYPE) \
OVERLOADABLE event_t async_work_group_copy (local TYPE *dst,  const global TYPE *src, \
							 size_t num, event_t event); \
OVERLOADABLE event_t async_work_group_copy (global TYPE *dst,  const local TYPE *src, \
							  size_t num, event_t event); \
OVERLOADABLE event_t async_work_group_strided_copy (local TYPE *dst,  const global TYPE *src, \
								 size_t num, size_t src_stride, event_t event); \
OVERLOADABLE event_t async_work_group_strided_copy (global TYPE *dst,  const local TYPE *src, \
								  size_t num, size_t dst_stride, event_t event); \

#define DEF(TYPE) \
  DEFN(TYPE); DEFN(TYPE##2); DEFN(TYPE##3); DEFN(TYPE##4); DEFN(TYPE##8); DEFN(TYPE##16);
DEF(char)
DEF(uchar)
DEF(short)
DEF(ushort)
DEF(int)
DEF(uint)
DEF(long)
DEF(ulong)
DEF(float)
DEF(double)
#undef DEFN
#undef DEF

void wait_group_events (int num_events, event_t *event_list);

#define DEFN(TYPE) \
OVERLOADABLE void prefetch(const global TYPE *p, size_t num);
#define DEF(TYPE) \
DEFN(TYPE); DEFN(TYPE##2); DEFN(TYPE##3); DEFN(TYPE##4); DEFN(TYPE##8); DEFN(TYPE##16)
DEF(char);
DEF(uchar);
DEF(short);
DEF(ushort);
DEF(int);
DEF(uint);
DEF(long);
DEF(ulong);
DEF(float);
#undef DEFN
#undef DEF

#endif
