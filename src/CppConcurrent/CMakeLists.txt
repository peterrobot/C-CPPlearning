cmake_minimum_required(VERSION 3.12)

project(CppConcurrent)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED true)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/chapter1)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/chapter3)

add_executable(test_${PROJECT_NAME} CppCon.cpp)

target_link_libraries(test_${PROJECT_NAME} CC_Chapter3)
