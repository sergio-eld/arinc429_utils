cmake_minimum_required(VERSION 3.11.4 FATAL_ERROR)

project(arinc429 VERSION 0.0.1 LANGUAGES CXX C)

option(BUILD_TESTS "Build tests" ON)

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

