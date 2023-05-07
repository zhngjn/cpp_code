#include <algorithm>
#include <vector>
#include <limits>
#include <iostream>

class Solution 
{
public:
    std::vector<std::vector<int>> permuteUnique(std::vector<int>& nums) 
    {
        std::vector<std::vector<int>> all_permutations;
        if (nums.empty() || nums.size() == 1)
        {
            all_permutations.emplace_back(nums);
            return all_permutations;
        }

        if (!std::is_sorted(nums.begin(), nums.end()))
            std::sort(nums.begin(), nums.end());

        // first perm
        all_permutations.emplace_back(nums);

        auto pos = findLastAscendingPos(nums);
        while (pos != InvalidPos)
        {
            auto i = nums.size() - 1;
            while (nums[i] <= nums[pos])
                i--;
            std::swap(nums[pos], nums[i]);
                
            reverseRange(nums, pos + 1, nums.size() - 1);

            // next perm
            all_permutations.emplace_back(nums);

            pos = findLastAscendingPos(nums);
        }

        return all_permutations;
    }

private:
    std::size_t findLastAscendingPos(const std::vector<int>& nums)
    {
        for (std::size_t i = nums.size() - 1; i > 0; i--)
        {
            if (nums[i] > nums[i - 1])
                return i - 1;
        }
        return InvalidPos;
    }

    void reverseRange(std::vector<int>& nums, std::size_t p, std::size_t q)
    {
        while (p < q)
            std::swap(nums[p++], nums[q--]);
    }

private:
    static constexpr std::size_t InvalidPos = std::numeric_limits<std::size_t>::max();
};