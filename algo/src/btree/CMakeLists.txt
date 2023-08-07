cmake_minimum_required(VERSION 3.16)

file(GLOB BTREE_SRCS 
    ${CMAKE_CURRENT_SOURCE_DIR}/**/*.cpp
)

add_library(btree SHARED
    ${BTREE_SRCS}
)

target_include_directories(btree
PUBLIC
    ${PROJECT_SOURCE_DIR}/include/btree
)