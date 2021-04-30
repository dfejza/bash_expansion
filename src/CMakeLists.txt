find_package(fmt REQUIRED)

add_library(cmake_brace_expansion_lib
    "../include/braceexpansion.h"
    braceexpansion.cpp)

add_library(cmake_brace_expansion::lib ALIAS cmake_brace_expansion_lib)
target_link_libraries(cmake_brace_expansion_lib
        PUBLIC cmake_brace_expansion::compiler_options fmt::fmt)
target_include_directories(cmake_brace_expansion_lib PUBLIC "${PROJECT_SOURCE_DIR}/include")

if(${BP_BUILD_TESTS_COVERAGE})
    target_compile_options(cmake_brace_expansion_lib PUBLIC -fprofile-arcs -ftest-coverage)
    target_link_libraries(cmake_brace_expansion_lib PUBLIC gcov)
endif()

add_executable(cmake_brace_expansion_app "main.cpp")
target_link_libraries(cmake_brace_expansion_app PRIVATE cmake_brace_expansion::lib)
