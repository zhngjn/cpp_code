
#include <algorithm>
#include <unordered_set>

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "union/weighted_union.h"

using ::testing::UnorderedElementsAreArray;

using namespace algo::disjoint_set;

TEST(WeightedDisjointSet, disjoint)
{
    std::vector<int> data{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    
    WeightedDisjointSet<int, int> disjoint_set(data);
    disjoint_set.postProcess();

    EXPECT_EQ(disjoint_set.getSetCount(), 15);
    EXPECT_EQ(disjoint_set.isJoint(1, 3), false);
    EXPECT_EQ(disjoint_set.isJoint(9, 10), false);
    EXPECT_EQ(disjoint_set.isJoint(5, 5), true);
    EXPECT_EQ(disjoint_set.isJoint(5, 1000), false);

    EXPECT_EQ(*disjoint_set.getWeightBetween(5, 5), 0);
    EXPECT_FALSE(!!disjoint_set.getWeightBetween(1, 3));
    EXPECT_FALSE(!!disjoint_set.getWeightBetween(9, 10));
    EXPECT_FALSE(!!disjoint_set.getWeightBetween(5, 1000));

    std::vector<std::unordered_set<int>> actual_sets;
    for (std::size_t set_id = 0; set_id < 15; set_id++) {
        const auto elements = disjoint_set.getElementsBySetID(set_id);
        actual_sets.emplace_back(elements.begin(), elements.end());
    }
    std::vector<std::unordered_set<int>> expected_sets{{1}, {2}, {3}, {4}, {5}, {6}, {7}, {8}, {9}, {10}, {11}, {12}, {13}, {14}, {15}};
    EXPECT_THAT(actual_sets, UnorderedElementsAreArray(expected_sets));
}

/**
 *     1              6                 2            4          8
 *    7  3        20    17          5   9   13
 *     15 12        10                  14    19
 *   16               11
 *                      18
 */
TEST(WeightedDisjointSet, joint)
{
    std::vector<int> data{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
    
    WeightedDisjointSet<int, int> disjoint_set(data);
    std::vector<std::tuple<int, int, int>> tuples = {
        {1, 7, 2}, {3, 12, 8}, {6, 17, 1}, {10, 11, 3}, {2, 5, 4},
        {13, 19, 9}, {9, 14, 5}, {11, 18, 6}, {15, 16, 7},
        {1, 3, 5}, {3, 15, 2}, {6, 20, 3}, {20, 10, 1}, {2, 13, 4}, {2, 9, 3}
    };
    for (const auto& t : tuples)
        disjoint_set.merge(std::get<0>(t), std::get<1>(t), std::get<2>(t));
    disjoint_set.postProcess();

    EXPECT_EQ(disjoint_set.getSetCount(), 5);
    EXPECT_EQ(disjoint_set.isJoint(1, 3), true);
    EXPECT_EQ(disjoint_set.isJoint(9, 10), false);
    EXPECT_EQ(disjoint_set.isJoint(5, 5), true);
    EXPECT_EQ(disjoint_set.isJoint(5, 1000), false);
    EXPECT_EQ(disjoint_set.isJoint(6, 15), false);
    EXPECT_EQ(disjoint_set.isJoint(4, 12), false);
    EXPECT_EQ(disjoint_set.isJoint(4, 8), false);

    EXPECT_EQ(*disjoint_set.getWeightBetween(1, 3), 5);
    EXPECT_EQ(*disjoint_set.getWeightBetween(1, 7), 2);
    // EXPECT_EQ(*disjoint_set.getWeightBetween(1, 12), 13);
    // EXPECT_EQ(*disjoint_set.getWeightBetween(3, 12), 8);
    // EXPECT_EQ(*disjoint_set.getWeightBetween(3, 16), 9);
    // EXPECT_EQ(*disjoint_set.getWeightBetween(1, 16), 14);
    // EXPECT_EQ(*disjoint_set.getWeightBetween(6, 17), 1);
    // EXPECT_EQ(*disjoint_set.getWeightBetween(6, 10), 4);
    // EXPECT_EQ(*disjoint_set.getWeightBetween(6, 18), 13);
    // EXPECT_EQ(*disjoint_set.getWeightBetween(2, 2), 0);
    // EXPECT_EQ(*disjoint_set.getWeightBetween(2, 13), 4);
    // EXPECT_EQ(*disjoint_set.getWeightBetween(2, 19), 13);
    // EXPECT_EQ(*disjoint_set.getWeightBetween(9, 14), 5);
    // EXPECT_EQ(*disjoint_set.getWeightBetween(2, 14), 8);
    // EXPECT_FALSE(!!disjoint_set.getWeightBetween(20, 13));
    // EXPECT_FALSE(!!disjoint_set.getWeightBetween(1, 5));
    // EXPECT_FALSE(!!disjoint_set.getWeightBetween(4, 8));
    // EXPECT_FALSE(!!disjoint_set.getWeightBetween(4, 15));

    std::vector<std::unordered_set<int>> actual_sets;
    for (std::size_t set_id = 0; set_id < 5; set_id++) {
        const auto elements = disjoint_set.getElementsBySetID(set_id);
        actual_sets.emplace_back(elements.begin(), elements.end());
    }
    std::vector<std::unordered_set<int>> expected_sets{{1, 7, 3, 15, 12, 16}, {6, 17, 20, 10, 11, 18}, {2, 5, 9, 13, 19, 14}, {4}, {8}};
    EXPECT_THAT(actual_sets, UnorderedElementsAreArray(expected_sets));
}