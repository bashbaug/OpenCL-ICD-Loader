/*
 * Copyright (c) 2016-2019 The Khronos Group Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * OpenCL is a trademark of Apple Inc. used under license by Khronos.
 */

#include "recorder.h"

///////////////////////////////////////////////////////////////////////////////

struct clGetPlatformIDs_args g_clGetPlatformIDs;

CL_API_ENTRY cl_int CL_API_CALL recclGetPlatformIDs(
    cl_uint num_entries,
    cl_platform_id* platforms,
    cl_uint* num_platforms)
{
    g_clGetPlatformIDs.num_entries = num_entries;
    g_clGetPlatformIDs.platforms = platforms;
    g_clGetPlatformIDs.num_platforms = num_platforms;
    return (cl_int)0;
}

///////////////////////////////////////////////////////////////////////////////

struct clGetPlatformInfo_args g_clGetPlatformInfo;

CL_API_ENTRY cl_int CL_API_CALL recclGetPlatformInfo(
    cl_platform_id platform,
    cl_platform_info param_name,
    size_t param_value_size,
    void* param_value,
    size_t* param_value_size_ret)
{
    g_clGetPlatformInfo.platform = platform;
    g_clGetPlatformInfo.param_name = param_name;
    g_clGetPlatformInfo.param_value_size = param_value_size;
    g_clGetPlatformInfo.param_value = param_value;
    g_clGetPlatformInfo.param_value_size_ret = param_value_size_ret;
    return (cl_int)0;
}

///////////////////////////////////////////////////////////////////////////////

struct clGetDeviceIDs_args g_clGetDeviceIDs;

CL_API_ENTRY cl_int CL_API_CALL recclGetDeviceIDs(
    cl_platform_id platform,
    cl_device_type device_type,
    cl_uint num_entries,
    cl_device_id* devices,
    cl_uint* num_devices)
{
    g_clGetDeviceIDs.platform = platform;
    g_clGetDeviceIDs.device_type = device_type;
    g_clGetDeviceIDs.num_entries = num_entries;
    g_clGetDeviceIDs.devices = devices;
    g_clGetDeviceIDs.num_devices = num_devices;
    return (cl_int)0;
}

///////////////////////////////////////////////////////////////////////////////

struct clGetDeviceInfo_args g_clGetDeviceInfo;

CL_API_ENTRY cl_int CL_API_CALL recclGetDeviceInfo(
    cl_device_id device,
    cl_device_info param_name,
    size_t param_value_size,
    void* param_value,
    size_t* param_value_size_ret)
{
    g_clGetDeviceInfo.device = device;
    g_clGetDeviceInfo.param_name = param_name;
    g_clGetDeviceInfo.param_value_size = param_value_size;
    g_clGetDeviceInfo.param_value = param_value;
    g_clGetDeviceInfo.param_value_size_ret = param_value_size_ret;
    return (cl_int)0;
}

///////////////////////////////////////////////////////////////////////////////

struct clCreateContext_args g_clCreateContext;

CL_API_ENTRY cl_context CL_API_CALL recclCreateContext(
    const cl_context_properties* properties,
    cl_uint num_devices,
    const cl_device_id* devices,
    void (CL_CALLBACK* pfn_notify)(const char*, const void*, size_t, void*),
    void* user_data,
    cl_int* errcode_ret)
{
    g_clCreateContext.properties = properties;
    g_clCreateContext.num_devices = num_devices;
    g_clCreateContext.devices = devices;
    g_clCreateContext.pfn_notify = pfn_notify;
    g_clCreateContext.user_data = user_data;
    g_clCreateContext.errcode_ret = errcode_ret;
    return g_Context;
}

///////////////////////////////////////////////////////////////////////////////

struct clCreateContextFromType_args g_clCreateContextFromType;

CL_API_ENTRY cl_context CL_API_CALL recclCreateContextFromType(
    const cl_context_properties* properties,
    cl_device_type device_type,
    void (CL_CALLBACK* pfn_notify)(const char*, const void*, size_t, void*),
    void* user_data,
    cl_int* errcode_ret)
{
    g_clCreateContextFromType.properties = properties;
    g_clCreateContextFromType.device_type = device_type;
    g_clCreateContextFromType.pfn_notify = pfn_notify;
    g_clCreateContextFromType.user_data = user_data;
    g_clCreateContextFromType.errcode_ret = errcode_ret;
    return g_Context;
}

///////////////////////////////////////////////////////////////////////////////

struct clRetainContext_args g_clRetainContext;

CL_API_ENTRY cl_int CL_API_CALL recclRetainContext(
    cl_context context)
{
    g_clRetainContext.context = context;
    return (cl_int)0;
}

///////////////////////////////////////////////////////////////////////////////

struct clReleaseContext_args g_clReleaseContext;

CL_API_ENTRY cl_int CL_API_CALL recclReleaseContext(
    cl_context context)
{
    g_clReleaseContext.context = context;
    return (cl_int)0;
}

///////////////////////////////////////////////////////////////////////////////

struct clGetContextInfo_args g_clGetContextInfo;

CL_API_ENTRY cl_int CL_API_CALL recclGetContextInfo(
    cl_context context,
    cl_context_info param_name,
    size_t param_value_size,
    void* param_value,
    size_t* param_value_size_ret)
{
    g_clGetContextInfo.context = context;
    g_clGetContextInfo.param_name = param_name;
    g_clGetContextInfo.param_value_size = param_value_size;
    g_clGetContextInfo.param_value = param_value;
    g_clGetContextInfo.param_value_size_ret = param_value_size_ret;
    return (cl_int)0;
}

///////////////////////////////////////////////////////////////////////////////

struct clRetainCommandQueue_args g_clRetainCommandQueue;

CL_API_ENTRY cl_int CL_API_CALL recclRetainCommandQueue(
    cl_command_queue command_queue)
{
    g_clRetainCommandQueue.command_queue = command_queue;
    return (cl_int)0;
}

///////////////////////////////////////////////////////////////////////////////

struct clReleaseCommandQueue_args g_clReleaseCommandQueue;

CL_API_ENTRY cl_int CL_API_CALL recclReleaseCommandQueue(
    cl_command_queue command_queue)
{
    g_clReleaseCommandQueue.command_queue = command_queue;
    return (cl_int)0;
}

///////////////////////////////////////////////////////////////////////////////

struct clGetCommandQueueInfo_args g_clGetCommandQueueInfo;

CL_API_ENTRY cl_int CL_API_CALL recclGetCommandQueueInfo(
    cl_command_queue command_queue,
    cl_command_queue_info param_name,
    size_t param_value_size,
    void* param_value,
    size_t* param_value_size_ret)
{
    g_clGetCommandQueueInfo.command_queue = command_queue;
    g_clGetCommandQueueInfo.param_name = param_name;
    g_clGetCommandQueueInfo.param_value_size = param_value_size;
    g_clGetCommandQueueInfo.param_value = param_value;
    g_clGetCommandQueueInfo.param_value_size_ret = param_value_size_ret;
    return (cl_int)0;
}

///////////////////////////////////////////////////////////////////////////////

struct clCreateBuffer_args g_clCreateBuffer;

CL_API_ENTRY cl_mem CL_API_CALL recclCreateBuffer(
    cl_context context,
    cl_mem_flags flags,
    size_t size,
    void* host_ptr,
    cl_int* errcode_ret)
{
    g_clCreateBuffer.context = context;
    g_clCreateBuffer.flags = flags;
    g_clCreateBuffer.size = size;
    g_clCreateBuffer.host_ptr = host_ptr;
    g_clCreateBuffer.errcode_ret = errcode_ret;
    return g_Mem;
}

///////////////////////////////////////////////////////////////////////////////

struct clRetainMemObject_args g_clRetainMemObject;

CL_API_ENTRY cl_int CL_API_CALL recclRetainMemObject(
    cl_mem memobj)
{
    g_clRetainMemObject.memobj = memobj;
    return (cl_int)0;
}

///////////////////////////////////////////////////////////////////////////////

struct clReleaseMemObject_args g_clReleaseMemObject;

CL_API_ENTRY cl_int CL_API_CALL recclReleaseMemObject(
    cl_mem memobj)
{
    g_clReleaseMemObject.memobj = memobj;
    return (cl_int)0;
}

///////////////////////////////////////////////////////////////////////////////

struct clGetSupportedImageFormats_args g_clGetSupportedImageFormats;

CL_API_ENTRY cl_int CL_API_CALL recclGetSupportedImageFormats(
    cl_context context,
    cl_mem_flags flags,
    cl_mem_object_type image_type,
    cl_uint num_entries,
    cl_image_format* image_formats,
    cl_uint* num_image_formats)
{
    g_clGetSupportedImageFormats.context = context;
    g_clGetSupportedImageFormats.flags = flags;
    g_clGetSupportedImageFormats.image_type = image_type;
    g_clGetSupportedImageFormats.num_entries = num_entries;
    g_clGetSupportedImageFormats.image_formats = image_formats;
    g_clGetSupportedImageFormats.num_image_formats = num_image_formats;
    return (cl_int)0;
}

///////////////////////////////////////////////////////////////////////////////

struct clGetMemObjectInfo_args g_clGetMemObjectInfo;

CL_API_ENTRY cl_int CL_API_CALL recclGetMemObjectInfo(
    cl_mem memobj,
    cl_mem_info param_name,
    size_t param_value_size,
    void* param_value,
    size_t* param_value_size_ret)
{
    g_clGetMemObjectInfo.memobj = memobj;
    g_clGetMemObjectInfo.param_name = param_name;
    g_clGetMemObjectInfo.param_value_size = param_value_size;
    g_clGetMemObjectInfo.param_value = param_value;
    g_clGetMemObjectInfo.param_value_size_ret = param_value_size_ret;
    return (cl_int)0;
}

///////////////////////////////////////////////////////////////////////////////

