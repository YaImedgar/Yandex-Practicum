cmake_minimum_required(VERSION 3.23)

project(YandexPracticum)

include(cmake/SetupEnvironment.cmake)
include(AddGoogleTests)
include(SetupGTest)

add_subdirectory(src/courses/algorithms)
