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

#pragma once
#include <CL/cl.h>
#include <CL/cl_ext.h>

///////////////////////////////////////////////////////////////////////////////

struct clGetPlatformIDs_args
{
    cl_uint num_entries;
    cl_platform_id* platforms;
    cl_uint* num_platforms;
};
extern struct clGetPlatformIDs_args g_clGetPlatformIDs;

CL_API_ENTRY cl_int CL_API_CALL recclGetPlatformIDs(
    cl_uint num_entries,
    cl_platform_id* platforms,
    cl_uint* num_platforms);

///////////////////////////////////////////////////////////////////////////////

struct clGetPlatformInfo_args
{
    cl_platform_id platform;
    cl_platform_info param_name;
    size_t param_value_size;
    void* param_value;
    size_t* param_value_size_ret;
};
extern struct clGetPlatformInfo_args g_clGetPlatformInfo;

CL_API_ENTRY cl_int CL_API_CALL recclGetPlatformInfo(
    cl_platform_id platform,
    cl_platform_info param_name,
    size_t param_value_size,
    void* param_value,
    size_t* param_value_size_ret);

///////////////////////////////////////////////////////////////////////////////

struct clGetDeviceIDs_args
{
    cl_platform_id platform;
    cl_device_type device_type;
    cl_uint num_entries;
    cl_device_id* devices;
    cl_uint* num_devices;
};
extern struct clGetDeviceIDs_args g_clGetDeviceIDs;

CL_API_ENTRY cl_int CL_API_CALL recclGetDeviceIDs(
    cl_platform_id platform,
    cl_device_type device_type,
    cl_uint num_entries,
    cl_device_id* devices,
    cl_uint* num_devices);

///////////////////////////////////////////////////////////////////////////////

struct clGetDeviceInfo_args
{
    cl_device_id device;
    cl_device_info param_name;
    size_t param_value_size;
    void* param_value;
    size_t* param_value_size_ret;
};
extern struct clGetDeviceInfo_args g_clGetDeviceInfo;

CL_API_ENTRY cl_int CL_API_CALL recclGetDeviceInfo(
    cl_device_id device,
    cl_device_info param_name,
    size_t param_value_size,
    void* param_value,
    size_t* param_value_size_ret);

///////////////////////////////////////////////////////////////////////////////

struct clCreateContext_args
{
    const cl_context_properties* properties;
    cl_uint num_devices;
    const cl_device_id* devices;
    void (CL_CALLBACK* pfn_notify)(const char*, const void*, size_t, void*);
    void* user_data;
    cl_int* errcode_ret;
};
extern struct clCreateContext_args g_clCreateContext;

CL_API_ENTRY cl_context CL_API_CALL recclCreateContext(
    const cl_context_properties* properties,
    cl_uint num_devices,
    const cl_device_id* devices,
    void (CL_CALLBACK* pfn_notify)(const char*, const void*, size_t, void*),
    void* user_data,
    cl_int* errcode_ret);

///////////////////////////////////////////////////////////////////////////////

struct clCreateContextFromType_args
{
    const cl_context_properties* properties;
    cl_device_type device_type;
    void (CL_CALLBACK* pfn_notify)(const char*, const void*, size_t, void*);
    void* user_data;
    cl_int* errcode_ret;
};
extern struct clCreateContextFromType_args g_clCreateContextFromType;

CL_API_ENTRY cl_context CL_API_CALL recclCreateContextFromType(
    const cl_context_properties* properties,
    cl_device_type device_type,
    void (CL_CALLBACK* pfn_notify)(const char*, const void*, size_t, void*),
    void* user_data,
    cl_int* errcode_ret);

///////////////////////////////////////////////////////////////////////////////

struct clRetainContext_args
{
    cl_context context;
};
extern struct clRetainContext_args g_clRetainContext;

CL_API_ENTRY cl_int CL_API_CALL recclRetainContext(
    cl_context context);

///////////////////////////////////////////////////////////////////////////////

struct clReleaseContext_args
{
    cl_context context;
};
extern struct clReleaseContext_args g_clReleaseContext;

CL_API_ENTRY cl_int CL_API_CALL recclReleaseContext(
    cl_context context);

///////////////////////////////////////////////////////////////////////////////

struct clGetContextInfo_args
{
    cl_context context;
    cl_context_info param_name;
    size_t param_value_size;
    void* param_value;
    size_t* param_value_size_ret;
};
extern struct clGetContextInfo_args g_clGetContextInfo;

CL_API_ENTRY cl_int CL_API_CALL recclGetContextInfo(
    cl_context context,
    cl_context_info param_name,
    size_t param_value_size,
    void* param_value,
    size_t* param_value_size_ret);

///////////////////////////////////////////////////////////////////////////////

struct clRetainCommandQueue_args
{
    cl_command_queue command_queue;
};
extern struct clRetainCommandQueue_args g_clRetainCommandQueue;

CL_API_ENTRY cl_int CL_API_CALL recclRetainCommandQueue(
    cl_command_queue command_queue);

///////////////////////////////////////////////////////////////////////////////

struct clReleaseCommandQueue_args
{
    cl_command_queue command_queue;
};
extern struct clReleaseCommandQueue_args g_clReleaseCommandQueue;

CL_API_ENTRY cl_int CL_API_CALL recclReleaseCommandQueue(
    cl_command_queue command_queue);

///////////////////////////////////////////////////////////////////////////////

struct clGetCommandQueueInfo_args
{
    cl_command_queue command_queue;
    cl_command_queue_info param_name;
    size_t param_value_size;
    void* param_value;
    size_t* param_value_size_ret;
};
extern struct clGetCommandQueueInfo_args g_clGetCommandQueueInfo;

CL_API_ENTRY cl_int CL_API_CALL recclGetCommandQueueInfo(
    cl_command_queue command_queue,
    cl_command_queue_info param_name,
    size_t param_value_size,
    void* param_value,
    size_t* param_value_size_ret);

///////////////////////////////////////////////////////////////////////////////

struct clCreateBuffer_args
{
    cl_context context;
    cl_mem_flags flags;
    size_t size;
    void* host_ptr;
    cl_int* errcode_ret;
};
extern struct clCreateBuffer_args g_clCreateBuffer;

CL_API_ENTRY cl_mem CL_API_CALL recclCreateBuffer(
    cl_context context,
    cl_mem_flags flags,
    size_t size,
    void* host_ptr,
    cl_int* errcode_ret);

///////////////////////////////////////////////////////////////////////////////

struct clRetainMemObject_args
{
    cl_mem memobj;
};
extern struct clRetainMemObject_args g_clRetainMemObject;

CL_API_ENTRY cl_int CL_API_CALL recclRetainMemObject(
    cl_mem memobj);

///////////////////////////////////////////////////////////////////////////////

struct clReleaseMemObject_args
{
    cl_mem memobj;
};
extern struct clReleaseMemObject_args g_clReleaseMemObject;

CL_API_ENTRY cl_int CL_API_CALL recclReleaseMemObject(
    cl_mem memobj);

///////////////////////////////////////////////////////////////////////////////

struct clGetSupportedImageFormats_args
{
    cl_context context;
    cl_mem_flags flags;
    cl_mem_object_type image_type;
    cl_uint num_entries;
    cl_image_format* image_formats;
    cl_uint* num_image_formats;
};
extern struct clGetSupportedImageFormats_args g_clGetSupportedImageFormats;

