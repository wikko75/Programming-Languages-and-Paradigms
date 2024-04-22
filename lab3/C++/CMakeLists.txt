cmake_minimum_required(VERSION 3.18)

project(Diffie_Hellman)

# compiler and language setup
set(
    CMAKE_CXX_STANDARD 23
    CMAKE_C_STANDARD_REQUIRED ON
)

add_compile_options(
    -Wall 
    -Wextra 
    -O3      
    -Wuninitialized 
    -Wunused-variable
    -Wshadow
)

# fmt setup
find_package(fmt REQUIRED)


# includes
set(GALOIS_INCLUDE "../../lab2/C++/inc")

add_executable(${PROJECT_NAME} "src/main.cpp")

target_include_directories(${PROJECT_NAME} PRIVATE "inc" ${GALOIS_INCLUDE})

target_link_libraries(${PROJECT_NAME} PRIVATE fmt::fmt)