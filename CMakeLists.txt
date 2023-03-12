cmake_minimum_required(VERSION 3.8)

project(C-CPPlearning)

########## Message some information #############

message(STATUS "CMake version: ${CMAKE_VERSION}")

########## Set some variables ##########

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED Ture)

set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake/module)

include(PreventInSourceBuilds)
include(ProjectBuildSet)

########## Add source ##########
add_subdirectory(${PROJECT_SOURCE_DIR}/src)

########## specific executable ##########
add_executable(${PROJECT_NAME} main.cpp)

target_include_directories( ${PROJECT_NAME}
    PRIVATE ${PROJECT_SOURCE_DIR}/include
)