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

# This code was heavily borrowed from SPIRV-Tools:

include (CTest)
if (BUILD_TESTING)
  # Find gmock if we can. If it's not already configured, then try finding
  # it in external/googletest.
  if (TARGET gmock)
    message(STATUS "Google Mock already configured")
  else()
    set(GMOCK_DIR ${CMAKE_CURRENT_SOURCE_DIR}/googletest/googlemock)
    if(EXISTS ${GMOCK_DIR})
      if(MSVC)
        # Our tests use ::testing::Combine.  Work around a compiler
        # detection problem in googletest, where that template is
        # accidentally disabled for VS 2017.
        # See https://github.com/google/googletest/issues/1352
        add_definitions(-DGTEST_HAS_COMBINE=1)
      endif()
      if(WIN32)
        option(gtest_force_shared_crt
          "Use shared (DLL) run-time lib even when Google Test is built as static lib."
          ON)
      endif()
      add_subdirectory(${GMOCK_DIR} EXCLUDE_FROM_ALL)
    endif()
  endif()
  if (TARGET gmock)
    set(GTEST_TARGETS
      gtest
      gtest_main
      gmock
      gmock_main
    )
    foreach(target ${GTEST_TARGETS})
      set_property(TARGET ${target} PROPERTY FOLDER GoogleTest)
    endforeach()
  endif()

endif()
