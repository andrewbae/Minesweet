cmake_minimum_required(VERSION 3.12)

project("mine-plow")
set(CMAKE_SYSTEM_NAME Windows)
#set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_VERBOSE_MAKEFILE true)

# binary preferences
set(PROJECT_VERSION_MAJOR 1)
set(PROJECT_VERSION_MINOR 0)
set(BINARY64 "${CMAKE_PROJECT_NAME}-${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}-x64.exe")

set(CMAKE_SHARED_LIBRARY_LINK_C_FLAGS "")
set(CMAKE_SHARED_LIBRARY_LINK_CXX_FLAGS "")

set(CMAKE_SOURCE_DIR src/)
include_directories(include)

add_executable(${BINARY64} ${CMAKE_SOURCE_DIR}main.cpp)

