cmake_minimum_required(VERSION 3.8)

project(C-CPPlearning)

########## Message some information #############

message(STATUS "CMake version: ${CMAKE_VERSION}")

########## Set some variables ##########

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED Ture)

########## Add source ##########
add_subdirectory(${PROJECT_SOURCE_DIR}/lib)

add_executable(${PROJECT_NAME} main.cpp)

target_include_directories( ${PROJECT_NAME}
    PRIVATE ${PROJECT_SOURCE_DIR}/include
)