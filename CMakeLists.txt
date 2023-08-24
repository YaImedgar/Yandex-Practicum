cmake_minimum_required(VERSION 3.23)
cmake_policy(SET CMP0025 NEW)
if(CMAKE_VERSION VERSION_GREATER_EQUAL "3.15")
    cmake_policy(SET CMP0093 NEW)
endif()
set(CMAKE_POLICY_DEFAULT_CMP0063 NEW)
set(CMAKE_POLICY_DEFAULT_CMP0069 NEW)

project(YandexPracticum)

include(cmake/SetupEnvironment.cmake)
include(AddGoogleTests)
include(SetupGTest)

add_subdirectory(algorithms)
