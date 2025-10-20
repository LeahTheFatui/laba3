cmake_minimum_required(VERSION 3.10)
project(Figures)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(MSVC)
    set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>DLL")
endif()

add_executable(figures
        src/main.cpp
        src/array.cpp
        src/figure.cpp
        src/rectangle.cpp
        src/square.cpp
        src/trapezoid.cpp
)

include(FetchContent)

FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG v1.14.0
)

if(WIN32)
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
endif()

FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(figure_tests
        tests/test_figures.cpp
        src/array.cpp
        src/figure.cpp
        src/rectangle.cpp
        src/square.cpp
        src/trapezoid.cpp
)

target_link_libraries(figure_tests
        GTest::gtest_main
)

target_include_directories(figure_tests PRIVATE
    ${CMAKE_SOURCE_DIR}/laba3test/src
)

include(GoogleTest)
gtest_discover_tests(figure_tests)