struct clGetImageInfo_args g_clGetImageInfo;

CL_API_ENTRY cl_int CL_API_CALL recclGetImageInfo(
    cl_mem image,
    cl_image_info param_name,
    size_t param_value_size,
    void* param_value,
    size_t* param_value_size_ret)
{
    g_clGetImageInfo.image = image;
    g_clGetImageInfo.param_name = param_name;
    g_clGetImageInfo.param_value_size = param_value_size;
    g_clGetImageInfo.param_value = param_value;
    g_clGetImageInfo.param_value_size_ret = param_value_size_ret;
    return (cl_int)0;
}

///////////////////////////////////////////////////////////////////////////////

struct clRetainSampler_args g_clRetainSampler;

CL_API_ENTRY cl_int CL_API_CALL recclRetainSampler(
    cl_sampler sampler)
{
    g_clRetainSampler.sampler = sampler;
    return (cl_int)0;
}

///////////////////////////////////////////////////////////////////////////////

struct clReleaseSampler_args g_clReleaseSampler;

CL_API_ENTRY cl_int CL_API_CALL recclReleaseSampler(
    cl_sampler sampler)
{
    g_clReleaseSampler.sampler = sampler;
    return (cl_int)0;
}

///////////////////////////////////////////////////////////////////////////////

struct clGetSamplerInfo_args g_clGetSamplerInfo;

CL_API_ENTRY cl_int CL_API_CALL recclGetSamplerInfo(
    cl_sampler sampler,
    cl_sampler_info param_name,
    size_t param_value_size,
    void* param_value,
    size_t* param_value_size_ret)
{
    g_clGetSamplerInfo.sampler = sampler;
    g_clGetSamplerInfo.param_name = param_name;
    g_clGetSamplerInfo.param_value_size = param_value_size;
    g_clGetSamplerInfo.param_value = param_value;
    g_clGetSamplerInfo.param_value_size_ret = param_value_size_ret;
    return (cl_int)0;
}

///////////////////////////////////////////////////////////////////////////////

struct clCreateProgramWithSource_args g_clCreateProgramWithSource;

CL_API_ENTRY cl_program CL_API_CALL recclCreateProgramWithSource(
    cl_context context,
    cl_uint count,
    const char** strings,
    const size_t* lengths,
    cl_int* errcode_ret)
{
    g_clCreateProgramWithSource.context = context;
    g_clCreateProgramWithSource.count = count;
    g_clCreateProgramWithSource.strings = strings;
    g_clCreateProgramWithSource.lengths = lengths;
    g_clCreateProgramWithSource.errcode_ret = errcode_ret;
    return g_Program;
}

///////////////////////////////////////////////////////////////////////////////

struct clCreateProgramWithBinary_args g_clCreateProgramWithBinary;

CL_API_ENTRY cl_program CL_API_CALL recclCreateProgramWithBinary(
    cl_context context,
    cl_uint num_devices,
    const cl_device_id* device_list,
    const size_t* lengths,
    const unsigned char** binaries,
    cl_int* binary_status,
    cl_int* errcode_ret)
{
    g_clCreateProgramWithBinary.context = context;
    g_clCreateProgramWithBinary.num_devices = num_devices;
    g_clCreateProgramWithBinary.device_list = device_list;
    g_clCreateProgramWithBinary.lengths = lengths;
    g_clCreateProgramWithBinary.binaries = binaries;
    g_clCreateProgramWithBinary.binary_status = binary_status;
    g_clCreateProgramWithBinary.errcode_ret = errcode_ret;
    return g_Program;
}

///////////////////////////////////////////////////////////////////////////////

struct clRetainProgram_args g_clRetainProgram;

CL_API_ENTRY cl_int CL_API_CALL recclRetainProgram(
    cl_program program)
{
    g_clRetainProgram.program = program;
    return (cl_int)0;
}

///////////////////////////////////////////////////////////////////////////////

struct clReleaseProgram_args g_clReleaseProgram;

CL_API_ENTRY cl_int CL_API_CALL recclReleaseProgram(
    cl_program program)
{
    g_clReleaseProgram.program = program;
    return (cl_int)0;
}

///////////////////////////////////////////////////////////////////////////////

struct clBuildProgram_args g_clBuildProgram;

CL_API_ENTRY cl_int CL_API_CALL recclBuildProgram(
    cl_program program,
    cl_uint num_devices,
    const cl_device_id* device_list,
    const char* options,
    void (CL_CALLBACK* pfn_notify)(cl_program program, void* user_data),
    void* user_data)
{
    g_clBuildProgram.program = program;
    g_clBuildProgram.num_devices = num_devices;
    g_clBuildProgram.device_list = device_list;
    g_clBuildProgram.options = options;
    g_clBuildProgram.pfn_notify = pfn_notify;
    g_clBuildProgram.user_data = user_data;
    return (cl_int)0;
}

///////////////////////////////////////////////////////////////////////////////

struct clGetProgramInfo_args g_clGetProgramInfo;

CL_API_ENTRY cl_int CL_API_CALL recclGetProgramInfo(
    cl_program program,
    cl_program_info param_name,
    size_t param_value_size,
    void* param_value,
    size_t* param_value_size_ret)
{
    g_clGetProgramInfo.program = program;
    g_clGetProgramInfo.param_name = param_name;
    g_clGetProgramInfo.param_value_size = param_value_size;
    g_clGetProgramInfo.param_value = param_value;
    g_clGetProgramInfo.param_value_size_ret = param_value_size_ret;
    return (cl_int)0;
}

///////////////////////////////////////////////////////////////////////////////

struct clGetProgramBuildInfo_args g_clGetProgramBuildInfo;

CL_API_ENTRY cl_int CL_API_CALL recclGetProgramBuildInfo(
    cl_program program,
    cl_device_id device,
    cl_program_build_info param_name,
    size_t param_value_size,
    void* param_value,
    size_t* param_value_size_ret)
{
    g_clGetProgramBuildInfo.program = program;
    g_clGetProgramBuildInfo.device = device;
    g_clGetProgramBuildInfo.param_name = param_name;
    g_clGetProgramBuildInfo.param_value_size = param_value_size;
    g_clGetProgramBuildInfo.param_value = param_value;
    g_clGetProgramBuildInfo.param_value_size_ret = param_value_size_ret;
    return (cl_int)0;
}

///////////////////////////////////////////////////////////////////////////////

struct clCreateKernel_args g_clCreateKernel;

CL_API_ENTRY cl_kernel CL_API_CALL recclCreateKernel(
    cl_program program,
    const char* kernel_name,
    cl_int* errcode_ret)
{
    g_clCreateKernel.program = program;
    g_clCreateKernel.kernel_name = kernel_name;
    g_clCreateKernel.errcode_ret = errcode_ret;
    return (cl_kernel)0;
}

///////////////////////////////////////////////////////////////////////////////

struct clCreateKernelsInProgram_args g_clCreateKernelsInProgram;

CL_API_ENTRY cl_int CL_API_CALL recclCreateKernelsInProgram(
    cl_program program,
    cl_uint num_kernels,
    cl_kernel* kernels,
    cl_uint* num_kernels_ret)
{
    g_clCreateKernelsInProgram.program = program;
    g_clCreateKernelsInProgram.num_kernels = num_kernels;
    g_clCreateKernelsInProgram.kernels = kernels;
    g_clCreateKernelsInProgram.num_kernels_ret = num_kernels_ret;
    return (cl_int)0;
}

///////////////////////////////////////////////////////////////////////////////

struct clRetainKernel_args g_clRetainKernel;

CL_API_ENTRY cl_int CL_API_CALL recclRetainKernel(
    cl_kernel kernel)
{
    g_clRetainKernel.kernel = kernel;
    return (cl_int)0;
}

///////////////////////////////////////////////////////////////////////////////

struct clReleaseKernel_args g_clReleaseKernel;

CL_API_ENTRY cl_int CL_API_CALL recclReleaseKernel(
    cl_kernel kernel)
{
    g_clReleaseKernel.kernel = kernel;
    return (cl_int)0;
}

///////////////////////////////////////////////////////////////////////////////

struct clSetKernelArg_args g_clSetKernelArg;

CL_API_ENTRY cl_int CL_API_CALL recclSetKernelArg(
    cl_kernel kernel,
    cl_uint arg_index,
    size_t arg_size,
    const void* arg_value)
{
    g_clSetKernelArg.kernel = kernel;
    g_clSetKernelArg.arg_index = arg_index;
    g_clSetKernelArg.arg_size = arg_size;
    g_clSetKernelArg.arg_value = arg_value;
    return (cl_int)0;
}

///////////////////////////////////////////////////////////////////////////////

struct clGetKernelInfo_args g_clGetKernelInfo;

CL_API_ENTRY cl_int CL_API_CALL recclGetKernelInfo(
    cl_kernel kernel,
    cl_kernel_info param_name,
    size_t param_value_size,
    void* param_value,
    size_t* param_value_size_ret)
{
    g_clGetKernelInfo.kernel = kernel;
    g_clGetKernelInfo.param_name = param_name;
    g_clGetKernelInfo.param_value_size = param_value_size;
    g_clGetKernelInfo.param_value = param_value;
    g_clGetKernelInfo.param_value_size_ret = param_value_size_ret;
    return (cl_int)0;
}

///////////////////////////////////////////////////////////////////////////////

struct clGetKernelWorkGroupInfo_args g_clGetKernelWorkGroupInfo;

CL_API_ENTRY cl_int CL_API_CALL recclGetKernelWorkGroupInfo(
    cl_kernel kernel,
    cl_device_id device,
    cl_kernel_work_group_info param_name,
    size_t param_value_size,
    void* param_value,
    size_t* param_value_size_ret)
{
    g_clGetKernelWorkGroupInfo.kernel = kernel;
    g_clGetKernelWorkGroupInfo.device = device;
    g_clGetKernelWorkGroupInfo.param_name = param_name;
    g_clGetKernelWorkGroupInfo.param_value_size = param_value_size;
    g_clGetKernelWorkGroupInfo.param_value = param_value;
    g_clGetKernelWorkGroupInfo.param_value_size_ret = param_value_size_ret;
    return (cl_int)0;
}

