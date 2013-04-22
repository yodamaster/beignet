/* 
 * Copyright © 2012 Intel Corporation
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library. If not, see <http://www.gnu.org/licenses/>.
 *
 * Author: Benjamin Segovia <benjamin.segovia@intel.com>
 */

#ifndef __OPENCL_CL_INTEL_H
#define __OPENCL_CL_INTEL_H

#include "CL/cl.h"

#ifdef __cplusplus
extern "C" {
#endif

#define CL_MEM_PINNABLE (1 << 10)

/* Track allocations and report current number of unfreed allocations */
extern CL_API_ENTRY cl_int CL_API_CALL
clReportUnfreedIntel(void);

typedef CL_API_ENTRY cl_int (CL_API_CALL *clReportUnfreedIntel_fn)(void);

/* 1 to 1 mapping of drm_intel_bo_map */
extern CL_API_ENTRY void* CL_API_CALL
clMapBufferIntel(cl_mem, cl_int*);

typedef CL_API_ENTRY void* (CL_API_CALL *clMapBufferIntel_fn)(cl_mem, cl_int*);

/* 1 to 1 mapping of drm_intel_bo_unmap */
extern CL_API_ENTRY cl_int CL_API_CALL
clUnmapBufferIntel(cl_mem);

typedef CL_API_ENTRY cl_int (CL_API_CALL *clUnmapBufferIntel_fn)(cl_mem);

/* 1 to 1 mapping of drm_intel_gem_bo_map_gtt */
extern CL_API_ENTRY void* CL_API_CALL
clMapBufferGTTIntel(cl_mem, cl_int*);

typedef CL_API_ENTRY void* (CL_API_CALL *clMapBufferGTTIntel_fn)(cl_mem, cl_int*);

/* 1 to 1 mapping of drm_intel_gem_bo_unmap_gtt */
extern CL_API_ENTRY cl_int CL_API_CALL
clUnmapBufferGTTIntel(cl_mem);

typedef CL_API_ENTRY cl_int (CL_API_CALL *clUnmapBufferGTTIntel_fn)(cl_mem);

/* Pin /Unpin the buffer in GPU memory (must be root) */
extern CL_API_ENTRY cl_int CL_API_CALL
clPinBufferIntel(cl_mem);
extern CL_API_ENTRY cl_int CL_API_CALL
clUnpinBufferIntel(cl_mem);

typedef CL_API_ENTRY cl_int (CL_API_CALL *clPinBufferIntel_fn)(cl_mem);
typedef CL_API_ENTRY cl_int (CL_API_CALL *clUnpinBufferIntel_fn)(cl_mem);

/* Get the generation of the Gen device (used to load the proper binary) */
extern CL_API_ENTRY cl_int CL_API_CALL
clGetGenVersionIntel(cl_device_id device, cl_int *ver);

typedef CL_API_ENTRY cl_int (CL_API_CALL *clGetGenVersionIntel_fn)(
                             cl_device_id device,
                             cl_int *ver);

/* Create a program from a LLVM source file */
extern CL_API_ENTRY cl_program CL_API_CALL
clCreateProgramWithLLVMIntel(cl_context              /* context */,
                             cl_uint                 /* num_devices */,
                             const cl_device_id *    /* device_list */,
                             const char *            /* file */,
                             cl_int *                /* errcode_ret */);

typedef CL_API_ENTRY cl_program (CL_API_CALL *clCreateProgramWithLLVMIntel_fn)(
                                 cl_context              /* context */,
                                 cl_uint                 /* num_devices */,
                                 const cl_device_id *    /* device_list */,
                                 const char *            /* file */,
                                 cl_int *                /* errcode_ret */);

#ifdef __cplusplus
}
#endif

#endif /* __OPENCL_CL_INTEL_H */

