cmake_minimum_required(VERSION 3.18)

project(Galois)

# language and compiler setup
set(
    CMAKE_CXX_STANDARD 20
    CMAKE_CXX_STANDARD_REQUIRED ON
)  

add_compile_options(
    -Wall 
    -Wextra 
    -g       
    -Wuninitialized 
    -Wunused-variable
    -Wshadow
)


# Fetch GoogleTest library
include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

FetchContent_MakeAvailable(googletest)



# fmt setup
find_package(fmt REQUIRED)


set(GALOIS_SRC "inc/Galois.inl")

add_executable(${PROJECT_NAME} ${GALOIS_SRC} src/main.cpp)

target_include_directories(${PROJECT_NAME} PRIVATE inc)

target_link_libraries(${PROJECT_NAME} PRIVATE fmt::fmt)


# Testing

set(GALOIS_TEST galoisTest)

add_executable(${GALOIS_TEST} test/galoisTest.cpp)

target_include_directories(${GALOIS_TEST} PRIVATE inc)

target_link_libraries(${GALOIS_TEST} PRIVATE GTest::gtest_main)


# Configure GoogleTest tests
include(GoogleTest)
enable_testing()
gtest_discover_tests(${GALOIS_TEST})