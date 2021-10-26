project (AA_Chapter2)

aux_source_directory(${PROJECT_SOURCE_DIR} DIR_LIB_SRCS)
add_library(${PROJECT_NAME} STATIC ${DIR_LIB_SRCS})