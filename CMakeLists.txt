cmake_minimum_required(VERSION 3.13)
include(CMakePrintHelpers)
include(cmake/ColorMessage.cmake)
include(cmake/CPM.cmake)

project(BitFlagExample VERSION 0.1.0)

add_executable(BitFlagExample)

target_sources(BitFlagExample
    PRIVATE
    src/input.cpp
    src/flags.cpp
    src/flags.hpp
    src/bitflags.hpp
    src/utils.hpp
    src/utils.cpp)

set_target_properties(BitFlagExample PROPERTIES
    CXX_STANDARD 23
    CXX_STANDARD_REQUIRED YES
)

# Add options for build type
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

# Set the default build type to Release if not specified
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE RELEASE CACHE STRING "Choose the type of build (DEBUG or RELEASE)" FORCE)
endif()

colormsg(HIGREEN "CMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}")

CPMAddPackage("gh:fmtlib/fmt#11.1.1")

if(fmt_ADDED)
    colormsg(HIGREEN "fmt found")
    target_link_libraries(BitFlagExample PRIVATE fmt)
    colormsg(HIGREEN "fmt linked")
else()
    colormsg(HIRED "fmt not found")
endif()

# Add the magic_enum library
CPMAddPackage("gh:Neargye/magic_enum#v0.9.7")

if(magic_enum_ADDED)
    colormsg(HIGREEN "magic_enum found")

    # Some libraries need to be built before they can be used
    # add_library(magic_enum INTERFACE IMPORTED)
    # target_include_directories(magic_enum INTERFACE "${magic_enumSOURCE_DIR}/include")
    target_link_libraries(BitFlagExample PRIVATE magic_enum)
    colormsg(HIGREEN "magic_enum linked")
else()
    colormsg(HIRED "magic_enum not found")
endif()