///////////////////////////////////////////////////////////////////////////////

struct clWaitForEvents_args g_clWaitForEvents;

CL_API_ENTRY cl_int CL_API_CALL recclWaitForEvents(
    cl_uint num_events,
    const cl_event* event_list)
{
    g_clWaitForEvents.num_events = num_events;
    g_clWaitForEvents.event_list = event_list;
    return (cl_int)0;
}

///////////////////////////////////////////////////////////////////////////////

struct clGetEventInfo_args g_clGetEventInfo;

CL_API_ENTRY cl_int CL_API_CALL recclGetEventInfo(
    cl_event event,
    cl_event_info param_name,
    size_t param_value_size,
    void* param_value,
    size_t* param_value_size_ret)
{
    g_clGetEventInfo.event = event;
    g_clGetEventInfo.param_name = param_name;
    g_clGetEventInfo.param_value_size = param_value_size;
    g_clGetEventInfo.param_value = param_value;
    g_clGetEventInfo.param_value_size_ret = param_value_size_ret;
    return (cl_int)0;
}

///////////////////////////////////////////////////////////////////////////////

struct clRetainEvent_args g_clRetainEvent;

CL_API_ENTRY cl_int CL_API_CALL recclRetainEvent(
    cl_event event)
{
    g_clRetainEvent.event = event;
    return (cl_int)0;
}

///////////////////////////////////////////////////////////////////////////////

struct clReleaseEvent_args g_clReleaseEvent;

CL_API_ENTRY cl_int CL_API_CALL recclReleaseEvent(
    cl_event event)
{
    g_clReleaseEvent.event = event;
    return (cl_int)0;
}

///////////////////////////////////////////////////////////////////////////////

struct clGetEventProfilingInfo_args g_clGetEventProfilingInfo;

CL_API_ENTRY cl_int CL_API_CALL recclGetEventProfilingInfo(
    cl_event event,
    cl_profiling_info param_name,
    size_t param_value_size,
    void* param_value,
    size_t* param_value_size_ret)
{
    g_clGetEventProfilingInfo.event = event;
    g_clGetEventProfilingInfo.param_name = param_name;
    g_clGetEventProfilingInfo.param_value_size = param_value_size;
    g_clGetEventProfilingInfo.param_value = param_value;
    g_clGetEventProfilingInfo.param_value_size_ret = param_value_size_ret;
    return (cl_int)0;
}

///////////////////////////////////////////////////////////////////////////////

struct clFlush_args g_clFlush;

CL_API_ENTRY cl_int CL_API_CALL recclFlush(
    cl_command_queue command_queue)
{
    g_clFlush.command_queue = command_queue;
    return (cl_int)0;
}

///////////////////////////////////////////////////////////////////////////////

struct clFinish_args g_clFinish;

CL_API_ENTRY cl_int CL_API_CALL recclFinish(
    cl_command_queue command_queue)
{
    g_clFinish.command_queue = command_queue;
    return (cl_int)0;
}

///////////////////////////////////////////////////////////////////////////////

struct clEnqueueReadBuffer_args g_clEnqueueReadBuffer;

CL_API_ENTRY cl_int CL_API_CALL recclEnqueueReadBuffer(
    cl_command_queue command_queue,
    cl_mem buffer,
    cl_bool blocking_read,
    size_t offset,
    size_t size,
    void* ptr,
    cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list,
    cl_event* event)
{
    g_clEnqueueReadBuffer.command_queue = command_queue;
    g_clEnqueueReadBuffer.buffer = buffer;
    g_clEnqueueReadBuffer.blocking_read = blocking_read;
    g_clEnqueueReadBuffer.offset = offset;
    g_clEnqueueReadBuffer.size = size;
    g_clEnqueueReadBuffer.ptr = ptr;
    g_clEnqueueReadBuffer.num_events_in_wait_list = num_events_in_wait_list;
    g_clEnqueueReadBuffer.event_wait_list = event_wait_list;
    g_clEnqueueReadBuffer.event = event;
    return (cl_int)0;
}

///////////////////////////////////////////////////////////////////////////////

struct clEnqueueWriteBuffer_args g_clEnqueueWriteBuffer;

CL_API_ENTRY cl_int CL_API_CALL recclEnqueueWriteBuffer(
    cl_command_queue command_queue,
    cl_mem buffer,
    cl_bool blocking_write,
    size_t offset,
    size_t size,
    const void* ptr,
    cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list,
    cl_event* event)
{
    g_clEnqueueWriteBuffer.command_queue = command_queue;
    g_clEnqueueWriteBuffer.buffer = buffer;
    g_clEnqueueWriteBuffer.blocking_write = blocking_write;
    g_clEnqueueWriteBuffer.offset = offset;
    g_clEnqueueWriteBuffer.size = size;
    g_clEnqueueWriteBuffer.ptr = ptr;
    g_clEnqueueWriteBuffer.num_events_in_wait_list = num_events_in_wait_list;
    g_clEnqueueWriteBuffer.event_wait_list = event_wait_list;
    g_clEnqueueWriteBuffer.event = event;
    return (cl_int)0;
}

///////////////////////////////////////////////////////////////////////////////

struct clEnqueueCopyBuffer_args g_clEnqueueCopyBuffer;

CL_API_ENTRY cl_int CL_API_CALL recclEnqueueCopyBuffer(
    cl_command_queue command_queue,
    cl_mem src_buffer,
    cl_mem dst_buffer,
    size_t src_offset,
    size_t dst_offset,
    size_t size,
    cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list,
    cl_event* event)
{
    g_clEnqueueCopyBuffer.command_queue = command_queue;
    g_clEnqueueCopyBuffer.src_buffer = src_buffer;
    g_clEnqueueCopyBuffer.dst_buffer = dst_buffer;
    g_clEnqueueCopyBuffer.src_offset = src_offset;
    g_clEnqueueCopyBuffer.dst_offset = dst_offset;
    g_clEnqueueCopyBuffer.size = size;
    g_clEnqueueCopyBuffer.num_events_in_wait_list = num_events_in_wait_list;
    g_clEnqueueCopyBuffer.event_wait_list = event_wait_list;
    g_clEnqueueCopyBuffer.event = event;
    return (cl_int)0;
}

///////////////////////////////////////////////////////////////////////////////

struct clEnqueueReadImage_args g_clEnqueueReadImage;

CL_API_ENTRY cl_int CL_API_CALL recclEnqueueReadImage(
    cl_command_queue command_queue,
    cl_mem image,
    cl_bool blocking_read,
    const size_t* origin,
    const size_t* region,
    size_t row_pitch,
    size_t slice_pitch,
    void* ptr,
    cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list,
    cl_event* event)
{
    g_clEnqueueReadImage.command_queue = command_queue;
    g_clEnqueueReadImage.image = image;
    g_clEnqueueReadImage.blocking_read = blocking_read;
    g_clEnqueueReadImage.origin = origin;
    g_clEnqueueReadImage.region = region;
    g_clEnqueueReadImage.row_pitch = row_pitch;
    g_clEnqueueReadImage.slice_pitch = slice_pitch;
    g_clEnqueueReadImage.ptr = ptr;
    g_clEnqueueReadImage.num_events_in_wait_list = num_events_in_wait_list;
    g_clEnqueueReadImage.event_wait_list = event_wait_list;
    g_clEnqueueReadImage.event = event;
    return (cl_int)0;
}

///////////////////////////////////////////////////////////////////////////////

struct clEnqueueWriteImage_args g_clEnqueueWriteImage;

CL_API_ENTRY cl_int CL_API_CALL recclEnqueueWriteImage(
    cl_command_queue command_queue,
    cl_mem image,
    cl_bool blocking_write,
    const size_t* origin,
    const size_t* region,
    size_t input_row_pitch,
    size_t input_slice_pitch,
    const void* ptr,
    cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list,
    cl_event* event)
{
    g_clEnqueueWriteImage.command_queue = command_queue;
    g_clEnqueueWriteImage.image = image;
    g_clEnqueueWriteImage.blocking_write = blocking_write;
    g_clEnqueueWriteImage.origin = origin;
    g_clEnqueueWriteImage.region = region;
    g_clEnqueueWriteImage.input_row_pitch = input_row_pitch;
    g_clEnqueueWriteImage.input_slice_pitch = input_slice_pitch;
    g_clEnqueueWriteImage.ptr = ptr;
    g_clEnqueueWriteImage.num_events_in_wait_list = num_events_in_wait_list;
    g_clEnqueueWriteImage.event_wait_list = event_wait_list;
    g_clEnqueueWriteImage.event = event;
    return (cl_int)0;
}

///////////////////////////////////////////////////////////////////////////////

struct clEnqueueCopyImage_args g_clEnqueueCopyImage;

CL_API_ENTRY cl_int CL_API_CALL recclEnqueueCopyImage(
    cl_command_queue command_queue,
    cl_mem src_image,
    cl_mem dst_image,
    const size_t* src_origin,
    const size_t* dst_origin,
    const size_t* region,
    cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list,
    cl_event* event)
{
    g_clEnqueueCopyImage.command_queue = command_queue;
    g_clEnqueueCopyImage.src_image = src_image;
    g_clEnqueueCopyImage.dst_image = dst_image;
    g_clEnqueueCopyImage.src_origin = src_origin;
    g_clEnqueueCopyImage.dst_origin = dst_origin;
    g_clEnqueueCopyImage.region = region;
    g_clEnqueueCopyImage.num_events_in_wait_list = num_events_in_wait_list;
    g_clEnqueueCopyImage.event_wait_list = event_wait_list;
    g_clEnqueueCopyImage.event = event;
    return (cl_int)0;
}

