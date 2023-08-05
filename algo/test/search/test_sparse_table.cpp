#include <functional>
#include <algorithm>

#include <gtest/gtest.h>

#include "search/sparse_table.h"
#include "util/random_generator.h"

using namespace algo::search;
using namespace algo::util;

template <typename T>
T getMinElement(const std::vector<T>& vec, std::size_t L, std::size_t R)
{
    return *std::min_element(vec.begin() + L, vec.begin() + R);
}

struct MinIntSelector
{
    MinIntSelector() = default;
    inline int operator()(int x, int y) const
    {
        return x <= y ? x : y;
    }
};

TEST(SparseTable, MinInt)
{
    RandomIntGenerator<int> int_generator(1234);
    std::vector<int> vec = int_generator.genRandomInts(0, 10000, 1000);

    SparseTable<std::vector<int>::const_iterator, MinIntSelector> sp(vec.begin(), vec.end());

    struct {
        std::size_t step[7] = {2, 3, 5, 7, 9, 11, 15};
        std::size_t idx = 0;
    } step_controller;
    for (std::size_t l = 1; l <= 1000; ) {
        for (std::size_t s = 0; s + l <= 1000; s++) {
            int actual = sp.RMQ(s, s + l);
            int expected = getMinElement(vec, s, s + l);
            EXPECT_EQ(actual, expected);
        }
        l += step_controller.step[step_controller.idx];
        step_controller.idx = (step_controller.idx + 1) % 7;
    }
}