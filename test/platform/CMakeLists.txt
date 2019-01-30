add_library (IcdLog SHARED icd_test_log.c)

if(WIN32)
    # Silence: warning C4996: 'fopen': This function or variable may be unsafe. Consider using fopen_s instead.
    target_compile_definitions (IcdLog PRIVATE _CRT_SECURE_NO_WARNINGS)
endif()
