cmake_minimum_required(VERSION 3.16)

file(GLOB LOGIC_SRCS 
    ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
)

add_library(logic SHARED
    ${LOGIC_SRCS}
)

target_include_directories(logic
PUBLIC
    ${PROJECT_SOURCE_DIR}/include/logic
)