CL_API_ENTRY cl_int CL_API_CALL recclGetSupportedImageFormats(
    cl_context context,
    cl_mem_flags flags,
    cl_mem_object_type image_type,
    cl_uint num_entries,
    cl_image_format* image_formats,
    cl_uint* num_image_formats);

///////////////////////////////////////////////////////////////////////////////

struct clGetMemObjectInfo_args
{
    cl_mem memobj;
    cl_mem_info param_name;
    size_t param_value_size;
    void* param_value;
    size_t* param_value_size_ret;
};
extern struct clGetMemObjectInfo_args g_clGetMemObjectInfo;

CL_API_ENTRY cl_int CL_API_CALL recclGetMemObjectInfo(
    cl_mem memobj,
    cl_mem_info param_name,
    size_t param_value_size,
    void* param_value,
    size_t* param_value_size_ret);

///////////////////////////////////////////////////////////////////////////////

struct clGetImageInfo_args
{
    cl_mem image;
    cl_image_info param_name;
    size_t param_value_size;
    void* param_value;
    size_t* param_value_size_ret;
};
extern struct clGetImageInfo_args g_clGetImageInfo;

CL_API_ENTRY cl_int CL_API_CALL recclGetImageInfo(
    cl_mem image,
    cl_image_info param_name,
    size_t param_value_size,
    void* param_value,
    size_t* param_value_size_ret);

///////////////////////////////////////////////////////////////////////////////

struct clRetainSampler_args
{
    cl_sampler sampler;
};
extern struct clRetainSampler_args g_clRetainSampler;

CL_API_ENTRY cl_int CL_API_CALL recclRetainSampler(
    cl_sampler sampler);

///////////////////////////////////////////////////////////////////////////////

struct clReleaseSampler_args
{
    cl_sampler sampler;
};
extern struct clReleaseSampler_args g_clReleaseSampler;

CL_API_ENTRY cl_int CL_API_CALL recclReleaseSampler(
    cl_sampler sampler);

///////////////////////////////////////////////////////////////////////////////

struct clGetSamplerInfo_args
{
    cl_sampler sampler;
    cl_sampler_info param_name;
    size_t param_value_size;
    void* param_value;
    size_t* param_value_size_ret;
};
extern struct clGetSamplerInfo_args g_clGetSamplerInfo;

CL_API_ENTRY cl_int CL_API_CALL recclGetSamplerInfo(
    cl_sampler sampler,
    cl_sampler_info param_name,
    size_t param_value_size,
    void* param_value,
    size_t* param_value_size_ret);

///////////////////////////////////////////////////////////////////////////////

struct clCreateProgramWithSource_args
{
    cl_context context;
    cl_uint count;
    const char** strings;
    const size_t* lengths;
    cl_int* errcode_ret;
};
extern struct clCreateProgramWithSource_args g_clCreateProgramWithSource;

CL_API_ENTRY cl_program CL_API_CALL recclCreateProgramWithSource(
    cl_context context,
    cl_uint count,
    const char** strings,
    const size_t* lengths,
    cl_int* errcode_ret);

///////////////////////////////////////////////////////////////////////////////

struct clCreateProgramWithBinary_args
{
    cl_context context;
    cl_uint num_devices;
    const cl_device_id* device_list;
    const size_t* lengths;
    const unsigned char** binaries;
    cl_int* binary_status;
    cl_int* errcode_ret;
};
extern struct clCreateProgramWithBinary_args g_clCreateProgramWithBinary;

CL_API_ENTRY cl_program CL_API_CALL recclCreateProgramWithBinary(
    cl_context context,
    cl_uint num_devices,
    const cl_device_id* device_list,
    const size_t* lengths,
    const unsigned char** binaries,
    cl_int* binary_status,
    cl_int* errcode_ret);

///////////////////////////////////////////////////////////////////////////////

struct clRetainProgram_args
{
    cl_program program;
};
extern struct clRetainProgram_args g_clRetainProgram;

CL_API_ENTRY cl_int CL_API_CALL recclRetainProgram(
    cl_program program);

///////////////////////////////////////////////////////////////////////////////

struct clReleaseProgram_args
{
    cl_program program;
};
extern struct clReleaseProgram_args g_clReleaseProgram;

CL_API_ENTRY cl_int CL_API_CALL recclReleaseProgram(
    cl_program program);

///////////////////////////////////////////////////////////////////////////////

struct clBuildProgram_args
{
    cl_program program;
    cl_uint num_devices;
    const cl_device_id* device_list;
    const char* options;
    void (CL_CALLBACK* pfn_notify)(cl_program program, void* user_data);
    void* user_data;
};
extern struct clBuildProgram_args g_clBuildProgram;

CL_API_ENTRY cl_int CL_API_CALL recclBuildProgram(
    cl_program program,
    cl_uint num_devices,
    const cl_device_id* device_list,
    const char* options,
    void (CL_CALLBACK* pfn_notify)(cl_program program, void* user_data),
    void* user_data);

///////////////////////////////////////////////////////////////////////////////

struct clGetProgramInfo_args
{
    cl_program program;
    cl_program_info param_name;
    size_t param_value_size;
    void* param_value;
    size_t* param_value_size_ret;
};
extern struct clGetProgramInfo_args g_clGetProgramInfo;

CL_API_ENTRY cl_int CL_API_CALL recclGetProgramInfo(
    cl_program program,
    cl_program_info param_name,
    size_t param_value_size,
    void* param_value,
    size_t* param_value_size_ret);

///////////////////////////////////////////////////////////////////////////////

struct clGetProgramBuildInfo_args
{
    cl_program program;
    cl_device_id device;
    cl_program_build_info param_name;
    size_t param_value_size;
    void* param_value;
    size_t* param_value_size_ret;
};
extern struct clGetProgramBuildInfo_args g_clGetProgramBuildInfo;

CL_API_ENTRY cl_int CL_API_CALL recclGetProgramBuildInfo(
    cl_program program,
    cl_device_id device,
    cl_program_build_info param_name,
    size_t param_value_size,
    void* param_value,
    size_t* param_value_size_ret);

///////////////////////////////////////////////////////////////////////////////

struct clCreateKernel_args
{
    cl_program program;
    const char* kernel_name;
    cl_int* errcode_ret;
};
extern struct clCreateKernel_args g_clCreateKernel;

CL_API_ENTRY cl_kernel CL_API_CALL recclCreateKernel(
    cl_program program,
    const char* kernel_name,
    cl_int* errcode_ret);

///////////////////////////////////////////////////////////////////////////////

struct clCreateKernelsInProgram_args
{
    cl_program program;
    cl_uint num_kernels;
    cl_kernel* kernels;
    cl_uint* num_kernels_ret;
};
extern struct clCreateKernelsInProgram_args g_clCreateKernelsInProgram;

CL_API_ENTRY cl_int CL_API_CALL recclCreateKernelsInProgram(
    cl_program program,
    cl_uint num_kernels,
    cl_kernel* kernels,
    cl_uint* num_kernels_ret);

///////////////////////////////////////////////////////////////////////////////

struct clRetainKernel_args
{
    cl_kernel kernel;
};
extern struct clRetainKernel_args g_clRetainKernel;

CL_API_ENTRY cl_int CL_API_CALL recclRetainKernel(
    cl_kernel kernel);

