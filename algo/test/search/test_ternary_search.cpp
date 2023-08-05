#include <vector> 

#include <gtest/gtest.h>

#include "search/ternary_search.h"

using namespace algo::search;

<<<<<<< HEAD
// --------------------------------- test ternary search: iterative version
=======
>>>>>>> add ternary search
TEST(ternarySearch, vector0)
{
    std::vector<int> vec{};
    {
        EXPECT_EQ(ternarySearch(vec.begin(), vec.end(), 1), vec.end());
    }
    {
        EXPECT_EQ(ternarySearch2(vec.begin(), vec.end(), 1), vec.end());
    }
}

TEST(ternarySearch, vector1)
{
    std::vector<int> vec{5};
    {
        EXPECT_EQ(*ternarySearch(vec.begin(), vec.end(), 5), 5);
        EXPECT_EQ(ternarySearch(vec.begin(), vec.end(), 3), vec.end());
        EXPECT_EQ(ternarySearch(vec.begin(), vec.end(), 6), vec.end());
    }
    {
        EXPECT_EQ(*ternarySearch2(vec.begin(), vec.end(), 5), 5);
        EXPECT_EQ(ternarySearch2(vec.begin(), vec.end(), 3), vec.end());
        EXPECT_EQ(ternarySearch2(vec.begin(), vec.end(), 6), vec.end());
    }
}

TEST(ternarySearch, vector2)
{
    std::vector<int> vec{5, 10};
    {
        EXPECT_EQ(*ternarySearch(vec.begin(), vec.end(), 5), 5);
        EXPECT_EQ(*ternarySearch(vec.begin(), vec.end(), 10), 10);
        EXPECT_EQ(ternarySearch(vec.begin(), vec.end(), 3), vec.end());
        EXPECT_EQ(ternarySearch(vec.begin(), vec.end(), 6), vec.end());
        EXPECT_EQ(ternarySearch(vec.begin(), vec.end(), 12), vec.end());
    }
    {
        EXPECT_EQ(*ternarySearch2(vec.begin(), vec.end(), 5), 5);
        EXPECT_EQ(*ternarySearch2(vec.begin(), vec.end(), 10), 10);
        EXPECT_EQ(ternarySearch2(vec.begin(), vec.end(), 3), vec.end());
        EXPECT_EQ(ternarySearch2(vec.begin(), vec.end(), 6), vec.end());
        EXPECT_EQ(ternarySearch2(vec.begin(), vec.end(), 12), vec.end());
    }
}

TEST(ternarySearch, vector3)
{
    std::vector<int> vec{5, 10, 15};
    {
        EXPECT_EQ(*ternarySearch(vec.begin(), vec.end(), 5), 5);
        EXPECT_EQ(*ternarySearch(vec.begin(), vec.end(), 10), 10);
        EXPECT_EQ(*ternarySearch(vec.begin(), vec.end(), 15), 15);
        EXPECT_EQ(ternarySearch(vec.begin(), vec.end(), 3), vec.end());
        EXPECT_EQ(ternarySearch(vec.begin(), vec.end(), 6), vec.end());
        EXPECT_EQ(ternarySearch(vec.begin(), vec.end(), 12), vec.end());
        EXPECT_EQ(ternarySearch(vec.begin(), vec.end(), 16), vec.end());
    }
    {
        EXPECT_EQ(*ternarySearch2(vec.begin(), vec.end(), 5), 5);
        EXPECT_EQ(*ternarySearch2(vec.begin(), vec.end(), 10), 10);
        EXPECT_EQ(*ternarySearch2(vec.begin(), vec.end(), 15), 15);
        EXPECT_EQ(ternarySearch2(vec.begin(), vec.end(), 3), vec.end());
        EXPECT_EQ(ternarySearch2(vec.begin(), vec.end(), 6), vec.end());
        EXPECT_EQ(ternarySearch2(vec.begin(), vec.end(), 12), vec.end());
        EXPECT_EQ(ternarySearch2(vec.begin(), vec.end(), 16), vec.end());
    }
}

