#include <iostream>
#include <vector>

class Solution 
{
public:
    int missingNumber(std::vector<int>& nums) 
    {
        int n = nums.size();
        int res = n;
        for (std::size_t i = 0; i < n; i++)
        {
            res ^= i;
            res ^= nums[i];
        }
        return res;
    }
};

int main()
{
    Solution s;

    {
        std::vector<int> nums{3,0,1};
        std::cout << s.missingNumber(nums) << std::endl;
    }
    {
        std::vector<int> nums{0,1};
        std::cout << s.missingNumber(nums) << std::endl;
    }
    {
        std::vector<int> nums{9,6,4,2,3,5,7,0,1};
        std::cout << s.missingNumber(nums) << std::endl;
    }
}