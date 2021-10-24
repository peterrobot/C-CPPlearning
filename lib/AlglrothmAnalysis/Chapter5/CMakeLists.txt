project(AA_Chapter5)

aux_source_directory(${PROJECT_SOURCE_DIR}/src DIR_LIB_SRCS)
add_library(${PROJECT_NAME} STATIC ${DIR_LIB_SRCS})
add_library(sub::Chapter5 ALIAS ${PROJECT_NAME})

target_include_directories(${PROJECT_NAME}
    PUBLIC ${PROJECT_SOURCE_DIR}/include
)