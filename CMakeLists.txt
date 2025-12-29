cmake_minimum_required(VERSION 3.21)
project(password_generator)

# GoogleTest requires at least C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${PROJECT_SOURCE_DIR}/includes)

set(SOURCES ${PROJECT_SOURCE_DIR}/src/main.cpp
        includes/random_generator.h
        src/random_generator.cpp)

add_executable(password_generator ${SOURCES})

# Google Test setup
enable_testing()


include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/tags/v1.17.0.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Create test executable
set(TEST_SOURCES
        ${PROJECT_SOURCE_DIR}/test/test_random_generator.cpp
        ${PROJECT_SOURCE_DIR}/src/random_generator.cpp
)

add_executable(run_tests ${TEST_SOURCES})

# Link Google Test libraries
target_link_libraries(run_tests
        GTest::gtest
        GTest::gtest_main
        GTest::gmock
        GTest::gmock_main
)

# Add test
add_test(NAME run_tests COMMAND run_tests)