///////////////////////////////////////////////////////////////////////////////

struct clReleaseKernel_args
{
    cl_kernel kernel;
};
extern struct clReleaseKernel_args g_clReleaseKernel;

CL_API_ENTRY cl_int CL_API_CALL recclReleaseKernel(
    cl_kernel kernel);

///////////////////////////////////////////////////////////////////////////////

struct clSetKernelArg_args
{
    cl_kernel kernel;
    cl_uint arg_index;
    size_t arg_size;
    const void* arg_value;
};
extern struct clSetKernelArg_args g_clSetKernelArg;

CL_API_ENTRY cl_int CL_API_CALL recclSetKernelArg(
    cl_kernel kernel,
    cl_uint arg_index,
    size_t arg_size,
    const void* arg_value);

///////////////////////////////////////////////////////////////////////////////

struct clGetKernelInfo_args
{
    cl_kernel kernel;
    cl_kernel_info param_name;
    size_t param_value_size;
    void* param_value;
    size_t* param_value_size_ret;
};
extern struct clGetKernelInfo_args g_clGetKernelInfo;

CL_API_ENTRY cl_int CL_API_CALL recclGetKernelInfo(
    cl_kernel kernel,
    cl_kernel_info param_name,
    size_t param_value_size,
    void* param_value,
    size_t* param_value_size_ret);

///////////////////////////////////////////////////////////////////////////////

struct clGetKernelWorkGroupInfo_args
{
    cl_kernel kernel;
    cl_device_id device;
    cl_kernel_work_group_info param_name;
    size_t param_value_size;
    void* param_value;
    size_t* param_value_size_ret;
};
extern struct clGetKernelWorkGroupInfo_args g_clGetKernelWorkGroupInfo;

CL_API_ENTRY cl_int CL_API_CALL recclGetKernelWorkGroupInfo(
    cl_kernel kernel,
    cl_device_id device,
    cl_kernel_work_group_info param_name,
    size_t param_value_size,
    void* param_value,
    size_t* param_value_size_ret);

///////////////////////////////////////////////////////////////////////////////

struct clWaitForEvents_args
{
    cl_uint num_events;
    const cl_event* event_list;
};
extern struct clWaitForEvents_args g_clWaitForEvents;

CL_API_ENTRY cl_int CL_API_CALL recclWaitForEvents(
    cl_uint num_events,
    const cl_event* event_list);

///////////////////////////////////////////////////////////////////////////////

struct clGetEventInfo_args
{
    cl_event event;
    cl_event_info param_name;
    size_t param_value_size;
    void* param_value;
    size_t* param_value_size_ret;
};
extern struct clGetEventInfo_args g_clGetEventInfo;

CL_API_ENTRY cl_int CL_API_CALL recclGetEventInfo(
    cl_event event,
    cl_event_info param_name,
    size_t param_value_size,
    void* param_value,
    size_t* param_value_size_ret);

///////////////////////////////////////////////////////////////////////////////

struct clRetainEvent_args
{
    cl_event event;
};
extern struct clRetainEvent_args g_clRetainEvent;

CL_API_ENTRY cl_int CL_API_CALL recclRetainEvent(
    cl_event event);

///////////////////////////////////////////////////////////////////////////////

struct clReleaseEvent_args
{
    cl_event event;
};
extern struct clReleaseEvent_args g_clReleaseEvent;

CL_API_ENTRY cl_int CL_API_CALL recclReleaseEvent(
    cl_event event);

///////////////////////////////////////////////////////////////////////////////

struct clGetEventProfilingInfo_args
{
    cl_event event;
    cl_profiling_info param_name;
    size_t param_value_size;
    void* param_value;
    size_t* param_value_size_ret;
};
extern struct clGetEventProfilingInfo_args g_clGetEventProfilingInfo;

CL_API_ENTRY cl_int CL_API_CALL recclGetEventProfilingInfo(
    cl_event event,
    cl_profiling_info param_name,
    size_t param_value_size,
    void* param_value,
    size_t* param_value_size_ret);

///////////////////////////////////////////////////////////////////////////////

struct clFlush_args
{
    cl_command_queue command_queue;
};
extern struct clFlush_args g_clFlush;

CL_API_ENTRY cl_int CL_API_CALL recclFlush(
    cl_command_queue command_queue);

///////////////////////////////////////////////////////////////////////////////

struct clFinish_args
{
    cl_command_queue command_queue;
};
extern struct clFinish_args g_clFinish;

CL_API_ENTRY cl_int CL_API_CALL recclFinish(
    cl_command_queue command_queue);

///////////////////////////////////////////////////////////////////////////////

struct clEnqueueReadBuffer_args
{
    cl_command_queue command_queue;
    cl_mem buffer;
    cl_bool blocking_read;
    size_t offset;
    size_t size;
    void* ptr;
    cl_uint num_events_in_wait_list;
    const cl_event* event_wait_list;
    cl_event* event;
};
extern struct clEnqueueReadBuffer_args g_clEnqueueReadBuffer;

CL_API_ENTRY cl_int CL_API_CALL recclEnqueueReadBuffer(
    cl_command_queue command_queue,
    cl_mem buffer,
    cl_bool blocking_read,
    size_t offset,
    size_t size,
    void* ptr,
    cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list,
    cl_event* event);

///////////////////////////////////////////////////////////////////////////////

struct clEnqueueWriteBuffer_args
{
    cl_command_queue command_queue;
    cl_mem buffer;
    cl_bool blocking_write;
    size_t offset;
    size_t size;
    const void* ptr;
    cl_uint num_events_in_wait_list;
    const cl_event* event_wait_list;
    cl_event* event;
};
extern struct clEnqueueWriteBuffer_args g_clEnqueueWriteBuffer;

CL_API_ENTRY cl_int CL_API_CALL recclEnqueueWriteBuffer(
    cl_command_queue command_queue,
    cl_mem buffer,
    cl_bool blocking_write,
    size_t offset,
    size_t size,
    const void* ptr,
    cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list,
    cl_event* event);

///////////////////////////////////////////////////////////////////////////////

struct clEnqueueCopyBuffer_args
{
    cl_command_queue command_queue;
    cl_mem src_buffer;
    cl_mem dst_buffer;
    size_t src_offset;
    size_t dst_offset;
    size_t size;
    cl_uint num_events_in_wait_list;
    const cl_event* event_wait_list;
    cl_event* event;
};
extern struct clEnqueueCopyBuffer_args g_clEnqueueCopyBuffer;

CL_API_ENTRY cl_int CL_API_CALL recclEnqueueCopyBuffer(
    cl_command_queue command_queue,
    cl_mem src_buffer,
    cl_mem dst_buffer,
    size_t src_offset,
    size_t dst_offset,
    size_t size,
    cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list,
    cl_event* event);

///////////////////////////////////////////////////////////////////////////////

struct clEnqueueReadImage_args
{
    cl_command_queue command_queue;
    cl_mem image;
    cl_bool blocking_read;
    const size_t* origin;
    const size_t* region;
    size_t row_pitch;
    size_t slice_pitch;
    void* ptr;
    cl_uint num_events_in_wait_list;
    const cl_event* event_wait_list;
    cl_event* event;
};
extern struct clEnqueueReadImage_args g_clEnqueueReadImage;

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
    cl_event* event);

///////////////////////////////////////////////////////////////////////////////

