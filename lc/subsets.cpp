#include <iostream>
#include <vector>
#include <cmath>
#include <cstdint>

class Solution 
{
public:
    std::vector<std::vector<int>> subsets(std::vector<int>& nums) 
    {
        std::vector<std::vector<int>> subsets;
        subsets.reserve(1 << nums.size());

        std::uint32_t n = (1u << nums.size()) - 1;
        for (std::uint32_t i = 0; i <= n; i++)
            subsets.emplace_back(generateSubset(nums, i));

        return subsets;
    }

private:
    std::vector<int> generateSubset(const std::vector<int>& nums, std::uint32_t mask)
    {
        std::vector<int> subset;
        subset.reserve(nums.size());

        std::uint32_t b = 1u << (nums.size() - 1);
        std::size_t i = 0;
        while (b)
        {
            if (mask & b)
                subset.emplace_back(nums[i]);
            b >>= 1;
            i++;
        }

        return subset;
    }
};

void printSubsets(const std::vector<std::vector<int>>& subsets)
{   
    std::cout << "----------------------------" << std::endl;
    for (const auto& subset : subsets)
    {
        for (const auto v : subset)
            std::cout << v << ",";
        std::cout << std::endl;
    }
}

int main()
{
    Solution s;

    {
        std::vector<int> nums{0};
        const auto res = s.subsets(nums);
        printSubsets(res);
    }
    {
        std::vector<int> nums{1, 2, 3};
        const auto res = s.subsets(nums);
        printSubsets(res);
    }
}