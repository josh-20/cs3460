cmake_minimum_required(VERSION 3.12)
set(project_name TypeAhead)
set(UNIT_TEST_RUNNER UnitTestRunner)

project(${project_name})

set(HEADER_FILES WordTree.hpp)
set(SOURCE_FILES WordTree.cpp)
set(UNIT_TEST_FILES TestWordTree.cpp)

add_executable(${project_name} ${SOURCE_FILES} ${HEADER_FILES} main.cpp)
add_executable(${UNIT_TEST_RUNNER} ${SOURCE_FILES} ${HEADER_FILES} ${UNIT_TEST_FILES})

set_property(TARGET ${project_name} PROPERTY CXX_STANDARD 20)
set_property(TARGET ${UNIT_TEST_RUNNER} PROPERTY CXX_STANDARD 20)


if (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    target_compile_options(${project_name} PRIVATE /W4 /permissive-)
    target_compile_options(${UNIT_TEST_RUNNER} PRIVATE /W4 /permissive-)

elseif (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    target_compile_options(${project_name} PRIVATE -Wall -Wextra -pedantic)
    target_compile_options(${UNIT_TEST_RUNNER} PRIVATE -Wall -Wextra -pedantic)
elseif (CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    target_compile_options(${project_name} PRIVATE -Wall -Wextra -pedantic)
endif()

find_program(CLANG_FORMAT "clang-format")
if (CLANG_FORMAT)
    message("clang found")
    unset(SOURCE_FILES_PATHS)
    foreach(SOURCE_FILE ${SOURCE_FILES} ${HEADER_FILES} ${UNIT_TEST_FILES} main.cpp)
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
include(FetchContent)
FetchContent_Declare(
	googletest
	GIT_REPOSITORY 	https://github.com/google/googletest.git
	GIT_TAG			release-1.11.0
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)


FetchContent_Declare(
    fmt
    GIT_REPOSITORY    https://github.com/fmtlib/fmt.git
    GIT_TAG           9.1.0
)
FetchContent_MakeAvailable(fmt)
target_link_libraries(${UNIT_TEST_RUNNER} gtest_main fmt::fmt)
target_link_libraries(${PROJECT_NAME} PRIVATE fmt::fmt)