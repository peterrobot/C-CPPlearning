# version require
cmake_minimum_required (VERSION 3.8)

# project name
project(CppNow)

# set c standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/Alignment)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/C11LibraryDesign)

add_executable(test_${PROJECT_NAME} .//CppNow.cpp)

target_link_libraries(test_${PROJECT_NAME} Alignment)
target_link_libraries(test_${PROJECT_NAME} CLibDesign)