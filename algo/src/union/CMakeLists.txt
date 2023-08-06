cmake_minimum_required(VERSION 3.16)

file(GLOB UNION_SRCS 
    ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
)

add_library(union SHARED
    ${UNION_SRCS}
)

target_include_directories(union
PUBLIC
    ${PROJECT_SOURCE_DIR}/include/union
)

# target_link_libraries(union
# PUBLIC
#     util
# )