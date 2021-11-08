cmake_minimum_required(VERSION 3.8)

project(AlgorithmAnalysis LANGUAGES C CXX)

########## Set some variables ##########

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED Ture)

########## Add source ##########

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/Chapter1)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/Chapter2)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/Chapter3)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/Chapter4)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/Chapter6)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/Chapter7)

add_executable(test_${PROJECT_NAME} AlgorithmAnalysis.cpp)