struct clEnqueueWriteImage_args
{
    cl_command_queue command_queue;
    cl_mem image;
    cl_bool blocking_write;
    const size_t* origin;
    const size_t* region;
    size_t input_row_pitch;
    size_t input_slice_pitch;
    const void* ptr;
    cl_uint num_events_in_wait_list;
    const cl_event* event_wait_list;
    cl_event* event;
};
extern struct clEnqueueWriteImage_args g_clEnqueueWriteImage;

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
    cl_event* event);

///////////////////////////////////////////////////////////////////////////////

struct clEnqueueCopyImage_args
{
    cl_command_queue command_queue;
    cl_mem src_image;
    cl_mem dst_image;
    const size_t* src_origin;
    const size_t* dst_origin;
    const size_t* region;
    cl_uint num_events_in_wait_list;
    const cl_event* event_wait_list;
    cl_event* event;
};
extern struct clEnqueueCopyImage_args g_clEnqueueCopyImage;

CL_API_ENTRY cl_int CL_API_CALL recclEnqueueCopyImage(
    cl_command_queue command_queue,
    cl_mem src_image,
    cl_mem dst_image,
    const size_t* src_origin,
    const size_t* dst_origin,
    const size_t* region,
    cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list,
    cl_event* event);

///////////////////////////////////////////////////////////////////////////////

struct clEnqueueCopyImageToBuffer_args
{
    cl_command_queue command_queue;
    cl_mem src_image;
    cl_mem dst_buffer;
    const size_t* src_origin;
    const size_t* region;
    size_t dst_offset;
    cl_uint num_events_in_wait_list;
    const cl_event* event_wait_list;
    cl_event* event;
};
extern struct clEnqueueCopyImageToBuffer_args g_clEnqueueCopyImageToBuffer;

CL_API_ENTRY cl_int CL_API_CALL recclEnqueueCopyImageToBuffer(
    cl_command_queue command_queue,
    cl_mem src_image,
    cl_mem dst_buffer,
    const size_t* src_origin,
    const size_t* region,
    size_t dst_offset,
    cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list,
    cl_event* event);

///////////////////////////////////////////////////////////////////////////////

struct clEnqueueCopyBufferToImage_args
{
    cl_command_queue command_queue;
    cl_mem src_buffer;
    cl_mem dst_image;
    size_t src_offset;
    const size_t* dst_origin;
    const size_t* region;
    cl_uint num_events_in_wait_list;
    const cl_event* event_wait_list;
    cl_event* event;
};
extern struct clEnqueueCopyBufferToImage_args g_clEnqueueCopyBufferToImage;

CL_API_ENTRY cl_int CL_API_CALL recclEnqueueCopyBufferToImage(
    cl_command_queue command_queue,
    cl_mem src_buffer,
    cl_mem dst_image,
    size_t src_offset,
    const size_t* dst_origin,
    const size_t* region,
    cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list,
    cl_event* event);

///////////////////////////////////////////////////////////////////////////////

struct clEnqueueMapBuffer_args
{
    cl_command_queue command_queue;
    cl_mem buffer;
    cl_bool blocking_map;
    cl_map_flags map_flags;
    size_t offset;
    size_t size;
    cl_uint num_events_in_wait_list;
    const cl_event* event_wait_list;
    cl_event* event;
    cl_int* errcode_ret;
};
extern struct clEnqueueMapBuffer_args g_clEnqueueMapBuffer;

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
    cl_int* errcode_ret);

///////////////////////////////////////////////////////////////////////////////

struct clEnqueueMapImage_args
{
    cl_command_queue command_queue;
    cl_mem image;
    cl_bool blocking_map;
    cl_map_flags map_flags;
    const size_t* origin;
    const size_t* region;
    size_t* image_row_pitch;
    size_t* image_slice_pitch;
    cl_uint num_events_in_wait_list;
    const cl_event* event_wait_list;
    cl_event* event;
    cl_int* errcode_ret;
};
extern struct clEnqueueMapImage_args g_clEnqueueMapImage;

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
    cl_int* errcode_ret);

///////////////////////////////////////////////////////////////////////////////

struct clEnqueueUnmapMemObject_args
{
    cl_command_queue command_queue;
    cl_mem memobj;
    void* mapped_ptr;
    cl_uint num_events_in_wait_list;
    const cl_event* event_wait_list;
    cl_event* event;
};
extern struct clEnqueueUnmapMemObject_args g_clEnqueueUnmapMemObject;

CL_API_ENTRY cl_int CL_API_CALL recclEnqueueUnmapMemObject(
    cl_command_queue command_queue,
    cl_mem memobj,
    void* mapped_ptr,
    cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list,
    cl_event* event);

///////////////////////////////////////////////////////////////////////////////

struct clEnqueueNDRangeKernel_args
{
    cl_command_queue command_queue;
    cl_kernel kernel;
    cl_uint work_dim;
    const size_t* global_work_offset;
    const size_t* global_work_size;
    const size_t* local_work_size;
    cl_uint num_events_in_wait_list;
    const cl_event* event_wait_list;
    cl_event* event;
};
extern struct clEnqueueNDRangeKernel_args g_clEnqueueNDRangeKernel;

CL_API_ENTRY cl_int CL_API_CALL recclEnqueueNDRangeKernel(
    cl_command_queue command_queue,
    cl_kernel kernel,
    cl_uint work_dim,
    const size_t* global_work_offset,
    const size_t* global_work_size,
    const size_t* local_work_size,
    cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list,
    cl_event* event);

///////////////////////////////////////////////////////////////////////////////

struct clEnqueueNativeKernel_args
{
    cl_command_queue command_queue;
    void (CL_CALLBACK* user_func)(void*);
    void* args;
    size_t cb_args;
    cl_uint num_mem_objects;
    const cl_mem* mem_list;
    const void** args_mem_loc;
    cl_uint num_events_in_wait_list;
    const cl_event* event_wait_list;
    cl_event* event;
};
extern struct clEnqueueNativeKernel_args g_clEnqueueNativeKernel;

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
    cl_event* event);

///////////////////////////////////////////////////////////////////////////////

struct clSetCommandQueueProperty_args
{
    cl_command_queue command_queue;
    cl_command_queue_properties properties;
    cl_bool enable;
    cl_command_queue_properties* old_properties;
};
extern struct clSetCommandQueueProperty_args g_clSetCommandQueueProperty;

CL_API_ENTRY cl_int CL_API_CALL recclSetCommandQueueProperty(
    cl_command_queue command_queue,
    cl_command_queue_properties properties,
    cl_bool enable,
    cl_command_queue_properties* old_properties);

///////////////////////////////////////////////////////////////////////////////

struct clCreateSubBuffer_args
{
    cl_mem buffer;
    cl_mem_flags flags;
    cl_buffer_create_type buffer_create_type;
    const void* buffer_create_info;
    cl_int* errcode_ret;
};
extern struct clCreateSubBuffer_args g_clCreateSubBuffer;

CL_API_ENTRY cl_mem CL_API_CALL recclCreateSubBuffer(
    cl_mem buffer,
    cl_mem_flags flags,
    cl_buffer_create_type buffer_create_type,
    const void* buffer_create_info,
    cl_int* errcode_ret);

///////////////////////////////////////////////////////////////////////////////

