cmake_minimum_required (VERSION 3.8)

# project name
project (C++Primer)

# c++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# add subdirectories
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/Chapter_1)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/Chapter_2)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/Chapter_8)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/Chapter_9)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/Chapter_10)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/Chapter_11)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/Chapter_12)

add_executable(test_${PROJECT_NAME} C++Primer.cpp)

target_link_libraries(test_${PROJECT_NAME} CP_Chapter_2)