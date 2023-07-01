#include "permute_unique.hpp"

int main()
{
    Solution solution;

    {
        std::vector<int> vec{1, 1, 2};
        std::vector<std::vector<int>> perms = solution.permuteUnique(vec);
        for (const auto& perm : perms)
        {
            for (const auto& v : perm)
                std::cout << v << ",";
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
    {
        std::vector<int> vec{1, 2, 3};
        std::vector<std::vector<int>> perms = solution.permuteUnique(vec);
        for (const auto& perm : perms)
        {
            for (const auto& v : perm)
                std::cout << v << ",";
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
}