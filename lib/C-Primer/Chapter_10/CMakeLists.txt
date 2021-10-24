project(CP_Chapter_10)

aux_source_directory(src DIR_LIB_SRC)
add_library(${PROJECT_NAME} ${DIR_LIB_SRC})

target_include_directories( ${PROJECT_NAME}
    PUBLIC ${PROJECT_SOURCE_DIR}/include
)