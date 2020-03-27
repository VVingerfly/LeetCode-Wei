cmake_minimum_required(VERSION 3.1)

set(PROJECT_NAME LeetCode)
project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 11)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Release")
    message(STATUS "Build type not specified: defaulting to Release.")
endif(NOT CMAKE_BUILD_TYPE)
set(CMAKE_BUILD_TYPE ${CMAKE_BUILD_TYPE} CACHE STRING "")

#set(CMAKE_CONFIGURATION_TYPES "Release" CACHE STRING "" FORCE)
#set(CMAKE_BUILD_TYPE "Release")
#set(CMAKE_GENERATOR_PLATFORM "x64")
message(STATUS ${CMAKE_CONFIGURATION_TYPES})
message(STATUS ${CMAKE_BUILD_TYPE})
message(STATUS ${CMAKE_GENERATOR_PLATFORM})


if(CMAKE_SIZEOF_VOID_P EQUAL 8)
    if(CMAKE_BUILD_TYPE STREQUAL "Debug")
        message(STATUS "Build Config: x64 Debug")
    else()
        message(STATUS "Build Config: x64 Release")
    endif()
else(CMAKE_SIZEOF_VOID_P EQUAL 8)
    if(CMAKE_BUILD_TYPE STREQUAL "Debug")
        message(STATUS "Build Config: x86 Debug")
    else()
        message(STATUS "Build Config: x86 Release")
    endif()
endif(CMAKE_SIZEOF_VOID_P EQUAL 8)

# set cmake module path
list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)
list(APPEND CMAKE_MODULE_PATH /home/user/Libs/cmake)

set(HEADER_PATH ${PROJECT_SOURCE_DIR}/include)
set(LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin)

set(DATAPATH ${PROJECT_SOURCE_DIR}/data)

include_directories(${HEADER_PATH})
link_directories(${LIBRARY_OUTPUT_DIRECTORY})

add_definitions("-DDATA_PATH=\"${DATAPATH}/\"")


option(BUILD_TESTS  "Build tests"            ON)
option(BUILD_DOCS   "Build documentation"    ON)

add_subdirectory(src)
add_subdirectory(doc)

# add_library(my_lib my_lib.cpp)
# set_property(TARGET my_lib PROPERTY FOLDER "libs")

# add_executable(my_exe my_exe.cpp)
# set_property(TARGET my_exe PROPERTY FOLDER "test")


if(BUILD_TESTS)
    enable_testing()
    add_test(NAME test-Q1_TwoSum COMMAND $<TARGET_FILE:Q1_TwoSum>)
    add_test(NAME test-Q2_AddTwoNums COMMAND $<TARGET_FILE:Q2_AddTwoNums>)
    # add_test(NAME test-parallel-exec COMMAND $<TARGET_FILE:test-parallel-exec>)
endif()