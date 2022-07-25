cmake_minimum_required(VERSION 3.16)
project(learningcplusplus)

# Setting custom tags by each compiler
if (${CMAKE_CXX_COMPILER_ID} STREQUAL "GNU")
    message(STATUS "Setting G++ flags")
    set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic -Werror -std=c++17 -Wno-exit-time-destructors -Wno-global-constructors")
    set(COMPILE_FLAGS_CUSTOM -Wall -Werror -Wextra -O2 -std=c++17 -Wformat-security -Wconversion -Wsign-conversion)
elseif(${CMAKE_CXX_COMPILER_ID} STREQUAL "Clang")
    message(STATUS "Setting Clang flags")
    set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic -Werror -std=c++17 -Wno-c++98-compat -Wno-padded -Wno-date-time -Wno-c++98-compat-pedantic -Wno-exit-time-destructors -Wno-global-constructors")
    set(COMPILE_FLAGS_CUSTOM -Weverything -Werror -Wno-date-time -Wno-disabled-macro-expansion -Wno-global-constructors -std=c++17 -Wno-c++98-compat -Wno-c++98-compat-pedantic -Wno-padded -Wno-exit-time-destructors)
endif()

# Setting important tags
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

# Tests
include(CTest)
enable_testing()
find_package(GTest REQUIRED)
include(GoogleTest)

# Setting include headers
set(INCLUDE_DIRS
        "src/course/"
        "src/algorithms/"
)

# Setting files sources
file(
        GLOB SOURCESEXE
        "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/src/algorithms/*.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/src/course/*.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/src/experiments/files/*.cpp"
)

# Linking
include_directories(${INCLUDE_DIRS})
add_executable(${PROJECT_NAME} ${SOURCESEXE})
target_compile_options(${PROJECT_NAME} PRIVATE ${COMPILE_FLAGS_CUSTOM})
add_subdirectory(${CMAKE_SOURCE_DIR}/tests)
