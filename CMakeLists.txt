cmake_minimum_required(VERSION 3.0)

project(Plompt)
set(VERSION_MAJOR 0)
set(VERSION_MINOR 2)
set(VERSION_PATCH 0)

# Output directories
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Looking for a C++11 compiler
include(CheckCXXCompilerFlag)
check_cxx_compiler_flag("-std=c++11" IS_STDCXX11)
if (NOT IS_STDCXX11)
    message(FATAL_ERROR "Need a C++11 compiler")
endif()

# Default compiler flags
set(CMAKE_CXX_FLAGS "-std=c++11 -Wall -Werror -pedantic")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -ggdb")

# Option
option(BUILD_SHARED_LIBS "Build shared library" ON)

# Set a default build type if none was specified
if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
  message(STATUS "Setting build type to 'Debug' as none was specified.")
  set(CMAKE_BUILD_TYPE Debug CACHE STRING "Choose the type of build." FORCE)
  # Set the possible values of build type for cmake-gui
  set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "Debug" "Release"
    "MinSizeRel" "RelWithDebInfo")
endif()

# Config file
configure_file(${CMAKE_SOURCE_DIR}/src/config.h.in ${CMAKE_BINARY_DIR}/config.h)

include_directories(${CMAKE_BINARY_DIR})
include_directories(${CMAKE_SOURCE_DIR}/src/)
include_directories(${CMAKE_SOURCE_DIR}/ext/include/)

file(GLOB_RECURSE source_files ${CMAKE_SOURCE_DIR}/src/*)
add_executable(plompt ${source_files})
target_link_libraries(plompt dl)

link_directories(${CMAKE_SOURCE_DIR}/ext/lib/)
target_link_libraries(plompt config++)
