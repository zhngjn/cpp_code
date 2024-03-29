cmake_minimum_required(VERSION 3.16)

find_package(GTest REQUIRED)
set(GTEST_LIBS GTest::gtest GTest::gtest_main GTest::gmock GTest::gmock_main)

include_directories(
    ${PROJECT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}
)

#==================== logic test
file(GLOB TEST_LOGIC_SRCS 
    ${CMAKE_CURRENT_SOURCE_DIR}/logic/*.cpp
)

add_executable(test_logic
    ${TEST_LOGIC_SRCS}
)

target_link_libraries(test_logic
    logic
    ${GTEST_LIBS}
)

#==================== search test
file(GLOB TEST_SEARCH_SRCS 
    ${CMAKE_CURRENT_SOURCE_DIR}/search/*.cpp
)

add_executable(test_search
    ${TEST_SEARCH_SRCS}
)

target_link_libraries(test_search 
    search
    util
    ${GTEST_LIBS}
)

#==================== union test
file(GLOB TEST_UNION_SRCS 
    ${CMAKE_CURRENT_SOURCE_DIR}/union/*.cpp
)

add_executable(test_union
    ${TEST_UNION_SRCS}
)

target_link_libraries(test_union
    union
    ${GTEST_LIBS}
)

#==================== btree test
# file(GLOB TEST_BTREE_SRCS 
#     ${CMAKE_CURRENT_SOURCE_DIR}/btree/*.cpp
# )

# add_executable(test_btree
#     ${TEST_BTREE_SRCS}
# )

# target_link_libraries(test_btree
#     btree
#     ${GTEST_LIBS}
# )

add_custom_target(unittests
COMMAND test_logic
COMMAND test_search
COMMAND test_union
# COMMAND test_btree
)