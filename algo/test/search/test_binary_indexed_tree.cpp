#include <functional>

#include <gtest/gtest.h>

#include "search/binary_indexed_tree.h"
#include "util/random_generator.h"

using namespace algo::search;
using namespace algo::util;

int getSum(const std::vector<int>& vec, std::size_t i)
{
    return std::accumulate(vec.begin(), vec.begin() + i + 1, 0.0);
}

TEST(BinaryIndexedTree, Sum)
{
    RandomIntGenerator<int> int_generator(100);
    std::vector<int> vec = int_generator.genRandomInts(0, 100, 100);

    BinaryIndexedTree<int, std::plus<int>> bit(vec);

    for (std::size_t i = 0; i < vec.size(); i++) {
        EXPECT_EQ(bit.sum(i), getSum(vec, i));
    }

    for (std::size_t i = 0; i < 50; i++) {
        std::size_t idx = static_cast<std::size_t>(int_generator.genRandomInt(0, 99));
        int inc = int_generator.genRandomInt(-50, 50);
        vec[idx] += inc;

        bit.add(idx, inc);

        for (std::size_t i = 0; i < vec.size(); i++) {
            EXPECT_EQ(bit.sum(i), getSum(vec, i));
        }
    }
}