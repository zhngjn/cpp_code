#include <tuple>
#include <vector> 

#include <gtest/gtest.h>

#include "logic/kleene3.hpp"

using namespace algo::logic;

TEST(Kleene3, and)
{
    std::vector<std::tuple<K3VL, K3VL, K3VL>> mapping_list = 
    {
        {K3VL::False, K3VL::False, K3VL::False},
        {K3VL::False, K3VL::Unknown, K3VL::False},
        {K3VL::False, K3VL::True, K3VL::False},

        {K3VL::Unknown, K3VL::False, K3VL::False},
        {K3VL::Unknown, K3VL::Unknown, K3VL::Unknown},
        {K3VL::Unknown, K3VL::True, K3VL::Unknown},

        {K3VL::True, K3VL::False, K3VL::False},
        {K3VL::True, K3VL::Unknown, K3VL::Unknown},
        {K3VL::True, K3VL::True, K3VL::True},
    };

    for (const auto& mapping : mapping_list) {
        ASSERT_EQ(std::get<0>(mapping) && std::get<1>(mapping), std::get<2>(mapping));
    }
}

TEST(Kleene3, or)
{
    std::vector<std::tuple<K3VL, K3VL, K3VL>> mapping_list = 
    {
        {K3VL::False, K3VL::False, K3VL::False},
        {K3VL::False, K3VL::Unknown, K3VL::Unknown},
        {K3VL::False, K3VL::True, K3VL::True},

        {K3VL::Unknown, K3VL::False, K3VL::Unknown},
        {K3VL::Unknown, K3VL::Unknown, K3VL::Unknown},
        {K3VL::Unknown, K3VL::True, K3VL::True},

        {K3VL::True, K3VL::False, K3VL::True},
        {K3VL::True, K3VL::Unknown, K3VL::True},
        {K3VL::True, K3VL::True, K3VL::True},
    };

    for (const auto& mapping : mapping_list) {
        ASSERT_EQ(std::get<0>(mapping) || std::get<1>(mapping), std::get<2>(mapping));
    }
}

TEST(Kleene3, not)
{
    std::vector<std::tuple<K3VL, K3VL>> mapping_list = 
    {
        {K3VL::False, K3VL::True},
        {K3VL::Unknown, K3VL::Unknown},
        {K3VL::True, K3VL::False},
    };

    for (const auto& mapping : mapping_list) {
        ASSERT_EQ(!std::get<0>(mapping), std::get<1>(mapping));
    }
}