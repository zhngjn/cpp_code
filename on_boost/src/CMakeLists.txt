cmake_minimum_required(VERSION 3.16)

# find_package(Boost REQUIRED COMPONENTS any)

include_directories(${PROJECT_SOURCE_DIR})

add_library(OnBoost SHARED
    any_out.cpp
)

# target_link_libraries(OnBoost
#     private Boost::any
# )