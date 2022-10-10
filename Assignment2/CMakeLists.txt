cmake_minimum_required(VERSION 3.12)
set(project_name RandDistributions)
project(${project_name})
add_executable(${project_name} Assignment2.cpp)
set_property(TARGET ${project_name} PROPERTY CXX_STANDARD 20)
set(SOURCE_FILES
Assignment2.cpp
)

if (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    target_compile_options(${project_name} PRIVATE /W4 /permissive-)
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    target_compile_options(${project_name} PRIVATE -Wall -Wextra -pedantic)
elseif (CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    target_compile_options(${project_name} PRIVATE -Wall -Wextra -pedantic)
endif()

find_program(CLANG_FORMAT "clang-format")
if (CLANG_FORMAT)
    message("clang found")
    unset(SOURCE_FILES_PATHS)
    foreach(SOURCE_FILE ${SOURCE_FILES})
        get_source_file_property(WHERE ${SOURCE_FILE} LOCATION)
        set(SOURCE_FILES_PATHS ${SOURCE_FILES_PATHS} ${WHERE})
    endforeach()

    add_custom_target(
        ClangFormat
        COMMAND ${CLANG_FORMAT}
        -i
        -style=file
        ${SOURCE_FILES_PATHS})
    add_dependencies(${project_name} ClangFormat)
endif()