struct clSetMemObjectDestructorCallback_args
{
    cl_mem memobj;
    void (CL_CALLBACK* pfn_notify)(cl_mem memobj, void* user_data);
    void* user_data;
};
extern struct clSetMemObjectDestructorCallback_args g_clSetMemObjectDestructorCallback;

CL_API_ENTRY cl_int CL_API_CALL recclSetMemObjectDestructorCallback(
    cl_mem memobj,
    void (CL_CALLBACK* pfn_notify)(cl_mem memobj, void* user_data),
    void* user_data);

///////////////////////////////////////////////////////////////////////////////

struct clCreateUserEvent_args
{
    cl_context context;
    cl_int* errcode_ret;
};
extern struct clCreateUserEvent_args g_clCreateUserEvent;

CL_API_ENTRY cl_event CL_API_CALL recclCreateUserEvent(
    cl_context context,
    cl_int* errcode_ret);

///////////////////////////////////////////////////////////////////////////////

struct clSetUserEventStatus_args
{
    cl_event event;
    cl_int execution_status;
};
extern struct clSetUserEventStatus_args g_clSetUserEventStatus;

CL_API_ENTRY cl_int CL_API_CALL recclSetUserEventStatus(
    cl_event event,
    cl_int execution_status);

///////////////////////////////////////////////////////////////////////////////

struct clSetEventCallback_args
{
    cl_event event;
    cl_int command_exec_callback_type;
    void (CL_CALLBACK* pfn_notify)(cl_event event, cl_int type, void *user_data);
    void* user_data;
};
extern struct clSetEventCallback_args g_clSetEventCallback;

CL_API_ENTRY cl_int CL_API_CALL recclSetEventCallback(
    cl_event event,
    cl_int command_exec_callback_type,
    void (CL_CALLBACK* pfn_notify)(cl_event event, cl_int type, void *user_data),
    void* user_data);

///////////////////////////////////////////////////////////////////////////////

struct clEnqueueReadBufferRect_args
{
    cl_command_queue command_queue;
    cl_mem buffer;
    cl_bool blocking_read;
    const size_t* buffer_offset;
    const size_t* host_offset;
    const size_t* region;
    size_t buffer_row_pitch;
    size_t buffer_slice_pitch;
    size_t host_row_pitch;
    size_t host_slice_pitch;
    void* ptr;
    cl_uint num_events_in_wait_list;
    const cl_event* event_wait_list;
    cl_event* event;
};
extern struct clEnqueueReadBufferRect_args g_clEnqueueReadBufferRect;

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
    cl_event* event);

///////////////////////////////////////////////////////////////////////////////

struct clEnqueueWriteBufferRect_args
{
    cl_command_queue command_queue;
    cl_mem buffer;
    cl_bool blocking_write;
    const size_t* buffer_offset;
    const size_t* host_offset;
    const size_t* region;
    size_t buffer_row_pitch;
    size_t buffer_slice_pitch;
    size_t host_row_pitch;
    size_t host_slice_pitch;
    const void* ptr;
    cl_uint num_events_in_wait_list;
    const cl_event* event_wait_list;
    cl_event* event;
};
extern struct clEnqueueWriteBufferRect_args g_clEnqueueWriteBufferRect;

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
    cl_event* event);

///////////////////////////////////////////////////////////////////////////////

struct clEnqueueCopyBufferRect_args
{
    cl_command_queue command_queue;
    cl_mem src_buffer;
    cl_mem dst_buffer;
    const size_t* src_origin;
    const size_t* dst_origin;
    const size_t* region;
    size_t src_row_pitch;
    size_t src_slice_pitch;
    size_t dst_row_pitch;
    size_t dst_slice_pitch;
    cl_uint num_events_in_wait_list;
    const cl_event* event_wait_list;
    cl_event* event;
};
extern struct clEnqueueCopyBufferRect_args g_clEnqueueCopyBufferRect;

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
    cl_event* event);

///////////////////////////////////////////////////////////////////////////////

struct clCreateImage2D_args
{
    cl_context context;
    cl_mem_flags flags;
    const cl_image_format* image_format;
    size_t image_width;
    size_t image_height;
    size_t image_row_pitch;
    void* host_ptr;
    cl_int* errcode_ret;
};
extern struct clCreateImage2D_args g_clCreateImage2D;

CL_API_ENTRY cl_mem CL_API_CALL recclCreateImage2D(
    cl_context context,
    cl_mem_flags flags,
    const cl_image_format* image_format,
    size_t image_width,
    size_t image_height,
    size_t image_row_pitch,
    void* host_ptr,
    cl_int* errcode_ret);

///////////////////////////////////////////////////////////////////////////////

struct clCreateImage3D_args
{
    cl_context context;
    cl_mem_flags flags;
    const cl_image_format* image_format;
    size_t image_width;
    size_t image_height;
    size_t image_depth;
    size_t image_row_pitch;
    size_t image_slice_pitch;
    void* host_ptr;
    cl_int* errcode_ret;
};
extern struct clCreateImage3D_args g_clCreateImage3D;

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
    cl_int* errcode_ret);

///////////////////////////////////////////////////////////////////////////////

struct clEnqueueMarker_args
{
    cl_command_queue command_queue;
    cl_event* event;
};
extern struct clEnqueueMarker_args g_clEnqueueMarker;

CL_API_ENTRY cl_int CL_API_CALL recclEnqueueMarker(
    cl_command_queue command_queue,
    cl_event* event);

///////////////////////////////////////////////////////////////////////////////

struct clEnqueueWaitForEvents_args
{
    cl_command_queue command_queue;
    cl_uint num_events;
    const cl_event* event_list;
};
extern struct clEnqueueWaitForEvents_args g_clEnqueueWaitForEvents;

CL_API_ENTRY cl_int CL_API_CALL recclEnqueueWaitForEvents(
    cl_command_queue command_queue,
    cl_uint num_events,
    const cl_event* event_list);

///////////////////////////////////////////////////////////////////////////////

struct clEnqueueBarrier_args
{
    cl_command_queue command_queue;
};
extern struct clEnqueueBarrier_args g_clEnqueueBarrier;

CL_API_ENTRY cl_int CL_API_CALL recclEnqueueBarrier(
    cl_command_queue command_queue);

///////////////////////////////////////////////////////////////////////////////

CL_API_ENTRY cl_int CL_API_CALL recclUnloadCompiler(void);

///////////////////////////////////////////////////////////////////////////////

struct clGetExtensionFunctionAddress_args
{
    const char* func_name;
};
extern struct clGetExtensionFunctionAddress_args g_clGetExtensionFunctionAddress;

CL_API_ENTRY void* CL_API_CALL recclGetExtensionFunctionAddress(
    const char* func_name);

///////////////////////////////////////////////////////////////////////////////

struct clCreateSubDevices_args
{
    cl_device_id in_device;
    const cl_device_partition_property* properties;
    cl_uint num_devices;
    cl_device_id* out_devices;
    cl_uint* num_devices_ret;
};
extern struct clCreateSubDevices_args g_clCreateSubDevices;

CL_API_ENTRY cl_int CL_API_CALL recclCreateSubDevices(
    cl_device_id in_device,
    const cl_device_partition_property* properties,
    cl_uint num_devices,
    cl_device_id* out_devices,
    cl_uint* num_devices_ret);

///////////////////////////////////////////////////////////////////////////////

struct clRetainDevice_args
{
    cl_device_id device;
};
extern struct clRetainDevice_args g_clRetainDevice;

