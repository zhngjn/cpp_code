cmake_minimum_required(VERSION 3.16)

file(GLOB SEARCH_SRCS 
    ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
)

add_library(search SHARED
    ${SEARCH_SRCS}
)

target_include_directories(search
PUBLIC
    ${PROJECT_SOURCE_DIR}/include/search
)