function(Require_x64 target)
    if(CMAKE_SIZEOF_VOID_P EQUAL 8)
        message("# 64bit Checked")
    else()
        message(FATAL_ERROR "# the project needs to be configed in x64")
    endif()
endfunction()