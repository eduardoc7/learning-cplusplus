# Configuração dos testes no CMake/GoogleTest

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../src)
set(CMAKE_CXX_STANDARD 17)

set(srcdir "${CMAKE_CURRENT_SOURCE_DIR}")
set(msrcdir "${CMAKE_CURRENT_SOURCE_DIR}/../src")
set(mainbinary "${CMAKE_CURRENT_SOURCE_DIR}/../bin")

file(
        GLOB MAIN_SOURCES
        "${msrcdir}/algorithms/*.cpp"
)

file(
        GLOB ALL_TESTS_SOURCES
        "${srcdir}/*.cpp"
)

add_executable(maintest_binary ${ALL_TESTS_SOURCES} ${MAIN_SOURCES})

target_compile_options(maintest_binary PUBLIC ${COMPILE_FLAGS_CUSTOM})
target_link_libraries(maintest_binary GTest::GTest GTest::Main)

gtest_discover_tests(maintest_binary)