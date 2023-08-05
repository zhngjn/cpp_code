cmake_minimum_required(VERSION 3.16)

file(GLOB UTIL_SRCS 
    ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
)

add_library(util SHARED
    ${UTIL_SRCS}
)

target_include_directories(util
PUBLIC
    ${PROJECT_SOURCE_DIR}/include/util
)