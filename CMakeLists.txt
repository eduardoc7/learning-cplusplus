cmake_minimum_required(VERSION 3.21)
project(learningcplusplus)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic -Werror -std=c++17 -Wno-c++98-compat -Wno-padded -Wno-date-time -Wno-c++98-compat-pedantic -Wno-exit-time-destructors -Wno-global-constructors")

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_DEFAULT 17)
set(CXX17 ON)
set(CMAKE_CXX_EXTENSIONS Off)
set(CMAKE_C_EXTENSIONS Off)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include(CPack)

include(CTest)
enable_testing()
find_package(GTest REQUIRED)
include(GoogleTest)

# setando todos arquivos include
set(INCLUDE_DIRS
        "${CMAKE_CURRENT_SOURCE_DIR}/course/"
        "${CMAKE_CURRENT_SOURCE_DIR}/algorithms/"
)

include_directories(${INCLUDE_DIRS})

add_executable(${PROJECT_NAME} main.cpp course/basic-language/S1BasicCPlusPlus.cpp course/OO-programing/Car.cpp)

# Compiler-specific compile flags
if (${CMAKE_CXX_COMPILER_ID} STREQUAL "GNU")
    message(STATUS "Setting G++ flags")
    # G++
    set(COMPILE_FLAGS_CUSTOM -Wall -Werror -Wextra -O2 -std=c++17 -Wformat-security -Wconversion -Wsign-conversion)
    target_compile_options(${PROJECT_NAME} PRIVATE )
elseif(${CMAKE_CXX_COMPILER_ID} STREQUAL "MSVC")
    message(STATUS "Setting MSVC flags")
    # MSVC
    set(COMPILE_FLAGS_CUSTOM /EHsc /W2 /c)
elseif(${CMAKE_CXX_COMPILER_ID} STREQUAL "Clang")
    message(STATUS "Setting Clang flags")
    if ("${CMAKE_BUILD_TYPE}" STREQUAL "Debug")
        message("Setting clang-tidy flags")
        set(CMAKE_CXX_CLANG_TIDY "clang-tidy;-header-filter=${CMAKE_CURRENT_SOURCE_DIR}/src;--warnings-as-errors=\"*\";-extra-arg=-std=c++17;-checks=read*,modern*,hicpp*,performance*,-readability-magic-numbers,-hicpp-use-auto,-modernize-use-equals-default,-modernize-deprecated-headers,-readability-uppercase-literal-suffix;-export-fixes=clang-tidy-sugested-fixes.txt")
    endif()
    # CLANG
    set(COMPILE_FLAGS_CUSTOM -Weverything -Werror -Wno-date-time -Wno-disabled-macro-expansion -Wno-global-constructors -std=c++17 -Wno-c++98-compat -Wno-c++98-compat-pedantic -Wno-padded -Wno-exit-time-destructors)
endif()
target_compile_options(${PROJECT_NAME} PRIVATE ${COMPILE_FLAGS_CUSTOM})

add_subdirectory(${CMAKE_SOURCE_DIR}/tests)