///////////////////////////////////////////////////////////////////////////////

struct clEnqueueCopyImageToBuffer_args g_clEnqueueCopyImageToBuffer;

CL_API_ENTRY cl_int CL_API_CALL recclEnqueueCopyImageToBuffer(
    cl_command_queue command_queue,
    cl_mem src_image,
    cl_mem dst_buffer,
    const size_t* src_origin,
    const size_t* region,
    size_t dst_offset,
    cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list,
    cl_event* event)
{
    g_clEnqueueCopyImageToBuffer.command_queue = command_queue;
    g_clEnqueueCopyImageToBuffer.src_image = src_image;
    g_clEnqueueCopyImageToBuffer.dst_buffer = dst_buffer;
    g_clEnqueueCopyImageToBuffer.src_origin = src_origin;
    g_clEnqueueCopyImageToBuffer.region = region;
    g_clEnqueueCopyImageToBuffer.dst_offset = dst_offset;
    g_clEnqueueCopyImageToBuffer.num_events_in_wait_list = num_events_in_wait_list;
    g_clEnqueueCopyImageToBuffer.event_wait_list = event_wait_list;
    g_clEnqueueCopyImageToBuffer.event = event;
    return (cl_int)0;
}

///////////////////////////////////////////////////////////////////////////////

struct clEnqueueCopyBufferToImage_args g_clEnqueueCopyBufferToImage;

CL_API_ENTRY cl_int CL_API_CALL recclEnqueueCopyBufferToImage(
    cl_command_queue command_queue,
    cl_mem src_buffer,
    cl_mem dst_image,
    size_t src_offset,
    const size_t* dst_origin,
    const size_t* region,
    cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list,
    cl_event* event)
{
    g_clEnqueueCopyBufferToImage.command_queue = command_queue;
    g_clEnqueueCopyBufferToImage.src_buffer = src_buffer;
    g_clEnqueueCopyBufferToImage.dst_image = dst_image;
    g_clEnqueueCopyBufferToImage.src_offset = src_offset;
    g_clEnqueueCopyBufferToImage.dst_origin = dst_origin;
    g_clEnqueueCopyBufferToImage.region = region;
    g_clEnqueueCopyBufferToImage.num_events_in_wait_list = num_events_in_wait_list;
    g_clEnqueueCopyBufferToImage.event_wait_list = event_wait_list;
    g_clEnqueueCopyBufferToImage.event = event;
    return (cl_int)0;
}

///////////////////////////////////////////////////////////////////////////////

struct clEnqueueMapBuffer_args g_clEnqueueMapBuffer;

CL_API_ENTRY void* CL_API_CALL recclEnqueueMapBuffer(
    cl_command_queue command_queue,
    cl_mem buffer,
    cl_bool blocking_map,
    cl_map_flags map_flags,
    size_t offset,
    size_t size,
    cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list,
    cl_event* event,
    cl_int* errcode_ret)
{
    g_clEnqueueMapBuffer.command_queue = command_queue;
    g_clEnqueueMapBuffer.buffer = buffer;
    g_clEnqueueMapBuffer.blocking_map = blocking_map;
    g_clEnqueueMapBuffer.map_flags = map_flags;
    g_clEnqueueMapBuffer.offset = offset;
    g_clEnqueueMapBuffer.size = size;
    g_clEnqueueMapBuffer.num_events_in_wait_list = num_events_in_wait_list;
    g_clEnqueueMapBuffer.event_wait_list = event_wait_list;
    g_clEnqueueMapBuffer.event = event;
    g_clEnqueueMapBuffer.errcode_ret = errcode_ret;
    return (void*)0;
}

///////////////////////////////////////////////////////////////////////////////

struct clEnqueueMapImage_args g_clEnqueueMapImage;

CL_API_ENTRY void* CL_API_CALL recclEnqueueMapImage(
    cl_command_queue command_queue,
    cl_mem image,
    cl_bool blocking_map,
    cl_map_flags map_flags,
    const size_t* origin,
    const size_t* region,
    size_t* image_row_pitch,
    size_t* image_slice_pitch,
    cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list,
    cl_event* event,
    cl_int* errcode_ret)
{
    g_clEnqueueMapImage.command_queue = command_queue;
    g_clEnqueueMapImage.image = image;
    g_clEnqueueMapImage.blocking_map = blocking_map;
    g_clEnqueueMapImage.map_flags = map_flags;
    g_clEnqueueMapImage.origin = origin;
    g_clEnqueueMapImage.region = region;
    g_clEnqueueMapImage.image_row_pitch = image_row_pitch;
    g_clEnqueueMapImage.image_slice_pitch = image_slice_pitch;
    g_clEnqueueMapImage.num_events_in_wait_list = num_events_in_wait_list;
    g_clEnqueueMapImage.event_wait_list = event_wait_list;
    g_clEnqueueMapImage.event = event;
    g_clEnqueueMapImage.errcode_ret = errcode_ret;
    return (void*)0;
}

///////////////////////////////////////////////////////////////////////////////

struct clEnqueueUnmapMemObject_args g_clEnqueueUnmapMemObject;

CL_API_ENTRY cl_int CL_API_CALL recclEnqueueUnmapMemObject(
    cl_command_queue command_queue,
    cl_mem memobj,
    void* mapped_ptr,
    cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list,
    cl_event* event)
{
    g_clEnqueueUnmapMemObject.command_queue = command_queue;
    g_clEnqueueUnmapMemObject.memobj = memobj;
    g_clEnqueueUnmapMemObject.mapped_ptr = mapped_ptr;
    g_clEnqueueUnmapMemObject.num_events_in_wait_list = num_events_in_wait_list;
    g_clEnqueueUnmapMemObject.event_wait_list = event_wait_list;
    g_clEnqueueUnmapMemObject.event = event;
    return (cl_int)0;
}

///////////////////////////////////////////////////////////////////////////////

struct clEnqueueNDRangeKernel_args g_clEnqueueNDRangeKernel;

CL_API_ENTRY cl_int CL_API_CALL recclEnqueueNDRangeKernel(
    cl_command_queue command_queue,
    cl_kernel kernel,
    cl_uint work_dim,
    const size_t* global_work_offset,
    const size_t* global_work_size,
    const size_t* local_work_size,
    cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list,
    cl_event* event)
{
    g_clEnqueueNDRangeKernel.command_queue = command_queue;
    g_clEnqueueNDRangeKernel.kernel = kernel;
    g_clEnqueueNDRangeKernel.work_dim = work_dim;
    g_clEnqueueNDRangeKernel.global_work_offset = global_work_offset;
    g_clEnqueueNDRangeKernel.global_work_size = global_work_size;
    g_clEnqueueNDRangeKernel.local_work_size = local_work_size;
    g_clEnqueueNDRangeKernel.num_events_in_wait_list = num_events_in_wait_list;
    g_clEnqueueNDRangeKernel.event_wait_list = event_wait_list;
    g_clEnqueueNDRangeKernel.event = event;
    return (cl_int)0;
}

///////////////////////////////////////////////////////////////////////////////

struct clEnqueueNativeKernel_args g_clEnqueueNativeKernel;

CL_API_ENTRY cl_int CL_API_CALL recclEnqueueNativeKernel(
    cl_command_queue command_queue,
    void (CL_CALLBACK* user_func)(void*),
    void* args,
    size_t cb_args,
    cl_uint num_mem_objects,
    const cl_mem* mem_list,
    const void** args_mem_loc,
    cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list,
    cl_event* event)
{
    g_clEnqueueNativeKernel.command_queue = command_queue;
    g_clEnqueueNativeKernel.user_func = user_func;
    g_clEnqueueNativeKernel.args = args;
    g_clEnqueueNativeKernel.cb_args = cb_args;
    g_clEnqueueNativeKernel.num_mem_objects = num_mem_objects;
    g_clEnqueueNativeKernel.mem_list = mem_list;
    g_clEnqueueNativeKernel.args_mem_loc = args_mem_loc;
    g_clEnqueueNativeKernel.num_events_in_wait_list = num_events_in_wait_list;
    g_clEnqueueNativeKernel.event_wait_list = event_wait_list;
    g_clEnqueueNativeKernel.event = event;
    return (cl_int)0;
}

///////////////////////////////////////////////////////////////////////////////

struct clSetCommandQueueProperty_args g_clSetCommandQueueProperty;

CL_API_ENTRY cl_int CL_API_CALL recclSetCommandQueueProperty(
    cl_command_queue command_queue,
    cl_command_queue_properties properties,
    cl_bool enable,
    cl_command_queue_properties* old_properties)
{
    g_clSetCommandQueueProperty.command_queue = command_queue;
    g_clSetCommandQueueProperty.properties = properties;
    g_clSetCommandQueueProperty.enable = enable;
    g_clSetCommandQueueProperty.old_properties = old_properties;
    return (cl_int)0;
}

///////////////////////////////////////////////////////////////////////////////

struct clCreateSubBuffer_args g_clCreateSubBuffer;

CL_API_ENTRY cl_mem CL_API_CALL recclCreateSubBuffer(
    cl_mem buffer,
    cl_mem_flags flags,
    cl_buffer_create_type buffer_create_type,
    const void* buffer_create_info,
    cl_int* errcode_ret)
{
    g_clCreateSubBuffer.buffer = buffer;
    g_clCreateSubBuffer.flags = flags;
    g_clCreateSubBuffer.buffer_create_type = buffer_create_type;
    g_clCreateSubBuffer.buffer_create_info = buffer_create_info;
    g_clCreateSubBuffer.errcode_ret = errcode_ret;
    return g_Mem;
}

///////////////////////////////////////////////////////////////////////////////

struct clSetMemObjectDestructorCallback_args g_clSetMemObjectDestructorCallback;

