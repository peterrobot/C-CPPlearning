cmake_minimum_required (VERSION 3.8)

# project name
project(FromAsmToC-Cpp)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/Chapter_1)

add_executable(test_${PROJECT_NAME} .//FaTc.cpp)

target_link_libraries(test_${PROJECT_NAME} AC_Chapter_1)