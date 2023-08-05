cmake_minimum_required(VERSION 3.16)

project(algo)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC -Wall") 

# find_package(Boost REQUIRED COMPONENTS math)


add_subdirectory(src/logic)
add_subdirectory(src/search)
add_subdirectory(src/util)
add_subdirectory(test)
