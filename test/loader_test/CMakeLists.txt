add_executable (icd_loader_test
    test_kernel.c
    main.c
    test_platforms.c
    icd_test_match.c
    test_program_objects.c
    test_sampler_objects.c
    test_buffer_object.c
    test_cl_runtime.c
    callbacks.c
    test_create_calls.c
    test_clgl.c
    test_image_objects.c )

if(WIN32)
    # Silence: warning C4996: 'fopen': This function or variable may be unsafe. Consider using fopen_s instead.
    target_compile_definitions (icd_loader_test PRIVATE _CRT_SECURE_NO_WARNINGS)
endif()

target_compile_definitions (icd_loader_test PRIVATE CL_TARGET_OPENCL_VERSION=220)
target_compile_definitions (icd_loader_test PRIVATE CL_USE_DEPRECATED_OPENCL_1_0_APIS)
target_compile_definitions (icd_loader_test PRIVATE CL_USE_DEPRECATED_OPENCL_1_1_APIS)
target_compile_definitions (icd_loader_test PRIVATE CL_USE_DEPRECATED_OPENCL_1_2_APIS)
target_compile_definitions (icd_loader_test PRIVATE CL_USE_DEPRECATED_OPENCL_2_0_APIS)
target_link_libraries (icd_loader_test OpenCL IcdLog)