CL_API_ENTRY cl_int CL_API_CALL recclRetainDevice(
    cl_device_id device);

///////////////////////////////////////////////////////////////////////////////

struct clReleaseDevice_args
{
    cl_device_id device;
};
extern struct clReleaseDevice_args g_clReleaseDevice;

CL_API_ENTRY cl_int CL_API_CALL recclReleaseDevice(
    cl_device_id device);

///////////////////////////////////////////////////////////////////////////////

struct clCreateImage_args
{
    cl_context context;
    cl_mem_flags flags;
    const cl_image_format* image_format;
    const cl_image_desc* image_desc;
    void* host_ptr;
    cl_int* errcode_ret;
};
extern struct clCreateImage_args g_clCreateImage;

CL_API_ENTRY cl_mem CL_API_CALL recclCreateImage(
    cl_context context,
    cl_mem_flags flags,
    const cl_image_format* image_format,
    const cl_image_desc* image_desc,
    void* host_ptr,
    cl_int* errcode_ret);

///////////////////////////////////////////////////////////////////////////////

struct clCreateProgramWithBuiltInKernels_args
{
    cl_context context;
    cl_uint num_devices;
    const cl_device_id* device_list;
    const char* kernel_names;
    cl_int* errcode_ret;
};
extern struct clCreateProgramWithBuiltInKernels_args g_clCreateProgramWithBuiltInKernels;

CL_API_ENTRY cl_program CL_API_CALL recclCreateProgramWithBuiltInKernels(
    cl_context context,
    cl_uint num_devices,
    const cl_device_id* device_list,
    const char* kernel_names,
    cl_int* errcode_ret);

///////////////////////////////////////////////////////////////////////////////

struct clCompileProgram_args
{
    cl_program program;
    cl_uint num_devices;
    const cl_device_id* device_list;
    const char* options;
    cl_uint num_input_headers;
    const cl_program* input_headers;
    const char** header_include_names;
    void (CL_CALLBACK* pfn_notify)(cl_program program, void* user_data);
    void* user_data;
};
extern struct clCompileProgram_args g_clCompileProgram;

CL_API_ENTRY cl_int CL_API_CALL recclCompileProgram(
    cl_program program,
    cl_uint num_devices,
    const cl_device_id* device_list,
    const char* options,
    cl_uint num_input_headers,
    const cl_program* input_headers,
    const char** header_include_names,
    void (CL_CALLBACK* pfn_notify)(cl_program program, void* user_data),
    void* user_data);

///////////////////////////////////////////////////////////////////////////////

struct clLinkProgram_args
{
    cl_context context;
    cl_uint num_devices;
    const cl_device_id* device_list;
    const char* options;
    cl_uint num_input_programs;
    const cl_program* input_programs;
    void (CL_CALLBACK* pfn_notify)(cl_program program, void* user_data);
    void* user_data;
    cl_int* errcode_ret;
};
extern struct clLinkProgram_args g_clLinkProgram;

CL_API_ENTRY cl_program CL_API_CALL recclLinkProgram(
    cl_context context,
    cl_uint num_devices,
    const cl_device_id* device_list,
    const char* options,
    cl_uint num_input_programs,
    const cl_program* input_programs,
    void (CL_CALLBACK* pfn_notify)(cl_program program, void* user_data),
    void* user_data,
    cl_int* errcode_ret);

///////////////////////////////////////////////////////////////////////////////

struct clUnloadPlatformCompiler_args
{
    cl_platform_id platform;
};
extern struct clUnloadPlatformCompiler_args g_clUnloadPlatformCompiler;

CL_API_ENTRY cl_int CL_API_CALL recclUnloadPlatformCompiler(
    cl_platform_id platform);

///////////////////////////////////////////////////////////////////////////////

struct clGetKernelArgInfo_args
{
    cl_kernel kernel;
    cl_uint arg_indx;
    cl_kernel_arg_info param_name;
    size_t param_value_size;
    void* param_value;
    size_t* param_value_size_ret;
};
extern struct clGetKernelArgInfo_args g_clGetKernelArgInfo;

CL_API_ENTRY cl_int CL_API_CALL recclGetKernelArgInfo(
    cl_kernel kernel,
    cl_uint arg_indx,
    cl_kernel_arg_info param_name,
    size_t param_value_size,
    void* param_value,
    size_t* param_value_size_ret);

///////////////////////////////////////////////////////////////////////////////

struct clEnqueueFillBuffer_args
{
    cl_command_queue command_queue;
    cl_mem buffer;
    const void* pattern;
    size_t pattern_size;
    size_t offset;
    size_t size;
    cl_uint num_events_in_wait_list;
    const cl_event* event_wait_list;
    cl_event* event;
};
extern struct clEnqueueFillBuffer_args g_clEnqueueFillBuffer;

CL_API_ENTRY cl_int CL_API_CALL recclEnqueueFillBuffer(
    cl_command_queue command_queue,
    cl_mem buffer,
    const void* pattern,
    size_t pattern_size,
    size_t offset,
    size_t size,
    cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list,
    cl_event* event);

///////////////////////////////////////////////////////////////////////////////

struct clEnqueueFillImage_args
{
    cl_command_queue command_queue;
    cl_mem image;
    const void* fill_color;
    const size_t* origin;
    const size_t* region;
    cl_uint num_events_in_wait_list;
    const cl_event* event_wait_list;
    cl_event* event;
};
extern struct clEnqueueFillImage_args g_clEnqueueFillImage;

CL_API_ENTRY cl_int CL_API_CALL recclEnqueueFillImage(
    cl_command_queue command_queue,
    cl_mem image,
    const void* fill_color,
    const size_t* origin,
    const size_t* region,
    cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list,
    cl_event* event);

///////////////////////////////////////////////////////////////////////////////

struct clEnqueueMigrateMemObjects_args
{
    cl_command_queue command_queue;
    cl_uint num_mem_objects;
    const cl_mem* mem_objects;
    cl_mem_migration_flags flags;
    cl_uint num_events_in_wait_list;
    const cl_event* event_wait_list;
    cl_event* event;
};
extern struct clEnqueueMigrateMemObjects_args g_clEnqueueMigrateMemObjects;

CL_API_ENTRY cl_int CL_API_CALL recclEnqueueMigrateMemObjects(
    cl_command_queue command_queue,
    cl_uint num_mem_objects,
    const cl_mem* mem_objects,
    cl_mem_migration_flags flags,
    cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list,
    cl_event* event);

///////////////////////////////////////////////////////////////////////////////

struct clEnqueueMarkerWithWaitList_args
{
    cl_command_queue command_queue;
    cl_uint num_events_in_wait_list;
    const cl_event* event_wait_list;
    cl_event* event;
};
extern struct clEnqueueMarkerWithWaitList_args g_clEnqueueMarkerWithWaitList;

CL_API_ENTRY cl_int CL_API_CALL recclEnqueueMarkerWithWaitList(
    cl_command_queue command_queue,
    cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list,
    cl_event* event);

///////////////////////////////////////////////////////////////////////////////

struct clEnqueueBarrierWithWaitList_args
{
    cl_command_queue command_queue;
    cl_uint num_events_in_wait_list;
    const cl_event* event_wait_list;
    cl_event* event;
};
extern struct clEnqueueBarrierWithWaitList_args g_clEnqueueBarrierWithWaitList;

