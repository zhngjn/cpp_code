#include <iostream>
#include <vector>
#include <algorithm>

class Solution 
{
public:
    std::vector<std::vector<int>> subsetsWithDup(std::vector<int>& nums) 
    {
        if (!std::is_sorted(nums.begin(), nums.end()))
            std::sort(nums.begin(), nums.end());

        std::vector<std::vector<int>> subsets;
        subsets.reserve(1 << nums.size());

        generateSubset(nums, 0, {}, subsets);

        return subsets;
    }

private:
    void generateSubset(
        const std::vector<int>& nums, std::size_t i, std::vector<int> subset, std::vector<std::vector<int>>& subsets)
    {
        if (i >= nums.size())
        {
            subsets.emplace_back(subset);
            return;
        }

        std::size_t j = i + 1;
        while (j < nums.size() && nums[j] == nums[j - 1])
            j++;
        
        for (std::size_t k = 0; k <= j - i; k++)
        {
            std::vector<int> new_subset = subset;
            for (std::size_t l = 0; l < k; l++)
                new_subset.emplace_back(nums[i]);
            generateSubset(nums, j, std::move(new_subset), subsets);
        }
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
        const auto res = s.subsetsWithDup(nums);
        printSubsets(res);
    }
    {
        std::vector<int> nums{1, 2, 2};
        const auto res = s.subsetsWithDup(nums);
        printSubsets(res);
    }
}