CL_API_ENTRY cl_int CL_API_CALL recclSetMemObjectDestructorCallback(
    cl_mem memobj,
    void (CL_CALLBACK* pfn_notify)(cl_mem memobj, void* user_data),
    void* user_data)
{
    g_clSetMemObjectDestructorCallback.memobj = memobj;
    g_clSetMemObjectDestructorCallback.pfn_notify = pfn_notify;
    g_clSetMemObjectDestructorCallback.user_data = user_data;
    return (cl_int)0;
}

///////////////////////////////////////////////////////////////////////////////

struct clCreateUserEvent_args g_clCreateUserEvent;

CL_API_ENTRY cl_event CL_API_CALL recclCreateUserEvent(
    cl_context context,
    cl_int* errcode_ret)
{
    g_clCreateUserEvent.context = context;
    g_clCreateUserEvent.errcode_ret = errcode_ret;
    return g_Event;
}

///////////////////////////////////////////////////////////////////////////////

struct clSetUserEventStatus_args g_clSetUserEventStatus;

CL_API_ENTRY cl_int CL_API_CALL recclSetUserEventStatus(
    cl_event event,
    cl_int execution_status)
{
    g_clSetUserEventStatus.event = event;
    g_clSetUserEventStatus.execution_status = execution_status;
    return (cl_int)0;
}

///////////////////////////////////////////////////////////////////////////////

struct clSetEventCallback_args g_clSetEventCallback;

CL_API_ENTRY cl_int CL_API_CALL recclSetEventCallback(
    cl_event event,
    cl_int command_exec_callback_type,
    void (CL_CALLBACK* pfn_notify)(cl_event event, cl_int type, void *user_data),
    void* user_data)
{
    g_clSetEventCallback.event = event;
    g_clSetEventCallback.command_exec_callback_type = command_exec_callback_type;
    g_clSetEventCallback.pfn_notify = pfn_notify;
    g_clSetEventCallback.user_data = user_data;
    return (cl_int)0;
}

///////////////////////////////////////////////////////////////////////////////

struct clEnqueueReadBufferRect_args g_clEnqueueReadBufferRect;

CL_API_ENTRY cl_int CL_API_CALL recclEnqueueReadBufferRect(
    cl_command_queue command_queue,
    cl_mem buffer,
    cl_bool blocking_read,
    const size_t* buffer_offset,
    const size_t* host_offset,
    const size_t* region,
    size_t buffer_row_pitch,
    size_t buffer_slice_pitch,
    size_t host_row_pitch,
    size_t host_slice_pitch,
    void* ptr,
    cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list,
    cl_event* event)
{
    g_clEnqueueReadBufferRect.command_queue = command_queue;
    g_clEnqueueReadBufferRect.buffer = buffer;
    g_clEnqueueReadBufferRect.blocking_read = blocking_read;
    g_clEnqueueReadBufferRect.buffer_offset = buffer_offset;
    g_clEnqueueReadBufferRect.host_offset = host_offset;
    g_clEnqueueReadBufferRect.region = region;
    g_clEnqueueReadBufferRect.buffer_row_pitch = buffer_row_pitch;
    g_clEnqueueReadBufferRect.buffer_slice_pitch = buffer_slice_pitch;
    g_clEnqueueReadBufferRect.host_row_pitch = host_row_pitch;
    g_clEnqueueReadBufferRect.host_slice_pitch = host_slice_pitch;
    g_clEnqueueReadBufferRect.ptr = ptr;
    g_clEnqueueReadBufferRect.num_events_in_wait_list = num_events_in_wait_list;
    g_clEnqueueReadBufferRect.event_wait_list = event_wait_list;
    g_clEnqueueReadBufferRect.event = event;
    return (cl_int)0;
}

///////////////////////////////////////////////////////////////////////////////

struct clEnqueueWriteBufferRect_args g_clEnqueueWriteBufferRect;

CL_API_ENTRY cl_int CL_API_CALL recclEnqueueWriteBufferRect(
    cl_command_queue command_queue,
    cl_mem buffer,
    cl_bool blocking_write,
    const size_t* buffer_offset,
    const size_t* host_offset,
    const size_t* region,
    size_t buffer_row_pitch,
    size_t buffer_slice_pitch,
    size_t host_row_pitch,
    size_t host_slice_pitch,
    const void* ptr,
    cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list,
    cl_event* event)
{
    g_clEnqueueWriteBufferRect.command_queue = command_queue;
    g_clEnqueueWriteBufferRect.buffer = buffer;
    g_clEnqueueWriteBufferRect.blocking_write = blocking_write;
    g_clEnqueueWriteBufferRect.buffer_offset = buffer_offset;
    g_clEnqueueWriteBufferRect.host_offset = host_offset;
    g_clEnqueueWriteBufferRect.region = region;
    g_clEnqueueWriteBufferRect.buffer_row_pitch = buffer_row_pitch;
    g_clEnqueueWriteBufferRect.buffer_slice_pitch = buffer_slice_pitch;
    g_clEnqueueWriteBufferRect.host_row_pitch = host_row_pitch;
    g_clEnqueueWriteBufferRect.host_slice_pitch = host_slice_pitch;
    g_clEnqueueWriteBufferRect.ptr = ptr;
    g_clEnqueueWriteBufferRect.num_events_in_wait_list = num_events_in_wait_list;
    g_clEnqueueWriteBufferRect.event_wait_list = event_wait_list;
    g_clEnqueueWriteBufferRect.event = event;
    return (cl_int)0;
}

///////////////////////////////////////////////////////////////////////////////

struct clEnqueueCopyBufferRect_args g_clEnqueueCopyBufferRect;

CL_API_ENTRY cl_int CL_API_CALL recclEnqueueCopyBufferRect(
    cl_command_queue command_queue,
    cl_mem src_buffer,
    cl_mem dst_buffer,
    const size_t* src_origin,
    const size_t* dst_origin,
    const size_t* region,
    size_t src_row_pitch,
    size_t src_slice_pitch,
    size_t dst_row_pitch,
    size_t dst_slice_pitch,
    cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list,
    cl_event* event)
{
    g_clEnqueueCopyBufferRect.command_queue = command_queue;
    g_clEnqueueCopyBufferRect.src_buffer = src_buffer;
    g_clEnqueueCopyBufferRect.dst_buffer = dst_buffer;
    g_clEnqueueCopyBufferRect.src_origin = src_origin;
    g_clEnqueueCopyBufferRect.dst_origin = dst_origin;
    g_clEnqueueCopyBufferRect.region = region;
    g_clEnqueueCopyBufferRect.src_row_pitch = src_row_pitch;
    g_clEnqueueCopyBufferRect.src_slice_pitch = src_slice_pitch;
    g_clEnqueueCopyBufferRect.dst_row_pitch = dst_row_pitch;
    g_clEnqueueCopyBufferRect.dst_slice_pitch = dst_slice_pitch;
    g_clEnqueueCopyBufferRect.num_events_in_wait_list = num_events_in_wait_list;
    g_clEnqueueCopyBufferRect.event_wait_list = event_wait_list;
    g_clEnqueueCopyBufferRect.event = event;
    return (cl_int)0;
}

///////////////////////////////////////////////////////////////////////////////

struct clCreateImage2D_args g_clCreateImage2D;

CL_API_ENTRY cl_mem CL_API_CALL recclCreateImage2D(
    cl_context context,
    cl_mem_flags flags,
    const cl_image_format* image_format,
    size_t image_width,
    size_t image_height,
    size_t image_row_pitch,
    void* host_ptr,
    cl_int* errcode_ret)
{
    g_clCreateImage2D.context = context;
    g_clCreateImage2D.flags = flags;
    g_clCreateImage2D.image_format = image_format;
    g_clCreateImage2D.image_width = image_width;
    g_clCreateImage2D.image_height = image_height;
    g_clCreateImage2D.image_row_pitch = image_row_pitch;
    g_clCreateImage2D.host_ptr = host_ptr;
    g_clCreateImage2D.errcode_ret = errcode_ret;
    return g_Mem;
}

///////////////////////////////////////////////////////////////////////////////

struct clCreateImage3D_args g_clCreateImage3D;

CL_API_ENTRY cl_mem CL_API_CALL recclCreateImage3D(
    cl_context context,
    cl_mem_flags flags,
    const cl_image_format* image_format,
    size_t image_width,
    size_t image_height,
    size_t image_depth,
    size_t image_row_pitch,
    size_t image_slice_pitch,
    void* host_ptr,
    cl_int* errcode_ret)
{
    g_clCreateImage3D.context = context;
    g_clCreateImage3D.flags = flags;
    g_clCreateImage3D.image_format = image_format;
    g_clCreateImage3D.image_width = image_width;
    g_clCreateImage3D.image_height = image_height;
    g_clCreateImage3D.image_depth = image_depth;
    g_clCreateImage3D.image_row_pitch = image_row_pitch;
    g_clCreateImage3D.image_slice_pitch = image_slice_pitch;
    g_clCreateImage3D.host_ptr = host_ptr;
    g_clCreateImage3D.errcode_ret = errcode_ret;
    return g_Mem;
}

///////////////////////////////////////////////////////////////////////////////

struct clEnqueueMarker_args g_clEnqueueMarker;

CL_API_ENTRY cl_int CL_API_CALL recclEnqueueMarker(
    cl_command_queue command_queue,
    cl_event* event)
{
    g_clEnqueueMarker.command_queue = command_queue;
    g_clEnqueueMarker.event = event;
    return (cl_int)0;
}

///////////////////////////////////////////////////////////////////////////////

struct clEnqueueWaitForEvents_args g_clEnqueueWaitForEvents;

CL_API_ENTRY cl_int CL_API_CALL recclEnqueueWaitForEvents(
    cl_command_queue command_queue,
    cl_uint num_events,
    const cl_event* event_list)
{
    g_clEnqueueWaitForEvents.command_queue = command_queue;
    g_clEnqueueWaitForEvents.num_events = num_events;
    g_clEnqueueWaitForEvents.event_list = event_list;
    return (cl_int)0;
}

