cmake_minimum_required(VERSION 3.24)

project(sprint1 CXX)

file(GLOB_RECURSE SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/**/*.cpp)

file(GLOB_RECURSE UNIT_TEST_SOURCES
        ${CMAKE_CURRENT_SOURCE_DIR}/**/*test.cpp
        )

list(REMOVE_ITEM SOURCES ${UNIT_TEST_SOURCES})

message(STATUS "Sprint1 sources=${SOURCES}")

message(STATUS "Sprint1 tests=${UNIT_TEST_SOURCES}")

add_library(${PROJECT_NAME} STATIC ${SOURCES})

set(SPRINT1_UNITTEST ${PROJECT_NAME}_unittest)

add_executable(${SPRINT1_UNITTEST} ${UNIT_TEST_SOURCES})

target_include_directories(
        ${SPRINT1_UNITTEST}
        PRIVATE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
)

target_link_libraries(
        ${SPRINT1_UNITTEST}
        PRIVATE
        ${PROJECT_NAME}
        gtest_main
)

add_google_tests(${SPRINT1_UNITTEST})

