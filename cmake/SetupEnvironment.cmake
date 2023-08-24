include_guard(GLOBAL)

message(STATUS "C compiler: ${CMAKE_C_COMPILER}")
message(STATUS "C++ compiler: ${CMAKE_CXX_COMPILER}")

set(CMAKE_MODULE_PATH
        ${CMAKE_MODULE_PATH}
        "${CMAKE_CURRENT_LIST_DIR}"
        "${CMAKE_BINARY_DIR}"
        "${CMAKE_BINARY_DIR}/cmake_generated"
        )

# set the C++ standard
set (CMAKE_EXPORT_COMPILE_COMMANDS ON)
if (NOT DEFINED CMAKE_CXX_STANDARD)
    set (CMAKE_CXX_STANDARD 17)
endif()
message(STATUS "C++ standard ${CMAKE_CXX_STANDARD}")
set (CMAKE_CXX_STANDARD_REQUIRED ON)
set (CMAKE_CXX_EXTENSIONS OFF)
set (CMAKE_VISIBILITY_INLINES_HIDDEN ON)
set (CMAKE_CXX_FLAGS "-fexceptions -Wall -Werror -Wextra -fsanitize=address,leak,undefined,signed-integer-overflow,null,alignment")