///////////////////////////////////////////////////////////////////////////////

struct clEnqueueBarrier_args g_clEnqueueBarrier;

CL_API_ENTRY cl_int CL_API_CALL recclEnqueueBarrier(
    cl_command_queue command_queue)
{
    g_clEnqueueBarrier.command_queue = command_queue;
    return (cl_int)0;
}

///////////////////////////////////////////////////////////////////////////////

CL_API_ENTRY cl_int CL_API_CALL recclUnloadCompiler(void)
{
    return (cl_int)0;
}

///////////////////////////////////////////////////////////////////////////////

struct clGetExtensionFunctionAddress_args g_clGetExtensionFunctionAddress;

CL_API_ENTRY void* CL_API_CALL recclGetExtensionFunctionAddress(
    const char* func_name)
{
    g_clGetExtensionFunctionAddress.func_name = func_name;
    return (void*)0;
}

///////////////////////////////////////////////////////////////////////////////

struct clCreateSubDevices_args g_clCreateSubDevices;

CL_API_ENTRY cl_int CL_API_CALL recclCreateSubDevices(
    cl_device_id in_device,
    const cl_device_partition_property* properties,
    cl_uint num_devices,
    cl_device_id* out_devices,
    cl_uint* num_devices_ret)
{
    g_clCreateSubDevices.in_device = in_device;
    g_clCreateSubDevices.properties = properties;
    g_clCreateSubDevices.num_devices = num_devices;
    g_clCreateSubDevices.out_devices = out_devices;
    g_clCreateSubDevices.num_devices_ret = num_devices_ret;
    return (cl_int)0;
}

///////////////////////////////////////////////////////////////////////////////

struct clRetainDevice_args g_clRetainDevice;

CL_API_ENTRY cl_int CL_API_CALL recclRetainDevice(
    cl_device_id device)
{
    g_clRetainDevice.device = device;
    return (cl_int)0;
}

///////////////////////////////////////////////////////////////////////////////

struct clReleaseDevice_args g_clReleaseDevice;

CL_API_ENTRY cl_int CL_API_CALL recclReleaseDevice(
    cl_device_id device)
{
    g_clReleaseDevice.device = device;
    return (cl_int)0;
}

///////////////////////////////////////////////////////////////////////////////

struct clCreateImage_args g_clCreateImage;

CL_API_ENTRY cl_mem CL_API_CALL recclCreateImage(
    cl_context context,
    cl_mem_flags flags,
    const cl_image_format* image_format,
    const cl_image_desc* image_desc,
    void* host_ptr,
    cl_int* errcode_ret)
{
    g_clCreateImage.context = context;
    g_clCreateImage.flags = flags;
    g_clCreateImage.image_format = image_format;
    g_clCreateImage.image_desc = image_desc;
    g_clCreateImage.host_ptr = host_ptr;
    g_clCreateImage.errcode_ret = errcode_ret;
    return g_Mem;
}

///////////////////////////////////////////////////////////////////////////////

struct clCreateProgramWithBuiltInKernels_args g_clCreateProgramWithBuiltInKernels;

CL_API_ENTRY cl_program CL_API_CALL recclCreateProgramWithBuiltInKernels(
    cl_context context,
    cl_uint num_devices,
    const cl_device_id* device_list,
    const char* kernel_names,
    cl_int* errcode_ret)
{
    g_clCreateProgramWithBuiltInKernels.context = context;
    g_clCreateProgramWithBuiltInKernels.num_devices = num_devices;
    g_clCreateProgramWithBuiltInKernels.device_list = device_list;
    g_clCreateProgramWithBuiltInKernels.kernel_names = kernel_names;
    g_clCreateProgramWithBuiltInKernels.errcode_ret = errcode_ret;
    return g_Program;
}

///////////////////////////////////////////////////////////////////////////////

struct clCompileProgram_args g_clCompileProgram;

CL_API_ENTRY cl_int CL_API_CALL recclCompileProgram(
    cl_program program,
    cl_uint num_devices,
    const cl_device_id* device_list,
    const char* options,
    cl_uint num_input_headers,
    const cl_program* input_headers,
    const char** header_include_names,
    void (CL_CALLBACK* pfn_notify)(cl_program program, void* user_data),
    void* user_data)
{
    g_clCompileProgram.program = program;
    g_clCompileProgram.num_devices = num_devices;
    g_clCompileProgram.device_list = device_list;
    g_clCompileProgram.options = options;
    g_clCompileProgram.num_input_headers = num_input_headers;
    g_clCompileProgram.input_headers = input_headers;
    g_clCompileProgram.header_include_names = header_include_names;
    g_clCompileProgram.pfn_notify = pfn_notify;
    g_clCompileProgram.user_data = user_data;
    return (cl_int)0;
}

///////////////////////////////////////////////////////////////////////////////

struct clLinkProgram_args g_clLinkProgram;

CL_API_ENTRY cl_program CL_API_CALL recclLinkProgram(
    cl_context context,
    cl_uint num_devices,
    const cl_device_id* device_list,
    const char* options,
    cl_uint num_input_programs,
    const cl_program* input_programs,
    void (CL_CALLBACK* pfn_notify)(cl_program program, void* user_data),
    void* user_data,
    cl_int* errcode_ret)
{
    g_clLinkProgram.context = context;
    g_clLinkProgram.num_devices = num_devices;
    g_clLinkProgram.device_list = device_list;
    g_clLinkProgram.options = options;
    g_clLinkProgram.num_input_programs = num_input_programs;
    g_clLinkProgram.input_programs = input_programs;
    g_clLinkProgram.pfn_notify = pfn_notify;
    g_clLinkProgram.user_data = user_data;
    g_clLinkProgram.errcode_ret = errcode_ret;
    return g_Program;
}

///////////////////////////////////////////////////////////////////////////////

struct clUnloadPlatformCompiler_args g_clUnloadPlatformCompiler;

CL_API_ENTRY cl_int CL_API_CALL recclUnloadPlatformCompiler(
    cl_platform_id platform)
{
    g_clUnloadPlatformCompiler.platform = platform;
    return (cl_int)0;
}

///////////////////////////////////////////////////////////////////////////////

struct clGetKernelArgInfo_args g_clGetKernelArgInfo;

CL_API_ENTRY cl_int CL_API_CALL recclGetKernelArgInfo(
    cl_kernel kernel,
    cl_uint arg_indx,
    cl_kernel_arg_info param_name,
    size_t param_value_size,
    void* param_value,
    size_t* param_value_size_ret)
{
    g_clGetKernelArgInfo.kernel = kernel;
    g_clGetKernelArgInfo.arg_indx = arg_indx;
    g_clGetKernelArgInfo.param_name = param_name;
    g_clGetKernelArgInfo.param_value_size = param_value_size;
    g_clGetKernelArgInfo.param_value = param_value;
    g_clGetKernelArgInfo.param_value_size_ret = param_value_size_ret;
    return (cl_int)0;
}

///////////////////////////////////////////////////////////////////////////////

struct clEnqueueFillBuffer_args g_clEnqueueFillBuffer;

CL_API_ENTRY cl_int CL_API_CALL recclEnqueueFillBuffer(
    cl_command_queue command_queue,
    cl_mem buffer,
    const void* pattern,
    size_t pattern_size,
    size_t offset,
    size_t size,
    cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list,
    cl_event* event)
{
    g_clEnqueueFillBuffer.command_queue = command_queue;
    g_clEnqueueFillBuffer.buffer = buffer;
    g_clEnqueueFillBuffer.pattern = pattern;
    g_clEnqueueFillBuffer.pattern_size = pattern_size;
    g_clEnqueueFillBuffer.offset = offset;
    g_clEnqueueFillBuffer.size = size;
    g_clEnqueueFillBuffer.num_events_in_wait_list = num_events_in_wait_list;
    g_clEnqueueFillBuffer.event_wait_list = event_wait_list;
    g_clEnqueueFillBuffer.event = event;
    return (cl_int)0;
}

///////////////////////////////////////////////////////////////////////////////

struct clEnqueueFillImage_args g_clEnqueueFillImage;

CL_API_ENTRY cl_int CL_API_CALL recclEnqueueFillImage(
    cl_command_queue command_queue,
    cl_mem image,
    const void* fill_color,
    const size_t* origin,
    const size_t* region,
    cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list,
    cl_event* event)
{
    g_clEnqueueFillImage.command_queue = command_queue;
    g_clEnqueueFillImage.image = image;
    g_clEnqueueFillImage.fill_color = fill_color;
    g_clEnqueueFillImage.origin = origin;
    g_clEnqueueFillImage.region = region;
    g_clEnqueueFillImage.num_events_in_wait_list = num_events_in_wait_list;
    g_clEnqueueFillImage.event_wait_list = event_wait_list;
    g_clEnqueueFillImage.event = event;
    return (cl_int)0;
}

///////////////////////////////////////////////////////////////////////////////

struct clEnqueueMigrateMemObjects_args g_clEnqueueMigrateMemObjects;

CL_API_ENTRY cl_int CL_API_CALL recclEnqueueMigrateMemObjects(
    cl_command_queue command_queue,
    cl_uint num_mem_objects,
    const cl_mem* mem_objects,
    cl_mem_migration_flags flags,
    cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list,
    cl_event* event)
{
    g_clEnqueueMigrateMemObjects.command_queue = command_queue;
    g_clEnqueueMigrateMemObjects.num_mem_objects = num_mem_objects;
    g_clEnqueueMigrateMemObjects.mem_objects = mem_objects;
    g_clEnqueueMigrateMemObjects.flags = flags;
    g_clEnqueueMigrateMemObjects.num_events_in_wait_list = num_events_in_wait_list;
    g_clEnqueueMigrateMemObjects.event_wait_list = event_wait_list;
    g_clEnqueueMigrateMemObjects.event = event;
    return (cl_int)0;
}

