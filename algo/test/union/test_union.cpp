
#include <algorithm>
#include <unordered_set>

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "union/union.h"

using ::testing::UnorderedElementsAreArray;

using namespace algo::disjoint_set;

TEST(DisjointSet, disjoint)
{
    std::vector<int> data{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    
    DisjointSet<int> disjoint_set(data);
    disjoint_set.postProcess();

    EXPECT_EQ(disjoint_set.getSetCount(), 15);
    EXPECT_EQ(disjoint_set.isJoint(1, 3), false);
    EXPECT_EQ(disjoint_set.isJoint(9, 10), false);
    EXPECT_EQ(disjoint_set.isJoint(5, 5), true);
    EXPECT_EQ(disjoint_set.isJoint(5, 1000), false);

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
TEST(DisjointSet, joint)
{
    std::vector<int> data{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
    
    DisjointSet<int> disjoint_set(data);
    std::vector<std::pair<int, int>> pairs = {
        {1, 7}, {3, 12}, {6, 17}, {10, 11}, {2, 5},
        {13, 19}, {9, 14}, {11, 18}, {15, 16},
        {1, 3}, {3, 15}, {6, 20}, {20, 10}, {2, 13}, {2, 9}
    };
    for (const auto& p : pairs)
        disjoint_set.merge(p.first, p.second);
    disjoint_set.postProcess();

    EXPECT_EQ(disjoint_set.getSetCount(), 5);
    EXPECT_EQ(disjoint_set.isJoint(1, 3), true);
    EXPECT_EQ(disjoint_set.isJoint(9, 10), false);
    EXPECT_EQ(disjoint_set.isJoint(5, 5), true);
    EXPECT_EQ(disjoint_set.isJoint(5, 1000), false);
    EXPECT_EQ(disjoint_set.isJoint(6, 15), false);
    EXPECT_EQ(disjoint_set.isJoint(4, 12), false);
    EXPECT_EQ(disjoint_set.isJoint(4, 8), false);

    std::vector<std::unordered_set<int>> actual_sets;
    for (std::size_t set_id = 0; set_id < 5; set_id++) {
        const auto elements = disjoint_set.getElementsBySetID(set_id);
        actual_sets.emplace_back(elements.begin(), elements.end());
    }
    std::vector<std::unordered_set<int>> expected_sets{{1, 7, 3, 15, 12, 16}, {6, 17, 20, 10, 11, 18}, {2, 5, 9, 13, 19, 14}, {4}, {8}};
    EXPECT_THAT(actual_sets, UnorderedElementsAreArray(expected_sets));
}