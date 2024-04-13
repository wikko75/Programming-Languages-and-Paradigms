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


# fmt setup
find_package(fmt REQUIRED)


set(GALOIS_SRC "inc/Galois.inl")

add_executable(${PROJECT_NAME} ${GALOIS_SRC} src/main.cpp)

target_include_directories(${PROJECT_NAME} PRIVATE inc)

target_link_libraries(${PROJECT_NAME} PRIVATE fmt::fmt)