///////////////////////////////////////////////////////////////////////////////

struct clEnqueueMarkerWithWaitList_args g_clEnqueueMarkerWithWaitList;

CL_API_ENTRY cl_int CL_API_CALL recclEnqueueMarkerWithWaitList(
    cl_command_queue command_queue,
    cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list,
    cl_event* event)
{
    g_clEnqueueMarkerWithWaitList.command_queue = command_queue;
    g_clEnqueueMarkerWithWaitList.num_events_in_wait_list = num_events_in_wait_list;
    g_clEnqueueMarkerWithWaitList.event_wait_list = event_wait_list;
    g_clEnqueueMarkerWithWaitList.event = event;
    return (cl_int)0;
}

///////////////////////////////////////////////////////////////////////////////

struct clEnqueueBarrierWithWaitList_args g_clEnqueueBarrierWithWaitList;

CL_API_ENTRY cl_int CL_API_CALL recclEnqueueBarrierWithWaitList(
    cl_command_queue command_queue,
    cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list,
    cl_event* event)
{
    g_clEnqueueBarrierWithWaitList.command_queue = command_queue;
    g_clEnqueueBarrierWithWaitList.num_events_in_wait_list = num_events_in_wait_list;
    g_clEnqueueBarrierWithWaitList.event_wait_list = event_wait_list;
    g_clEnqueueBarrierWithWaitList.event = event;
    return (cl_int)0;
}

///////////////////////////////////////////////////////////////////////////////

struct clGetExtensionFunctionAddressForPlatform_args g_clGetExtensionFunctionAddressForPlatform;

CL_API_ENTRY void* CL_API_CALL recclGetExtensionFunctionAddressForPlatform(
    cl_platform_id platform,
    const char* func_name)
{
    g_clGetExtensionFunctionAddressForPlatform.platform = platform;
    g_clGetExtensionFunctionAddressForPlatform.func_name = func_name;
    return (void*)0;
}

///////////////////////////////////////////////////////////////////////////////

struct clCreateCommandQueueWithProperties_args g_clCreateCommandQueueWithProperties;

CL_API_ENTRY cl_command_queue CL_API_CALL recclCreateCommandQueueWithProperties(
    cl_context context,
    cl_device_id device,
    const cl_queue_properties* properties,
    cl_int* errcode_ret)
{
    g_clCreateCommandQueueWithProperties.context = context;
    g_clCreateCommandQueueWithProperties.device = device;
    g_clCreateCommandQueueWithProperties.properties = properties;
    g_clCreateCommandQueueWithProperties.errcode_ret = errcode_ret;
    return g_CommandQueue;
}

///////////////////////////////////////////////////////////////////////////////

struct clCreatePipe_args g_clCreatePipe;

CL_API_ENTRY cl_mem CL_API_CALL recclCreatePipe(
    cl_context context,
    cl_mem_flags flags,
    cl_uint pipe_packet_size,
    cl_uint pipe_max_packets,
    const cl_pipe_properties* properties,
    cl_int* errcode_ret)
{
    g_clCreatePipe.context = context;
    g_clCreatePipe.flags = flags;
    g_clCreatePipe.pipe_packet_size = pipe_packet_size;
    g_clCreatePipe.pipe_max_packets = pipe_max_packets;
    g_clCreatePipe.properties = properties;
    g_clCreatePipe.errcode_ret = errcode_ret;
    return g_Mem;
}

///////////////////////////////////////////////////////////////////////////////

struct clGetPipeInfo_args g_clGetPipeInfo;

CL_API_ENTRY cl_int CL_API_CALL recclGetPipeInfo(
    cl_mem pipe,
    cl_pipe_info param_name,
    size_t param_value_size,
    void* param_value,
    size_t* param_value_size_ret)
{
    g_clGetPipeInfo.pipe = pipe;
    g_clGetPipeInfo.param_name = param_name;
    g_clGetPipeInfo.param_value_size = param_value_size;
    g_clGetPipeInfo.param_value = param_value;
    g_clGetPipeInfo.param_value_size_ret = param_value_size_ret;
    return (cl_int)0;
}

///////////////////////////////////////////////////////////////////////////////

struct clSVMAlloc_args g_clSVMAlloc;

CL_API_ENTRY void* CL_API_CALL recclSVMAlloc(
    cl_context context,
    cl_svm_mem_flags flags,
    size_t size,
    cl_uint alignment)
{
    g_clSVMAlloc.context = context;
    g_clSVMAlloc.flags = flags;
    g_clSVMAlloc.size = size;
    g_clSVMAlloc.alignment = alignment;
    return (void*)0;
}

///////////////////////////////////////////////////////////////////////////////

struct clSVMFree_args g_clSVMFree;

CL_API_ENTRY void CL_API_CALL recclSVMFree(
    cl_context context,
    void* svm_pointer)
{
    g_clSVMFree.context = context;
    g_clSVMFree.svm_pointer = svm_pointer;
    // no return value
}

///////////////////////////////////////////////////////////////////////////////

struct clCreateSamplerWithProperties_args g_clCreateSamplerWithProperties;

CL_API_ENTRY cl_sampler CL_API_CALL recclCreateSamplerWithProperties(
    cl_context context,
    const cl_sampler_properties* sampler_properties,
    cl_int* errcode_ret)
{
    g_clCreateSamplerWithProperties.context = context;
    g_clCreateSamplerWithProperties.sampler_properties = sampler_properties;
    g_clCreateSamplerWithProperties.errcode_ret = errcode_ret;
    return g_Sampler;
}

///////////////////////////////////////////////////////////////////////////////

struct clSetKernelArgSVMPointer_args g_clSetKernelArgSVMPointer;

CL_API_ENTRY cl_int CL_API_CALL recclSetKernelArgSVMPointer(
    cl_kernel kernel,
    cl_uint arg_index,
    const void* arg_value)
{
    g_clSetKernelArgSVMPointer.kernel = kernel;
    g_clSetKernelArgSVMPointer.arg_index = arg_index;
    g_clSetKernelArgSVMPointer.arg_value = arg_value;
    return (cl_int)0;
}

///////////////////////////////////////////////////////////////////////////////

struct clSetKernelExecInfo_args g_clSetKernelExecInfo;

CL_API_ENTRY cl_int CL_API_CALL recclSetKernelExecInfo(
    cl_kernel kernel,
    cl_kernel_exec_info param_name,
    size_t param_value_size,
    const void* param_value)
{
    g_clSetKernelExecInfo.kernel = kernel;
    g_clSetKernelExecInfo.param_name = param_name;
    g_clSetKernelExecInfo.param_value_size = param_value_size;
    g_clSetKernelExecInfo.param_value = param_value;
    return (cl_int)0;
}

///////////////////////////////////////////////////////////////////////////////

struct clEnqueueSVMFree_args g_clEnqueueSVMFree;

CL_API_ENTRY cl_int CL_API_CALL recclEnqueueSVMFree(
    cl_command_queue command_queue,
    cl_uint num_svm_pointers,
    void* svm_pointers[],
    void (CL_CALLBACK* pfn_free_func)(cl_command_queue queue, cl_uint num_svm_pointers, void* svm_pointers[], void* user_data),
    void* user_data,
    cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list,
    cl_event* event)
{
    g_clEnqueueSVMFree.command_queue = command_queue;
    g_clEnqueueSVMFree.num_svm_pointers = num_svm_pointers;
    g_clEnqueueSVMFree.svm_pointers = svm_pointers;
    g_clEnqueueSVMFree.pfn_free_func = pfn_free_func;
    g_clEnqueueSVMFree.user_data = user_data;
    g_clEnqueueSVMFree.num_events_in_wait_list = num_events_in_wait_list;
    g_clEnqueueSVMFree.event_wait_list = event_wait_list;
    g_clEnqueueSVMFree.event = event;
    return (cl_int)0;
}

///////////////////////////////////////////////////////////////////////////////

struct clEnqueueSVMMemcpy_args g_clEnqueueSVMMemcpy;

CL_API_ENTRY cl_int CL_API_CALL recclEnqueueSVMMemcpy(
    cl_command_queue command_queue,
    cl_bool blocking_copy,
    void* dst_ptr,
    const void* src_ptr,
    size_t size,
    cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list,
    cl_event* event)
{
    g_clEnqueueSVMMemcpy.command_queue = command_queue;
    g_clEnqueueSVMMemcpy.blocking_copy = blocking_copy;
    g_clEnqueueSVMMemcpy.dst_ptr = dst_ptr;
    g_clEnqueueSVMMemcpy.src_ptr = src_ptr;
    g_clEnqueueSVMMemcpy.size = size;
    g_clEnqueueSVMMemcpy.num_events_in_wait_list = num_events_in_wait_list;
    g_clEnqueueSVMMemcpy.event_wait_list = event_wait_list;
    g_clEnqueueSVMMemcpy.event = event;
    return (cl_int)0;
}

///////////////////////////////////////////////////////////////////////////////

struct clEnqueueSVMMemFill_args g_clEnqueueSVMMemFill;

CL_API_ENTRY cl_int CL_API_CALL recclEnqueueSVMMemFill(
    cl_command_queue command_queue,
    void* svm_ptr,
    const void* pattern,
    size_t pattern_size,
    size_t size,
    cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list,
    cl_event* event)
{
    g_clEnqueueSVMMemFill.command_queue = command_queue;
    g_clEnqueueSVMMemFill.svm_ptr = svm_ptr;
    g_clEnqueueSVMMemFill.pattern = pattern;
    g_clEnqueueSVMMemFill.pattern_size = pattern_size;
    g_clEnqueueSVMMemFill.size = size;
    g_clEnqueueSVMMemFill.num_events_in_wait_list = num_events_in_wait_list;
    g_clEnqueueSVMMemFill.event_wait_list = event_wait_list;
    g_clEnqueueSVMMemFill.event = event;
    return (cl_int)0;
}

