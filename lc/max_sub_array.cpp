#include <iostream>
#include <vector>
#include <algorithm>

class Solution 
{
public:
    int maxSubArray(std::vector<int>& nums) 
    {
        int max_sum = -1000000;
        int last_sum = 0;
        for (std::size_t i = 0; i < nums.size(); i++)
        {
            if (nums[i] < 0)
            {               
                last_sum += nums[i];
                if (last_sum <= 0)
                    last_sum = 0;

                max_sum = std::max(max_sum, nums[i]);
            }
            else
            {
                last_sum += nums[i];
                max_sum = std::max(max_sum, last_sum);
            }
        }
        return max_sum;
    }
};

int main()
{
    Solution s;

    {
        std::vector<int> nums{-2,1,-3,4,-1,2,1,-5,4};
        std::cout << s.maxSubArray(nums) << std::endl;
    }
    {
        std::vector<int> nums{1};
        std::cout << s.maxSubArray(nums) << std::endl;
    }
    {
        std::vector<int> nums{5,4,-1,7,8};
        std::cout << s.maxSubArray(nums) << std::endl;
    }
}