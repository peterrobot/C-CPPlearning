cmake_minimum_required(VERSION 3.8)

# project name
project(CPP-ProgrammingLanguage)

# c++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# add subdirectories
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/Part_2)

# specific executable
add_executable(test_${PROJECT_NAME} CPP-PL.cpp)

target_link_libraries(test_${PROJECT_NAME} PL-Chapter2)