///////////////////////////////////////////////////////////////////////////////

struct clEnqueueSVMMap_args g_clEnqueueSVMMap;

CL_API_ENTRY cl_int CL_API_CALL recclEnqueueSVMMap(
    cl_command_queue command_queue,
    cl_bool blocking_map,
    cl_map_flags flags,
    void* svm_ptr,
    size_t size,
    cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list,
    cl_event* event)
{
    g_clEnqueueSVMMap.command_queue = command_queue;
    g_clEnqueueSVMMap.blocking_map = blocking_map;
    g_clEnqueueSVMMap.flags = flags;
    g_clEnqueueSVMMap.svm_ptr = svm_ptr;
    g_clEnqueueSVMMap.size = size;
    g_clEnqueueSVMMap.num_events_in_wait_list = num_events_in_wait_list;
    g_clEnqueueSVMMap.event_wait_list = event_wait_list;
    g_clEnqueueSVMMap.event = event;
    return (cl_int)0;
}

///////////////////////////////////////////////////////////////////////////////

struct clEnqueueSVMUnmap_args g_clEnqueueSVMUnmap;

CL_API_ENTRY cl_int CL_API_CALL recclEnqueueSVMUnmap(
    cl_command_queue command_queue,
    void* svm_ptr,
    cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list,
    cl_event* event)
{
    g_clEnqueueSVMUnmap.command_queue = command_queue;
    g_clEnqueueSVMUnmap.svm_ptr = svm_ptr;
    g_clEnqueueSVMUnmap.num_events_in_wait_list = num_events_in_wait_list;
    g_clEnqueueSVMUnmap.event_wait_list = event_wait_list;
    g_clEnqueueSVMUnmap.event = event;
    return (cl_int)0;
}

///////////////////////////////////////////////////////////////////////////////

struct clCreateCommandQueue_args g_clCreateCommandQueue;

CL_API_ENTRY cl_command_queue CL_API_CALL recclCreateCommandQueue(
    cl_context context,
    cl_device_id device,
    cl_command_queue_properties properties,
    cl_int* errcode_ret)
{
    g_clCreateCommandQueue.context = context;
    g_clCreateCommandQueue.device = device;
    g_clCreateCommandQueue.properties = properties;
    g_clCreateCommandQueue.errcode_ret = errcode_ret;
    return g_CommandQueue;
}

///////////////////////////////////////////////////////////////////////////////

struct clCreateSampler_args g_clCreateSampler;

CL_API_ENTRY cl_sampler CL_API_CALL recclCreateSampler(
    cl_context context,
    cl_bool normalized_coords,
    cl_addressing_mode addressing_mode,
    cl_filter_mode filter_mode,
    cl_int* errcode_ret)
{
    g_clCreateSampler.context = context;
    g_clCreateSampler.normalized_coords = normalized_coords;
    g_clCreateSampler.addressing_mode = addressing_mode;
    g_clCreateSampler.filter_mode = filter_mode;
    g_clCreateSampler.errcode_ret = errcode_ret;
    return g_Sampler;
}

///////////////////////////////////////////////////////////////////////////////

struct clEnqueueTask_args g_clEnqueueTask;

CL_API_ENTRY cl_int CL_API_CALL recclEnqueueTask(
    cl_command_queue command_queue,
    cl_kernel kernel,
    cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list,
    cl_event* event)
{
    g_clEnqueueTask.command_queue = command_queue;
    g_clEnqueueTask.kernel = kernel;
    g_clEnqueueTask.num_events_in_wait_list = num_events_in_wait_list;
    g_clEnqueueTask.event_wait_list = event_wait_list;
    g_clEnqueueTask.event = event;
    return (cl_int)0;
}

///////////////////////////////////////////////////////////////////////////////

struct clSetDefaultDeviceCommandQueue_args g_clSetDefaultDeviceCommandQueue;

CL_API_ENTRY cl_int CL_API_CALL recclSetDefaultDeviceCommandQueue(
    cl_context context,
    cl_device_id device,
    cl_command_queue command_queue)
{
    g_clSetDefaultDeviceCommandQueue.context = context;
    g_clSetDefaultDeviceCommandQueue.device = device;
    g_clSetDefaultDeviceCommandQueue.command_queue = command_queue;
    return (cl_int)0;
}

///////////////////////////////////////////////////////////////////////////////

struct clGetDeviceAndHostTimer_args g_clGetDeviceAndHostTimer;

CL_API_ENTRY cl_int CL_API_CALL recclGetDeviceAndHostTimer(
    cl_device_id device,
    cl_ulong* device_timestamp,
    cl_ulong* host_timestamp)
{
    g_clGetDeviceAndHostTimer.device = device;
    g_clGetDeviceAndHostTimer.device_timestamp = device_timestamp;
    g_clGetDeviceAndHostTimer.host_timestamp = host_timestamp;
    return (cl_int)0;
}

///////////////////////////////////////////////////////////////////////////////

struct clGetHostTimer_args g_clGetHostTimer;

CL_API_ENTRY cl_int CL_API_CALL recclGetHostTimer(
    cl_device_id device,
    cl_ulong* host_timestamp)
{
    g_clGetHostTimer.device = device;
    g_clGetHostTimer.host_timestamp = host_timestamp;
    return (cl_int)0;
}

///////////////////////////////////////////////////////////////////////////////

struct clCreateProgramWithIL_args g_clCreateProgramWithIL;

CL_API_ENTRY cl_program CL_API_CALL recclCreateProgramWithIL(
    cl_context context,
    const void* il,
    size_t length,
    cl_int* errcode_ret)
{
    g_clCreateProgramWithIL.context = context;
    g_clCreateProgramWithIL.il = il;
    g_clCreateProgramWithIL.length = length;
    g_clCreateProgramWithIL.errcode_ret = errcode_ret;
    return g_Program;
}

///////////////////////////////////////////////////////////////////////////////

struct clCloneKernel_args g_clCloneKernel;

CL_API_ENTRY cl_kernel CL_API_CALL recclCloneKernel(
    cl_kernel source_kernel,
    cl_int* errcode_ret)
{
    g_clCloneKernel.source_kernel = source_kernel;
    g_clCloneKernel.errcode_ret = errcode_ret;
    return (cl_kernel)0;
}

///////////////////////////////////////////////////////////////////////////////

struct clGetKernelSubGroupInfo_args g_clGetKernelSubGroupInfo;

CL_API_ENTRY cl_int CL_API_CALL recclGetKernelSubGroupInfo(
    cl_kernel kernel,
    cl_device_id device,
    cl_kernel_sub_group_info param_name,
    size_t input_value_size,
    const void* input_value,
    size_t param_value_size,
    void* param_value,
    size_t* param_value_size_ret)
{
    g_clGetKernelSubGroupInfo.kernel = kernel;
    g_clGetKernelSubGroupInfo.device = device;
    g_clGetKernelSubGroupInfo.param_name = param_name;
    g_clGetKernelSubGroupInfo.input_value_size = input_value_size;
    g_clGetKernelSubGroupInfo.input_value = input_value;
    g_clGetKernelSubGroupInfo.param_value_size = param_value_size;
    g_clGetKernelSubGroupInfo.param_value = param_value;
    g_clGetKernelSubGroupInfo.param_value_size_ret = param_value_size_ret;
    return (cl_int)0;
}

///////////////////////////////////////////////////////////////////////////////

struct clEnqueueSVMMigrateMem_args g_clEnqueueSVMMigrateMem;

CL_API_ENTRY cl_int CL_API_CALL recclEnqueueSVMMigrateMem(
    cl_command_queue command_queue,
    cl_uint num_svm_pointers,
    const void** svm_pointers,
    const size_t* sizes,
    cl_mem_migration_flags flags,
    cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list,
    cl_event* event)
{
    g_clEnqueueSVMMigrateMem.command_queue = command_queue;
    g_clEnqueueSVMMigrateMem.num_svm_pointers = num_svm_pointers;
    g_clEnqueueSVMMigrateMem.svm_pointers = svm_pointers;
    g_clEnqueueSVMMigrateMem.sizes = sizes;
    g_clEnqueueSVMMigrateMem.flags = flags;
    g_clEnqueueSVMMigrateMem.num_events_in_wait_list = num_events_in_wait_list;
    g_clEnqueueSVMMigrateMem.event_wait_list = event_wait_list;
    g_clEnqueueSVMMigrateMem.event = event;
    return (cl_int)0;
}

///////////////////////////////////////////////////////////////////////////////

struct clSetProgramReleaseCallback_args g_clSetProgramReleaseCallback;

CL_API_ENTRY cl_int CL_API_CALL recclSetProgramReleaseCallback(
    cl_program program,
    void (CL_CALLBACK* pfn_notify)(cl_program program, void* user_data),
    void* user_data)
{
    g_clSetProgramReleaseCallback.program = program;
    g_clSetProgramReleaseCallback.pfn_notify = pfn_notify;
    g_clSetProgramReleaseCallback.user_data = user_data;
    return (cl_int)0;
}

///////////////////////////////////////////////////////////////////////////////

struct clSetProgramSpecializationConstant_args g_clSetProgramSpecializationConstant;

CL_API_ENTRY cl_int CL_API_CALL recclSetProgramSpecializationConstant(
    cl_program program,
    cl_uint spec_id,
    size_t spec_size,
    const void* spec_value)
{
    g_clSetProgramSpecializationConstant.program = program;
    g_clSetProgramSpecializationConstant.spec_id = spec_id;
    g_clSetProgramSpecializationConstant.spec_size = spec_size;
    g_clSetProgramSpecializationConstant.spec_value = spec_value;
    return (cl_int)0;
}

