cmake_minimum_required(VERSION 3.15)
project(kmeans_cpp)

set(CMAKE_CXX_STANDARD 14)

add_executable(kmeans_cpp src/main.cpp src/utils.h src/KMeans.cpp src/KMeans.h src/Data.cpp src/Data.h)

target_include_directories(kmeans_cpp PUBLIC
        libs/eigen-master-01242020)