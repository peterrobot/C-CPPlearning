project(CC_Chapter1)

aux_source_directory(${PROJECT_SOURCE_DIR}/src DIR_LIB_SRC)
add_library(${PROJECT_NAME} ${DIR_LIB_SRC})

target_include_directories( ${PROJECT_NAME}
    PUBLIC ${PROJECT_SOURCE_DIR}/include
)