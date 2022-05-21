cmake_minimum_required(VERSION 3.16)

include_directories(${PROJECT_SOURCE_DIR}/src)

add_executable(TestAnyOut
    test_any_out.cpp
)
target_link_libraries(TestAnyOut
    PRIVATE OnBoost
)

add_executable(TestVariant1
    test_variant1.cpp
)