CL_API_ENTRY cl_int CL_API_CALL recclEnqueueBarrierWithWaitList(
    cl_command_queue command_queue,
    cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list,
    cl_event* event);

///////////////////////////////////////////////////////////////////////////////

struct clGetExtensionFunctionAddressForPlatform_args
{
    cl_platform_id platform;
    const char* func_name;
};
extern struct clGetExtensionFunctionAddressForPlatform_args g_clGetExtensionFunctionAddressForPlatform;

CL_API_ENTRY void* CL_API_CALL recclGetExtensionFunctionAddressForPlatform(
    cl_platform_id platform,
    const char* func_name);

///////////////////////////////////////////////////////////////////////////////

struct clCreateCommandQueueWithProperties_args
{
    cl_context context;
    cl_device_id device;
    const cl_queue_properties* properties;
    cl_int* errcode_ret;
};
extern struct clCreateCommandQueueWithProperties_args g_clCreateCommandQueueWithProperties;

CL_API_ENTRY cl_command_queue CL_API_CALL recclCreateCommandQueueWithProperties(
    cl_context context,
    cl_device_id device,
    const cl_queue_properties* properties,
    cl_int* errcode_ret);

///////////////////////////////////////////////////////////////////////////////

struct clCreatePipe_args
{
    cl_context context;
    cl_mem_flags flags;
    cl_uint pipe_packet_size;
    cl_uint pipe_max_packets;
    const cl_pipe_properties* properties;
    cl_int* errcode_ret;
};
extern struct clCreatePipe_args g_clCreatePipe;

CL_API_ENTRY cl_mem CL_API_CALL recclCreatePipe(
    cl_context context,
    cl_mem_flags flags,
    cl_uint pipe_packet_size,
    cl_uint pipe_max_packets,
    const cl_pipe_properties* properties,
    cl_int* errcode_ret);

///////////////////////////////////////////////////////////////////////////////

struct clGetPipeInfo_args
{
    cl_mem pipe;
    cl_pipe_info param_name;
    size_t param_value_size;
    void* param_value;
    size_t* param_value_size_ret;
};
extern struct clGetPipeInfo_args g_clGetPipeInfo;

CL_API_ENTRY cl_int CL_API_CALL recclGetPipeInfo(
    cl_mem pipe,
    cl_pipe_info param_name,
    size_t param_value_size,
    void* param_value,
    size_t* param_value_size_ret);

///////////////////////////////////////////////////////////////////////////////

struct clSVMAlloc_args
{
    cl_context context;
    cl_svm_mem_flags flags;
    size_t size;
    cl_uint alignment;
};
extern struct clSVMAlloc_args g_clSVMAlloc;

CL_API_ENTRY void* CL_API_CALL recclSVMAlloc(
    cl_context context,
    cl_svm_mem_flags flags,
    size_t size,
    cl_uint alignment);

///////////////////////////////////////////////////////////////////////////////

struct clSVMFree_args
{
    cl_context context;
    void* svm_pointer;
};
extern struct clSVMFree_args g_clSVMFree;

CL_API_ENTRY void CL_API_CALL recclSVMFree(
    cl_context context,
    void* svm_pointer);

///////////////////////////////////////////////////////////////////////////////

struct clCreateSamplerWithProperties_args
{
    cl_context context;
    const cl_sampler_properties* sampler_properties;
    cl_int* errcode_ret;
};
extern struct clCreateSamplerWithProperties_args g_clCreateSamplerWithProperties;

CL_API_ENTRY cl_sampler CL_API_CALL recclCreateSamplerWithProperties(
    cl_context context,
    const cl_sampler_properties* sampler_properties,
    cl_int* errcode_ret);

///////////////////////////////////////////////////////////////////////////////

struct clSetKernelArgSVMPointer_args
{
    cl_kernel kernel;
    cl_uint arg_index;
    const void* arg_value;
};
extern struct clSetKernelArgSVMPointer_args g_clSetKernelArgSVMPointer;

CL_API_ENTRY cl_int CL_API_CALL recclSetKernelArgSVMPointer(
    cl_kernel kernel,
    cl_uint arg_index,
    const void* arg_value);

///////////////////////////////////////////////////////////////////////////////

struct clSetKernelExecInfo_args
{
    cl_kernel kernel;
    cl_kernel_exec_info param_name;
    size_t param_value_size;
    const void* param_value;
};
extern struct clSetKernelExecInfo_args g_clSetKernelExecInfo;

CL_API_ENTRY cl_int CL_API_CALL recclSetKernelExecInfo(
    cl_kernel kernel,
    cl_kernel_exec_info param_name,
    size_t param_value_size,
    const void* param_value);

///////////////////////////////////////////////////////////////////////////////

struct clEnqueueSVMFree_args
{
    cl_command_queue command_queue;
    cl_uint num_svm_pointers;
    void** svm_pointers;
    void (CL_CALLBACK* pfn_free_func)(cl_command_queue queue, cl_uint num_svm_pointers, void* svm_pointers[], void* user_data);
    void* user_data;
    cl_uint num_events_in_wait_list;
    const cl_event* event_wait_list;
    cl_event* event;
};
extern struct clEnqueueSVMFree_args g_clEnqueueSVMFree;

CL_API_ENTRY cl_int CL_API_CALL recclEnqueueSVMFree(
    cl_command_queue command_queue,
    cl_uint num_svm_pointers,
    void* svm_pointers[],
    void (CL_CALLBACK* pfn_free_func)(cl_command_queue queue, cl_uint num_svm_pointers, void* svm_pointers[], void* user_data),
    void* user_data,
    cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list,
    cl_event* event);

///////////////////////////////////////////////////////////////////////////////

struct clEnqueueSVMMemcpy_args
{
    cl_command_queue command_queue;
    cl_bool blocking_copy;
    void* dst_ptr;
    const void* src_ptr;
    size_t size;
    cl_uint num_events_in_wait_list;
    const cl_event* event_wait_list;
    cl_event* event;
};
extern struct clEnqueueSVMMemcpy_args g_clEnqueueSVMMemcpy;

CL_API_ENTRY cl_int CL_API_CALL recclEnqueueSVMMemcpy(
    cl_command_queue command_queue,
    cl_bool blocking_copy,
    void* dst_ptr,
    const void* src_ptr,
    size_t size,
    cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list,
    cl_event* event);

///////////////////////////////////////////////////////////////////////////////

struct clEnqueueSVMMemFill_args
{
    cl_command_queue command_queue;
    void* svm_ptr;
    const void* pattern;
    size_t pattern_size;
    size_t size;
    cl_uint num_events_in_wait_list;
    const cl_event* event_wait_list;
    cl_event* event;
};
extern struct clEnqueueSVMMemFill_args g_clEnqueueSVMMemFill;

CL_API_ENTRY cl_int CL_API_CALL recclEnqueueSVMMemFill(
    cl_command_queue command_queue,
    void* svm_ptr,
    const void* pattern,
    size_t pattern_size,
    size_t size,
    cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list,
    cl_event* event);

///////////////////////////////////////////////////////////////////////////////

struct clEnqueueSVMMap_args
{
    cl_command_queue command_queue;
    cl_bool blocking_map;
    cl_map_flags flags;
    void* svm_ptr;
    size_t size;
    cl_uint num_events_in_wait_list;
    const cl_event* event_wait_list;
    cl_event* event;
};
extern struct clEnqueueSVMMap_args g_clEnqueueSVMMap;

