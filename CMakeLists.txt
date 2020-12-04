cmake_minimum_required(VERSION 3.12)

project("gambian-pouched-rat")
set(CMAKE_SYSTEM_NAME Windows)
#set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_VERBOSE_MAKEFILE true)

# x64 Tool chain preferences
if(UNIX) # Don't have to specified the compiler for Windows if you have Visual Studio
    set(TOOLCHAIN_PATH 	   "/usr/bin/")
    set(TOOLCHAIN_PREFIX   "${TOOLCHAIN_PATH}x86_64-w64-mingw32")
    set(CMAKE_C_COMPILER   "${TOOLCHAIN_PREFIX}-gcc")
    set(CMAKE_CXX_COMPILER "${TOOLCHAIN_PREFIX}-g++")	
endif()

# binary preferences
set(PROJECT_VERSION_MAJOR 1)
set(PROJECT_VERSION_MINOR 0)
set(BINARY64 "${CMAKE_PROJECT_NAME}-${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}-x64.exe")

set(CMAKE_SHARED_LIBRARY_LINK_C_FLAGS "")
set(CMAKE_SHARED_LIBRARY_LINK_CXX_FLAGS "")

set(CMAKE_SOURCE_DIR src/)
include_directories(include)

add_executable(${BINARY64} ${CMAKE_SOURCE_DIR}main.cpp)

