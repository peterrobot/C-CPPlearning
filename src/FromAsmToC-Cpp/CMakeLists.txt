cmake_minimum_required (VERSION 3.8)

# project name
project(FromAsmToC-Cpp LANGUAGES C)

# set c standard
set(CMAKE_C_STANDARD 99)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/Section_1)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/Section_2)

add_executable(test_${PROJECT_NAME} .//FaTc.c)

target_link_libraries(test_${PROJECT_NAME} AC_Section_1)
target_link_libraries(test_${PROJECT_NAME} AC_Section_2)