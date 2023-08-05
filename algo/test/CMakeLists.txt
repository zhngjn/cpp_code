cmake_minimum_required(VERSION 3.16)

find_package(GTest REQUIRED)
set(GTEST_LIBS GTest::gtest GTest::gtest_main GTest::gmock GTest::gmock_main)

include_directories(
    ${PROJECT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}
)

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

file(GLOB TEST_SEARCH_SRCS 
    ${CMAKE_CURRENT_SOURCE_DIR}/search/*.cpp
)

add_executable(test_search
    ${TEST_SEARCH_SRCS}
)

target_link_libraries(test_search 
    search
    ${GTEST_LIBS}
)