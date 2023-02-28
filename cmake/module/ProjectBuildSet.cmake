set(CMAKE_DEBUG_TARGET_PROPERTIES

)

include(ProjectConfigDefine)
include(ProjectBuildHelper)

set(PRJ_BIN_ROOT ${CMAKE_CURRENT_SOURCE_DIR}/lib/${PLATFORM_FOLDER})
set(PRJ_RT_ROOT ${CMAKE_CURRENT_SOURCE_DIR}/bin/${PLATFORM_FOLDER})

option(IS_BUILD_DLL "build dll for project" FALSE)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG ${PRJ_BIN_ROOT}/DEBUG)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG ${PRJ_BIN_ROOT}/DEBUG)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${PRJ_RT_ROOT}/DEBUG)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE ${PRJ_BIN_ROOT}/RELEASE)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_RELEASE ${PRJ_BIN_ROOT}/RELEASE)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${PRJ_RT_ROOT}/RELEASE)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_MINSIZEREL ${PRJ_BIN_ROOT}/MINSIZEREL)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_MINSIZEREL ${PRJ_BIN_ROOT}/MINSIZEREL)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_MINSIZEREL ${PRJ_RT_ROOT}/MINSIZEREL)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELWITHDEBINFO ${PRJ_BIN_ROOT}/RELWITHDEBINFO)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_RELWITHDEBINFO ${PRJ_BIN_ROOT}/RELWITHDEBINFO)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELWITHDEBINFO ${PRJ_RT_ROOT}/RELWITHDEBINFO)