CL_API_ENTRY cl_int CL_API_CALL recclEnqueueSVMMap(
    cl_command_queue command_queue,
    cl_bool blocking_map,
    cl_map_flags flags,
    void* svm_ptr,
    size_t size,
    cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list,
    cl_event* event);

///////////////////////////////////////////////////////////////////////////////

struct clEnqueueSVMUnmap_args
{
    cl_command_queue command_queue;
    void* svm_ptr;
    cl_uint num_events_in_wait_list;
    const cl_event* event_wait_list;
    cl_event* event;
};
extern struct clEnqueueSVMUnmap_args g_clEnqueueSVMUnmap;

CL_API_ENTRY cl_int CL_API_CALL recclEnqueueSVMUnmap(
    cl_command_queue command_queue,
    void* svm_ptr,
    cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list,
    cl_event* event);

///////////////////////////////////////////////////////////////////////////////

struct clCreateCommandQueue_args
{
    cl_context context;
    cl_device_id device;
    cl_command_queue_properties properties;
    cl_int* errcode_ret;
};
extern struct clCreateCommandQueue_args g_clCreateCommandQueue;

CL_API_ENTRY cl_command_queue CL_API_CALL recclCreateCommandQueue(
    cl_context context,
    cl_device_id device,
    cl_command_queue_properties properties,
    cl_int* errcode_ret);

///////////////////////////////////////////////////////////////////////////////

struct clCreateSampler_args
{
    cl_context context;
    cl_bool normalized_coords;
    cl_addressing_mode addressing_mode;
    cl_filter_mode filter_mode;
    cl_int* errcode_ret;
};
extern struct clCreateSampler_args g_clCreateSampler;

CL_API_ENTRY cl_sampler CL_API_CALL recclCreateSampler(
    cl_context context,
    cl_bool normalized_coords,
    cl_addressing_mode addressing_mode,
    cl_filter_mode filter_mode,
    cl_int* errcode_ret);

///////////////////////////////////////////////////////////////////////////////

struct clEnqueueTask_args
{
    cl_command_queue command_queue;
    cl_kernel kernel;
    cl_uint num_events_in_wait_list;
    const cl_event* event_wait_list;
    cl_event* event;
};
extern struct clEnqueueTask_args g_clEnqueueTask;

CL_API_ENTRY cl_int CL_API_CALL recclEnqueueTask(
    cl_command_queue command_queue,
    cl_kernel kernel,
    cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list,
    cl_event* event);

///////////////////////////////////////////////////////////////////////////////

struct clSetDefaultDeviceCommandQueue_args
{
    cl_context context;
    cl_device_id device;
    cl_command_queue command_queue;
};
extern struct clSetDefaultDeviceCommandQueue_args g_clSetDefaultDeviceCommandQueue;

CL_API_ENTRY cl_int CL_API_CALL recclSetDefaultDeviceCommandQueue(
    cl_context context,
    cl_device_id device,
    cl_command_queue command_queue);

///////////////////////////////////////////////////////////////////////////////

struct clGetDeviceAndHostTimer_args
{
    cl_device_id device;
    cl_ulong* device_timestamp;
    cl_ulong* host_timestamp;
};
extern struct clGetDeviceAndHostTimer_args g_clGetDeviceAndHostTimer;

CL_API_ENTRY cl_int CL_API_CALL recclGetDeviceAndHostTimer(
    cl_device_id device,
    cl_ulong* device_timestamp,
    cl_ulong* host_timestamp);

///////////////////////////////////////////////////////////////////////////////

struct clGetHostTimer_args
{
    cl_device_id device;
    cl_ulong* host_timestamp;
};
extern struct clGetHostTimer_args g_clGetHostTimer;

CL_API_ENTRY cl_int CL_API_CALL recclGetHostTimer(
    cl_device_id device,
    cl_ulong* host_timestamp);

///////////////////////////////////////////////////////////////////////////////

struct clCreateProgramWithIL_args
{
    cl_context context;
    const void* il;
    size_t length;
    cl_int* errcode_ret;
};
extern struct clCreateProgramWithIL_args g_clCreateProgramWithIL;

CL_API_ENTRY cl_program CL_API_CALL recclCreateProgramWithIL(
    cl_context context,
    const void* il,
    size_t length,
    cl_int* errcode_ret);

///////////////////////////////////////////////////////////////////////////////

struct clCloneKernel_args
{
    cl_kernel source_kernel;
    cl_int* errcode_ret;
};
extern struct clCloneKernel_args g_clCloneKernel;

CL_API_ENTRY cl_kernel CL_API_CALL recclCloneKernel(
    cl_kernel source_kernel,
    cl_int* errcode_ret);

///////////////////////////////////////////////////////////////////////////////

struct clGetKernelSubGroupInfo_args
{
    cl_kernel kernel;
    cl_device_id device;
    cl_kernel_sub_group_info param_name;
    size_t input_value_size;
    const void* input_value;
    size_t param_value_size;
    void* param_value;
    size_t* param_value_size_ret;
};
extern struct clGetKernelSubGroupInfo_args g_clGetKernelSubGroupInfo;

CL_API_ENTRY cl_int CL_API_CALL recclGetKernelSubGroupInfo(
    cl_kernel kernel,
    cl_device_id device,
    cl_kernel_sub_group_info param_name,
    size_t input_value_size,
    const void* input_value,
    size_t param_value_size,
    void* param_value,
    size_t* param_value_size_ret);

///////////////////////////////////////////////////////////////////////////////

struct clEnqueueSVMMigrateMem_args
{
    cl_command_queue command_queue;
    cl_uint num_svm_pointers;
    const void** svm_pointers;
    const size_t* sizes;
    cl_mem_migration_flags flags;
    cl_uint num_events_in_wait_list;
    const cl_event* event_wait_list;
    cl_event* event;
};
extern struct clEnqueueSVMMigrateMem_args g_clEnqueueSVMMigrateMem;

CL_API_ENTRY cl_int CL_API_CALL recclEnqueueSVMMigrateMem(
    cl_command_queue command_queue,
    cl_uint num_svm_pointers,
    const void** svm_pointers,
    const size_t* sizes,
    cl_mem_migration_flags flags,
    cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list,
    cl_event* event);

///////////////////////////////////////////////////////////////////////////////

struct clSetProgramReleaseCallback_args
{
    cl_program program;
    void (CL_CALLBACK* pfn_notify)(cl_program program, void* user_data);
    void* user_data;
};
extern struct clSetProgramReleaseCallback_args g_clSetProgramReleaseCallback;

CL_API_ENTRY cl_int CL_API_CALL recclSetProgramReleaseCallback(
    cl_program program,
    void (CL_CALLBACK* pfn_notify)(cl_program program, void* user_data),
    void* user_data);

///////////////////////////////////////////////////////////////////////////////

struct clSetProgramSpecializationConstant_args
{
    cl_program program;
    cl_uint spec_id;
    size_t spec_size;
    const void* spec_value;
};
extern struct clSetProgramSpecializationConstant_args g_clSetProgramSpecializationConstant;

CL_API_ENTRY cl_int CL_API_CALL recclSetProgramSpecializationConstant(
    cl_program program,
    cl_uint spec_id,
    size_t spec_size,
    const void* spec_value);

