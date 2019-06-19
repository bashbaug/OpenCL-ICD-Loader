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

#include "icd_dispatch.h"
#include "api.h"

static KHRicdVendorDispatch g_sDispatch =
{
    recclGetPlatformIDs,
    recclGetPlatformInfo,
    recclGetDeviceIDs,
    recclGetDeviceInfo,
    recclCreateContext,
    recclCreateContextFromType,
    recclRetainContext,
    recclReleaseContext,
    recclGetContextInfo,
    recclCreateCommandQueue,
    recclRetainCommandQueue,
    recclReleaseCommandQueue,
    recclGetCommandQueueInfo,
    recclSetCommandQueueProperty,
    recclCreateBuffer,
    recclCreateImage2D,
    recclCreateImage3D,
    recclRetainMemObject,
    recclReleaseMemObject,
    recclGetSupportedImageFormats,
    recclGetMemObjectInfo,
    recclGetImageInfo,
    recclCreateSampler,
    recclRetainSampler,
    recclReleaseSampler,
    recclGetSamplerInfo,
    recclCreateProgramWithSource,
    recclCreateProgramWithBinary,
    recclRetainProgram,
    recclReleaseProgram,
    recclBuildProgram,
    recclUnloadCompiler,
    recclGetProgramInfo,
    recclGetProgramBuildInfo,
    recclCreateKernel,
    recclCreateKernelsInProgram,
    recclRetainKernel,
    recclReleaseKernel,
    recclSetKernelArg,
    recclGetKernelInfo,
    recclGetKernelWorkGroupInfo,
    recclWaitForEvents,
    recclGetEventInfo,
    recclRetainEvent,
    recclReleaseEvent,
    recclGetEventProfilingInfo,
    recclFlush,
    recclFinish,
    recclEnqueueReadBuffer,
    recclEnqueueWriteBuffer,
    recclEnqueueCopyBuffer,
    recclEnqueueReadImage,
    recclEnqueueWriteImage,
    recclEnqueueCopyImage,
    recclEnqueueCopyImageToBuffer,
    recclEnqueueCopyBufferToImage,
    recclEnqueueMapBuffer,
    recclEnqueueMapImage,
    recclEnqueueUnmapMemObject,
    recclEnqueueNDRangeKernel,
    recclEnqueueTask,
    recclEnqueueNativeKernel,
    recclEnqueueMarker,
    recclEnqueueWaitForEvents,
    recclEnqueueBarrier,
    recclGetExtensionFunctionAddress,
    nullptr, //recclCreateFromGLBuffer,
    nullptr, //recclCreateFromGLTexture2D,
    nullptr, //recclCreateFromGLTexture3D,
    nullptr, //recclCreateFromGLRenderbuffer,
    nullptr, //recclGetGLObjectInfo,
    nullptr, //recclGetGLTextureInfo,
    nullptr, //recclEnqueueAcquireGLObjects,
    nullptr, //recclEnqueueReleaseGLObjects,
    nullptr, //recclGetGLContextInfoKHR,

    nullptr, //recclGetDeviceIDsFromD3D10KHR,
    nullptr, //recclCreateFromD3D10BufferKHR,
    nullptr, //recclCreateFromD3D10Texture2DKHR,
    nullptr, //recclCreateFromD3D10Texture3DKHR,
    nullptr, //recclEnqueueAcquireD3D10ObjectsKHR,
    nullptr, //recclEnqueueReleaseD3D10ObjectsKHR,

    recclSetEventCallback,
    recclCreateSubBuffer,
    recclSetMemObjectDestructorCallback,
    recclCreateUserEvent,
    recclSetUserEventStatus,
    recclEnqueueReadBufferRect,
    recclEnqueueWriteBufferRect,
    recclEnqueueCopyBufferRect,

    nullptr, //recclCreateSubDevicesEXT,
    recclRetainDevice,     // clRetainDeviceEXT
    recclReleaseDevice,    // clReleaseDeviceEXT

    nullptr, //recclCreateEventFromGLsyncKHR,

    recclCreateSubDevices,
    recclRetainDevice,
    recclReleaseDevice,
    recclCreateImage,
    recclCreateProgramWithBuiltInKernels,
    recclCompileProgram,
    recclLinkProgram,
    recclUnloadPlatformCompiler,
    recclGetKernelArgInfo,
    recclEnqueueFillBuffer,
    recclEnqueueFillImage,
    recclEnqueueMigrateMemObjects,
    recclEnqueueMarkerWithWaitList,
    recclEnqueueBarrierWithWaitList,
    recclGetExtensionFunctionAddressForPlatform,
    nullptr, //recclCreateFromGLTexture,

    nullptr, //recclGetDeviceIDsFromD3D11KHR,
    nullptr, //recclCreateFromD3D11BufferKHR,
    nullptr, //recclCreateFromD3D11Texture2DKHR,
    nullptr, //recclCreateFromD3D11Texture3DKHR,
    nullptr, //recclCreateFromDX9MediaSurfaceKHR,
    nullptr, //recclEnqueueAcquireD3D11ObjectsKHR,
    nullptr, //recclEnqueueReleaseD3D11ObjectsKHR,

    nullptr, //recclGetDeviceIDsFromDX9MediaAdapterKHR,
    nullptr, //recclEnqueueAcquireDX9MediaSurfacesKHR,
    nullptr, //recclEnqueueReleaseDX9MediaSurfacesKHR,

    nullptr, //recclCreateFromEGLImageKHR,
    nullptr, //recclEnqueueAcquireEGLObjectsKHR,
    nullptr, //recclEnqueueReleaseEGLObjectsKHR,

    nullptr, //recclCreateEventFromEGLSyncKHR,

    recclCreateCommandQueueWithProperties,
    recclCreatePipe,
    recclGetPipeInfo,
    recclSVMAlloc,
    recclSVMFree,
    recclEnqueueSVMFree,
    recclEnqueueSVMMemcpy,
    recclEnqueueSVMMemFill,
    recclEnqueueSVMMap,
    recclEnqueueSVMUnmap,
    recclCreateSamplerWithProperties,
    recclSetKernelArgSVMPointer,
    recclSetKernelExecInfo,

    nullptr, //recclGetKernelSubGroupInfoKHR,

    recclCloneKernel,
    recclCreateProgramWithIL,
    recclEnqueueSVMMigrateMem,
    recclGetDeviceAndHostTimer,
    recclGetHostTimer,
    recclGetKernelSubGroupInfo,
    recclSetDefaultDeviceCommandQueue,

    recclSetProgramReleaseCallback,
    recclSetProgramSpecializationConstant,
};

// Helper macro for making objects of the specified type:
#define MAKE_OBJECT( _type, _name ) \
    static struct _##_type _s##_name   { &g_sDispatch };   \
    _type _name = &_s##_name;

MAKE_OBJECT( cl_platform_id,    g_Platform      );
MAKE_OBJECT( cl_device_id,      g_Device        );
MAKE_OBJECT( cl_context,        g_Context       );
MAKE_OBJECT( cl_command_queue,  g_CommandQueue  );
MAKE_OBJECT( cl_mem,            g_Mem           );
MAKE_OBJECT( cl_program,        g_Program       );
MAKE_OBJECT( cl_kernel,         g_Kernel        );
MAKE_OBJECT( cl_event,          g_Event         );
MAKE_OBJECT( cl_sampler,        g_Sampler       );
