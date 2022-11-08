cmake_minimum_required(VERSION 3.12)
set(project_name ConwaysLife)

project(${project_name})

set(HEADER_FILES LifeSimulator.hpp Pattern.hpp PatternAcorn.hpp PatternBlinker.hpp PatternBlock.hpp PatternGlider.hpp PatternGosperGliderGun.hpp RendererConsole.hpp Renderer.hpp )
set(SOURCE_FILES LifeSimulator.cpp PatternAcorn.cpp PatternBlinker.cpp PatternBlock.cpp PatternGlider.cpp PatternGosperGliderGun.cpp RendererConsole.cpp)

add_executable(${project_name} ${SOURCE_FILES} ${HEADER_FILES} main.cpp)
set_property(TARGET ${project_name} PROPERTY CXX_STANDARD 20)


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
    foreach(SOURCE_FILE ${SOURCE_FILES} ${HEADER_FILES} main.cpp)
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