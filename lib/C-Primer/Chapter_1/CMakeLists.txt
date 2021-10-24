# initialize
project(CP_Chapter1)

aux_source_directory(. DIR_LIB_SRC)
add_library(${PROJECT_NAME} ${DIR_LIB_SRC})