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
#include "gtest/gtest.h"

#include "../recorder/recorder.h"

///////////////////////////////////////////////////////////////////////////////

TEST(Context, clCreateCommandQueue) {
    cl_int errorCode = CL_SUCCESS;

    cl_command_queue_properties properties = CL_QUEUE_OUT_OF_ORDER_EXEC_MODE_ENABLE;

    struct clCreateCommandQueue_args testArgs = {
        g_Context,
        g_Device,
        properties,
        &errorCode,
    };

    memset(&g_clCreateCommandQueue, 0xCC, sizeof(g_clCreateCommandQueue));

    cl_command_queue ret = clCreateCommandQueue(
        testArgs.context,
        testArgs.device,
        testArgs.properties,
        testArgs.errcode_ret);

    EXPECT_EQ( ret, g_CommandQueue );
    EXPECT_EQ( testArgs.context, g_clCreateCommandQueue.context );
    EXPECT_EQ( testArgs.device, g_clCreateCommandQueue.device );
    EXPECT_EQ( testArgs.properties, g_clCreateCommandQueue.properties );
    EXPECT_EQ( testArgs.errcode_ret, g_clCreateCommandQueue.errcode_ret );
}

///////////////////////////////////////////////////////////////////////////////

TEST(Context, clCreateCommandQueueWithProperties) {
    cl_int errorCode = CL_SUCCESS;

    cl_queue_properties properties = 0;

    struct clCreateCommandQueueWithProperties_args testArgs = {
        g_Context,
        g_Device,
        &properties,
        &errorCode,
    };

    memset(&g_clCreateCommandQueueWithProperties, 0xCC, sizeof(g_clCreateCommandQueueWithProperties));

    cl_command_queue ret = clCreateCommandQueueWithProperties(
        testArgs.context,
        testArgs.device,
        testArgs.properties,
        testArgs.errcode_ret);

    EXPECT_EQ( ret, g_CommandQueue );
    EXPECT_EQ( testArgs.context, g_clCreateCommandQueueWithProperties.context );
    EXPECT_EQ( testArgs.device, g_clCreateCommandQueueWithProperties.device );
    EXPECT_EQ( testArgs.properties, g_clCreateCommandQueueWithProperties.properties );
    EXPECT_EQ( testArgs.errcode_ret, g_clCreateCommandQueueWithProperties.errcode_ret );
}

///////////////////////////////////////////////////////////////////////////////

TEST(Category, clCreateBuffer) {
    cl_int errorCode = CL_SUCCESS;

    cl_mem_flags flags = CL_MEM_READ_WRITE;
    size_t size = 42;
    void* host_ptr = &size;
    
    struct clCreateBuffer_args testArgs = {
        g_Context,
        flags,
        size,
        host_ptr,
        &errorCode,
    };

    memset(&g_clCreateBuffer, 0xCC, sizeof(g_clCreateBuffer));

    cl_mem ret = clCreateBuffer(
        testArgs.context,
        testArgs.flags,
        testArgs.size,
        testArgs.host_ptr,
        testArgs.errcode_ret);

    EXPECT_EQ( ret, g_Mem );
    EXPECT_EQ( testArgs.context, g_clCreateBuffer.context );
    EXPECT_EQ( testArgs.flags, g_clCreateBuffer.flags );
    EXPECT_EQ( testArgs.size, g_clCreateBuffer.size );
    EXPECT_EQ( testArgs.host_ptr, g_clCreateBuffer.host_ptr );
    EXPECT_EQ( testArgs.errcode_ret, g_clCreateBuffer.errcode_ret );
}

// clCreateEventFromEGLSyncKHR
// clCreateEventFromGLsyncKHR?
// clCreateFromGLBuffer?
// clCreateFromGLTexture?
// clCreateFromGLTexture2D?
// clCreateFromGLTexture3D?
// clCreateFromGLRenderbuffer?
// clCreateFromEGLImageKHR
// clCreateFromD3D10BufferKHR?
// clCreateFromD3D10Texture2DKHR?
// clCreateFromD3D10Texture3DKHR?
// clCreateFromD3D11BufferKHR?
// clCreateFromD3D11Texture2DKHR?
// clCreateFromD3D11Texture3DKHR?
// clCreateFromDX9MediaSurfaceKHR?
// clCreateImage
// clCreateImage2D
// clCreateImage3D
// clCreatePipe
// clCreateProgramWithBinary
// clCreateProgramWithBuiltInKernels
// clCreateProgramWithIL
// clCreateProgramWithSource
// clCreateSampler
// clCreateSamplerWithProperties
// clCreateUserEvent
// clGetContextInfo
// clGetSupportedImageFormats
// clLinkProgram
// clReleaseContext
// clRetainContext
// clSetDefaultDeviceCommandQueue
// clSVMAlloc
// clSVMFree

