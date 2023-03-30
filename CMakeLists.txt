if(NOT DEFINED CMAKE_INSTALL_PREFIX)
    set(CMAKE_INSTALL_PREFIX "${CMAKE_BINARY_DIR}/install" CACHE PATH "Installation Directory")
endif()
message(STATUS "CMAKE_INSTALL_PREFIX = ${CMAKE_INSTALL_PREFIX}")

cmake_minimum_required(VERSION 3.20)

# set cxx compiler
set(CMAKE_C_COMPILER "/usr/bin/clang")
set(CMAKE_CXX_COMPILER "/usr/bin/clang++")

project(cpp_project_template)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF) 
set(CMAKE_BUILD_TYPE Debug)

set(CMAKE_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/include")
set(PROJECT_INCLUDE_DIR "${PROJECT_SOURCE_DIR}/include")
set(CMAKE_LIB_DIR "${PROJECT_SOURCE_DIR}/src")

message(STATUS "PROJECT_NAME:${PROJECT_NAME}")
message(STATUS "CMAKE_SOURCE_DIR: ${CMAKE_SOURCE_DIR}")

include_directories(${PROJECT_INCLUDE_DIR})
add_subdirectory(src bin)
add_subdirectory(test)