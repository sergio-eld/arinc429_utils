cmake_minimum_required(VERSION 3.11.4 FATAL_ERROR)

project(arinc429 VERSION 0.0.1 LANGUAGES CXX C)

option(CLEAN_BUILD "Treat all warnings as errors" ON)
option(BUILD_TESTS "Build tests" ON)

if (MSVC)
    add_compile_options(/W4)
    # warnings as errors
    if (${CLEAN_BUILD})
        add_compile_options(/WX)
        #exclude deprecated
        if (NOT ${ALLOW_DEPRECATED})
            add_compile_options(-wd4996)
        endif()
    endif ()
else ()
    add_compile_options(-Wall -Wextra -pedantic)
    # warnings as errors
    if (${CLEAN_BUILD})
        add_compile_options(-Werror)
        # exclude deprecated
        if (${ALLOW_DEPRECATED})
            add_compile_options(-Wno-error=deprecated-declarations)
        endif ()
    endif ()
endif ()

add_library(arinc429 INTERFACE)
target_include_directories(arinc429
        INTERFACE
            $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
            $<INSTALL_INTERFACE:include>
        )

add_library(eld::arinc429 ALIAS arinc429)

get_directory_property(EXCLUDED EXCLUDE_FROM_ALL)

if (NOT EXCLUDED AND BUILD_TESTS)
    message(STATUS "Building tests for ${PROJECT_NAME}")
    enable_testing()
    add_subdirectory(test)
endif()

# TODO: installation

