cmake_minimum_required(VERSION 2.8)
project(rotate)

find_package(Eigen3 REQUIRED)
include_directories(${EIGEN3_INCLUDE_DIRS})

add_executable(rotate rotate.cpp)