TEST(ternarySearch, vector10)
{
    std::vector<int> vec{1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    {
        for (int i = 1; i < 20; i += 2) {
            EXPECT_EQ(*ternarySearch(vec.begin(), vec.end(), i), i);
        }
        for (int i = 0; i < 21; i += 2) {
            EXPECT_EQ(ternarySearch(vec.begin(), vec.end(), i), vec.end());
        }
    }
    {
        for (int i = 1; i < 20; i += 2) {
            EXPECT_EQ(*ternarySearch2(vec.begin(), vec.end(), i), i);
        }
        for (int i = 0; i < 21; i += 2) {
            EXPECT_EQ(ternarySearch2(vec.begin(), vec.end(), i), vec.end());
        }
    }
}

TEST(ternarySearch, vector6dup)
{
    std::vector<int> vec{2, 2, 4, 4, 6, 6};
    {
        EXPECT_EQ(*ternarySearch(vec.begin(), vec.end(), 2), 2);
        EXPECT_EQ(*ternarySearch(vec.begin(), vec.end(), 4), 4);
        EXPECT_EQ(*ternarySearch(vec.begin(), vec.end(), 6), 6);
        EXPECT_EQ(ternarySearch(vec.begin(), vec.end(), 1), vec.end());
        EXPECT_EQ(ternarySearch(vec.begin(), vec.end(), 3), vec.end());
        EXPECT_EQ(ternarySearch(vec.begin(), vec.end(), 5), vec.end());
        EXPECT_EQ(ternarySearch(vec.begin(), vec.end(), 7), vec.end());
    }
    {
        EXPECT_EQ(*ternarySearch2(vec.begin(), vec.end(), 2), 2);
        EXPECT_EQ(*ternarySearch2(vec.begin(), vec.end(), 4), 4);
        EXPECT_EQ(*ternarySearch2(vec.begin(), vec.end(), 6), 6);
        EXPECT_EQ(ternarySearch2(vec.begin(), vec.end(), 1), vec.end());
        EXPECT_EQ(ternarySearch2(vec.begin(), vec.end(), 3), vec.end());
        EXPECT_EQ(ternarySearch2(vec.begin(), vec.end(), 5), vec.end());
        EXPECT_EQ(ternarySearch2(vec.begin(), vec.end(), 7), vec.end());
    }
}

// --------------------------------- test ternary search: resursive version
TEST(ternarySearchR, vector0)
{
    std::vector<int> vec{};
    {
        EXPECT_EQ(ternarySearchR(vec.begin(), vec.end(), 1), vec.end());
    }
    {
        EXPECT_EQ(ternarySearchR2(vec.begin(), vec.end(), 1), vec.end());
    }
}

TEST(ternarySearchR, vector1)
{
    std::vector<int> vec{5};
    {
        EXPECT_EQ(*ternarySearchR(vec.begin(), vec.end(), 5), 5);
        EXPECT_EQ(ternarySearchR(vec.begin(), vec.end(), 3), vec.end());
        EXPECT_EQ(ternarySearchR(vec.begin(), vec.end(), 6), vec.end());
    }
    {
        EXPECT_EQ(*ternarySearchR2(vec.begin(), vec.end(), 5), 5);
        EXPECT_EQ(ternarySearchR2(vec.begin(), vec.end(), 3), vec.end());
        EXPECT_EQ(ternarySearchR2(vec.begin(), vec.end(), 6), vec.end());
    }
}

TEST(ternarySearchR, vector2)
{
    std::vector<int> vec{5, 10};
    {
        EXPECT_EQ(*ternarySearchR(vec.begin(), vec.end(), 5), 5);
        EXPECT_EQ(*ternarySearchR(vec.begin(), vec.end(), 10), 10);
        EXPECT_EQ(ternarySearchR(vec.begin(), vec.end(), 3), vec.end());
        EXPECT_EQ(ternarySearchR(vec.begin(), vec.end(), 6), vec.end());
        EXPECT_EQ(ternarySearchR(vec.begin(), vec.end(), 12), vec.end());
    }
    {
        EXPECT_EQ(*ternarySearchR2(vec.begin(), vec.end(), 5), 5);
        EXPECT_EQ(*ternarySearchR2(vec.begin(), vec.end(), 10), 10);
        EXPECT_EQ(ternarySearchR2(vec.begin(), vec.end(), 3), vec.end());
        EXPECT_EQ(ternarySearchR2(vec.begin(), vec.end(), 6), vec.end());
        EXPECT_EQ(ternarySearchR2(vec.begin(), vec.end(), 12), vec.end());
    }
}

TEST(ternarySearchR, vector3)
{
    std::vector<int> vec{5, 10, 15};
    {
        EXPECT_EQ(*ternarySearchR(vec.begin(), vec.end(), 5), 5);
        EXPECT_EQ(*ternarySearchR(vec.begin(), vec.end(), 10), 10);
        EXPECT_EQ(*ternarySearchR(vec.begin(), vec.end(), 15), 15);
        EXPECT_EQ(ternarySearchR(vec.begin(), vec.end(), 3), vec.end());
        EXPECT_EQ(ternarySearchR(vec.begin(), vec.end(), 6), vec.end());
        EXPECT_EQ(ternarySearchR(vec.begin(), vec.end(), 12), vec.end());
        EXPECT_EQ(ternarySearchR(vec.begin(), vec.end(), 16), vec.end());
    }
    {
        EXPECT_EQ(*ternarySearchR2(vec.begin(), vec.end(), 5), 5);
        EXPECT_EQ(*ternarySearchR2(vec.begin(), vec.end(), 10), 10);
        EXPECT_EQ(*ternarySearchR2(vec.begin(), vec.end(), 15), 15);
        EXPECT_EQ(ternarySearchR2(vec.begin(), vec.end(), 3), vec.end());
        EXPECT_EQ(ternarySearchR2(vec.begin(), vec.end(), 6), vec.end());
        EXPECT_EQ(ternarySearchR2(vec.begin(), vec.end(), 12), vec.end());
        EXPECT_EQ(ternarySearchR2(vec.begin(), vec.end(), 16), vec.end());
    }
}

TEST(ternarySearchR, vector10)
{
    std::vector<int> vec{1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    {
        for (int i = 1; i < 20; i += 2) {
            EXPECT_EQ(*ternarySearchR(vec.begin(), vec.end(), i), i);
        }
        for (int i = 0; i < 21; i += 2) {
            EXPECT_EQ(ternarySearchR(vec.begin(), vec.end(), i), vec.end());
        }
    }
    {
        for (int i = 1; i < 20; i += 2) {
            EXPECT_EQ(*ternarySearchR2(vec.begin(), vec.end(), i), i);
        }
        for (int i = 0; i < 21; i += 2) {
            EXPECT_EQ(ternarySearchR2(vec.begin(), vec.end(), i), vec.end());
        }
    }
}

TEST(ternarySearchR, vector6dup)
{
    std::vector<int> vec{2, 2, 4, 4, 6, 6};
    {
        EXPECT_EQ(*ternarySearchR(vec.begin(), vec.end(), 2), 2);
        EXPECT_EQ(*ternarySearchR(vec.begin(), vec.end(), 4), 4);
        EXPECT_EQ(*ternarySearchR(vec.begin(), vec.end(), 6), 6);
        EXPECT_EQ(ternarySearchR(vec.begin(), vec.end(), 1), vec.end());
        EXPECT_EQ(ternarySearchR(vec.begin(), vec.end(), 3), vec.end());
        EXPECT_EQ(ternarySearchR(vec.begin(), vec.end(), 5), vec.end());
        EXPECT_EQ(ternarySearchR(vec.begin(), vec.end(), 7), vec.end());
    }
    {
        EXPECT_EQ(*ternarySearchR2(vec.begin(), vec.end(), 2), 2);
        EXPECT_EQ(*ternarySearchR2(vec.begin(), vec.end(), 4), 4);
        EXPECT_EQ(*ternarySearchR2(vec.begin(), vec.end(), 6), 6);
        EXPECT_EQ(ternarySearchR2(vec.begin(), vec.end(), 1), vec.end());
        EXPECT_EQ(ternarySearchR2(vec.begin(), vec.end(), 3), vec.end());
        EXPECT_EQ(ternarySearchR2(vec.begin(), vec.end(), 5), vec.end());
        EXPECT_EQ(ternarySearchR2(vec.begin(), vec.end(), 7), vec.end());
    }
}
