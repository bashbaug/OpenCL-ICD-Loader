set (OPENCL_DRIVER_STUB_SOURCES cl.c cl_ext.c cl_gl.c icd.c)

if(WIN32)
    list (APPEND OPENCL_DRIVER_STUB_SOURCES driver_stub.def)
endif ()

add_library (OpenCLDriverStub SHARED ${OPENCL_DRIVER_STUB_SOURCES})

target_compile_definitions (OpenCLDriverStub PRIVATE CL_TARGET_OPENCL_VERSION=220)
target_compile_definitions (OpenCLDriverStub PRIVATE CL_USE_DEPRECATED_OPENCL_1_0_APIS)
target_compile_definitions (OpenCLDriverStub PRIVATE CL_USE_DEPRECATED_OPENCL_1_1_APIS)
target_compile_definitions (OpenCLDriverStub PRIVATE CL_USE_DEPRECATED_OPENCL_1_2_APIS)
target_compile_definitions (OpenCLDriverStub PRIVATE CL_USE_DEPRECATED_OPENCL_2_0_APIS)
target_link_libraries (OpenCLDriverStub IcdLog)
