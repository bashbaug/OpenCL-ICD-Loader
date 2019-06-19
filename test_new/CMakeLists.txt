# Copyright (c) 2019 The Khronos Group Inc.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

# Add an OpenCL ICD loader unit test. Signature:
#   add_OpenCLICDLoader_unittest(
#     TARGET target_name
#     SRCS   src_file.h src_file.cpp
#     LIBS   lib1 lib2
#   )

include (CTest)

if (BUILD_TESTING)
  if (TARGET gmock_main)
    message(STATUS "Found Google Mock, building tests.")
  else()
    message(STATUS "Did not find googletest, tests will not be built. "
      "To enable tests place googletest in '<spirv-dir>/external/googletest'.")
  endif()
endif()

set(OPENCL_ICD_LOADER_TEST_FOLDER "OpenCLICDLoader-Tests")

function(add_OpenCLICDLoader_unittest)
  if (BUILD_TESTING AND TARGET gmock_main)
    set(one_value_args TARGET)
    set(multi_value_args SRCS LIBS)
    cmake_parse_arguments(
      ARG "" "${one_value_args}" "${multi_value_args}" ${ARGN})
    set(target test_${ARG_TARGET})
    add_executable(${target} ${ARG_SRCS})
    target_include_directories(${target} PRIVATE
      ${gtest_SOURCE_DIR}/include
      ${gmock_SOURCE_DIR}/include
      ../loader
      ${OPENCL_ICD_LOADER_HEADERS_DIR}
    )
    target_link_libraries(${target} PRIVATE ${ARG_LIBS})
    target_link_libraries(${target} PRIVATE gmock_main)
    add_test(NAME opencl_icd_loader-${target} COMMAND ${target})
    set_property(TARGET ${target} PROPERTY FOLDER ${OPENCL_ICD_LOADER_TEST_FOLDER})
  endif()
endfunction()

add_subdirectory(recorder)
set_property(TARGET RecorderICD PROPERTY FOLDER ${OPENCL_ICD_LOADER_TEST_FOLDER})

add_OpenCLICDLoader_unittest(
    TARGET icd_loader_apis
    SRCS
    loader/platform_tests.cpp
    loader/context_tests.cpp
    LIBS OpenCL RecorderICD )

add_custom_target(
    check_icd_loader_tests
    COMMAND ${CMAKE_COMMAND} -E echo Running: ${CMAKE_CTEST_COMMAND} -C $<CONFIG> -V 
    COMMAND ${CMAKE_CTEST_COMMAND} -C $<CONFIG> -V )
set_property(TARGET check_icd_loader_tests PROPERTY FOLDER ${OPENCL_ICD_LOADER_TEST_FOLDER})
