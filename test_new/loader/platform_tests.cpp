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

TEST(Platform, clGetPlatformIDs_numPlatforms) {
    cl_int errorCode = CL_SUCCESS;

    cl_uint numPlatforms = 0;
    errorCode = clGetPlatformIDs(
        0,
        nullptr,
        &numPlatforms);
    ASSERT_TRUE( errorCode == CL_SUCCESS || errorCode == CL_PLATFORM_NOT_FOUND_KHR )
        << "Where error code is: " << errorCode;
}

///////////////////////////////////////////////////////////////////////////////

TEST(Platform, clGetPlatformIDs) {
    cl_int errorCode = CL_SUCCESS;

    cl_uint numPlatforms = 0;
    errorCode = clGetPlatformIDs(
        0,
        nullptr,
        &numPlatforms);
    ASSERT_TRUE( errorCode == CL_SUCCESS || errorCode == CL_PLATFORM_NOT_FOUND_KHR )
        << "Where error code is: " << errorCode;

    if( numPlatforms )
    {
        std::vector<cl_platform_id> platforms;
        platforms.resize(numPlatforms);

        errorCode = clGetPlatformIDs(
            numPlatforms,
            platforms.data(),
            nullptr);
        ASSERT_EQ( errorCode, CL_SUCCESS );
        for(auto platform : platforms)
        {
            ASSERT_NE( platform, nullptr );
        }
    }
}

///////////////////////////////////////////////////////////////////////////////

TEST(Platform, clGetPlatformInfo) {
    int param;
    size_t param_value_size_ret;

    struct clGetPlatformInfo_args testArgs = {
        g_Platform,
        CL_PLATFORM_NAME,
        10,
        &param,
        &param_value_size_ret,
    };

    memset(&g_clGetPlatformInfo, 0xCC, sizeof(g_clGetPlatformInfo));

    cl_int errorCode = clGetPlatformInfo(
        testArgs.platform,
        testArgs.param_name,
        testArgs.param_value_size,
        testArgs.param_value,
        testArgs.param_value_size_ret );

    EXPECT_EQ( errorCode, CL_SUCCESS);
    EXPECT_EQ( testArgs.platform,               g_clGetPlatformInfo.platform );
    EXPECT_EQ( testArgs.param_name,             g_clGetPlatformInfo.param_name );
    EXPECT_EQ( testArgs.param_value_size,       g_clGetPlatformInfo.param_value_size );
    EXPECT_EQ( testArgs.param_value,            g_clGetPlatformInfo.param_value );
    EXPECT_EQ( testArgs.param_value_size_ret,   g_clGetPlatformInfo.param_value_size_ret );
}

// clGetDeviceIDs
// clCreateContextFromType
// clUnloadPlatformCompiler
// clGetExtensionFunctionAddressForPlatform
// clGetGLContextInfoKHR?
// clGetDeviceIDsFromD3D10KHR?
// clGetDeviceIDsFromDX9MediaAdapterKHR?
