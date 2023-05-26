#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

#include "util/to_string.hpp"

class Solution 
{
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) 
    {
        if (nums.size() < 2)
            return {-1, -1};

        std::vector<int> ordering(nums.size());
        std::iota(ordering.begin(), ordering.end(), 0);
        std::sort(ordering.begin(), ordering.end(), [&nums](int i, int j){
            return nums[i] < nums[j];
        });

        int i = 0, j = ordering.size() - 1;
        while (i < j)
        {
            int sum = nums[ordering[i]] + nums[ordering[j]];
            if (sum == target)
                return {ordering[i], ordering[j]};
            else if (sum < target)
                i++;
            else
                j--;
        }
        return {-1, -1};
    }
};

int main()
{
    Solution s;

    {
        std::vector<int> nums{2,7,11,15};
        std::cout << util::toString(s.twoSum(nums, 9)) << std::endl;
    }
    {
        std::vector<int> nums{3,2,4};
        std::cout << util::toString(s.twoSum(nums, 6)) << std::endl;
    }
    {
        std::vector<int> nums{3,3};
        std::cout << util::toString(s.twoSum(nums, 6)) << std::endl;
    }
}
