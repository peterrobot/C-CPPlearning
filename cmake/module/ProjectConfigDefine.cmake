if(${CMAKE_SYSTEM_NAME} MATCHES "Windows")
    set(WINDOWS TRUE)
    set(PLATFORM_FOLDER win64)
else()
    message(FATAL_ERROR "Only windows is supported")
endif()

# organize the components into a hierarchy of folders
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

if(CMAKE_GENERATOR STREQUAL Visual)
    set(VS TRUE)
endif()
message(STATUS "CMAKE_GENERATOR: ${CMAKE_GENERATOR}")

# set c/c++ standard
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED TRUE)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

if(WINDOWS)
    if(MSVC)
        if(${MSVC_VERSION} EQUAL 1900 OR ${MSVC_VERSION} GREATER 1900)
            message(STATUS "using Windows MSVC generate project, MSVC_VERSION:${MSVC_VERSION}")
        endif()
    else()
        message(FATAL_ERROR "please use MSVC greater than 19")
    endif()
endif()

function(use_project_compile_define target)

endfunction()

function(use_project_compile_option target)
    if(MSVC)
        target_compile_options(${target} PUBLIC /MP)
    endif()
endfunction()