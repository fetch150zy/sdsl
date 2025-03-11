# cmake最低版本要求
cmake_minimum_required(VERSION 3.20 FATAL_ERROR)

# 项目名版本信息及语言
project(DataStructure VERSION 0.1 LANGUAGES C CXX)
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
# cmake global flag
set(BUILD_SHARED_LIBS OFF)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

# 检测操作系统
if(CMAKE_SYSTEM_NAME STREQUAL "Linux")
    message(STATUS "Configuring on/for Linux")
elseif(CMAKE_SYSTEM_NAME STREQUAL "Darwin")
    message(STATUS "Configuring on/for macOS")
elseif(CMAKE_SYSTEM_NAME STREQUAL "Windows")
    message(STATUS "Configuring on/for Windows")
elseif(CMAKE_SYSTEM_NAME STREQUAL "AIX")
    message(STATUS "Configuring on/for IBM AIX")
else()
    message(STATUS "Configuring on/for ${CMAKE_SYSTEM_NAME}")
endif()

# 构建类型
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release CACHE STRING "Build type" FORCE) # release版本
    # set(CMAKE_BUILD_TYPE Debug CACHE STRING "Build type" FORCE) # debug版本
endif()
message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")
# 关于一些flag的信息
message(STATUS "Is the C compiler loaded? ${CMAKE_C_COMPILER_LOADED}")
if(CMAKE_C_COMPILER_LOADED)
    message(STATUS "C flags, Debug configuration: ${CMAKE_C_FLAGS_DEBUG}")
    message(STATUS "C flags, Release configuration: ${CMAKE_C_FLAGS_RELEASE}")
    message(STATUS "C flags, Release configuration with Debug info: ${CMAKE_C_FLAGS_RELWITHDEBINFO}")
    message(STATUS "C flags, minimal Release configuration: ${CMAKE_C_FLAGS_MINSIZEREL}")
endif()

# Check测试相关
include(CheckCSourceCompiles)
include(CheckCSourceRuns)
include(CheckFunctionExists)
include(CheckIncludeFile)
include(CheckIncludeFiles)
include(CheckLibraryExists)
include(CheckSymbolExists)
include(CheckTypeSize)

include(CTest)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/cmake/config.h.in
    ${CMAKE_CURRENT_BINARY_DIR}/config.h)
include_directories(BEFORE ${CMAKE_CURRENT_BINARY_DIR})
add_definitions(-DHAVE_CONFIG_H)
set(CONFIG_HEADER ${CMAKE_CURRENT_BINARY_DIR}/config.h)

option(USE_SEQ_LIST "use sequence list" ON)
option(USE_LINK_LIST "use link list" OFF)
option(USE_SEQ_STACK "use sequence stack" ON)
option(USE_LINK_STACK "use link stack" OFF)
option(USE_SEQ_QUEUE "use sequece queue" ON)
option(USE_LINK_QUEUE "use link queue" OFF)
option(USE_STRING "use string" OFF)
option(USE_BIN_TREE "use binary tree" OFF)
option(USE_TH_BIN_TREE "use threaded binary tree" OFF)

set(op_list
    USE_SEQ_LIST
    USE_LINK_LIST
    USE_SEQ_STACK
    USE_LINK_STACK
    USE_SEQ_QUEUE
    USE_LINK_QUEUE
    USE_STRING
    USE_BIN_TREE
    USE_TH_BIN_TREE
)

add_subdirectory(${CMAKE_SOURCE_DIR}/src)


add_subdirectory(${CMAKE_SOURCE_DIR}/test)


