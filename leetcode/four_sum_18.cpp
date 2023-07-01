#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdint>

#include "util/to_string.hpp"

class Solution 
{
public:
    std::vector<std::vector<int>> fourSum(std::vector<int>& nums, int target) 
    {
        std::size_t N = nums.size();
        if (N < 4)
            return {};

        std::sort(nums.begin(), nums.end());

        std::vector<std::vector<int>> quadruples;
        for (std::size_t i = 0; i < N - 3;)
        {
            if ((std::int64_t)nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target)
                break;
            if ((std::int64_t)nums[i] + nums[N - 3] + nums[N - 2] + nums[N - 1] < target)
            {
                int last_vi = nums[i];
                while (i < N - 3 && nums[i] == last_vi)
                    i++;
                continue;
            }

            for (std::size_t j = i + 1; j < N - 2;)
            {
                if ((std::int64_t)nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target)
                    break;
                if ((std::int64_t)nums[i] + nums[j] + nums[N - 1] + nums[N - 2] < target)
                {
                    int last_vj = nums[j];
                    while (j < N - 2 && nums[j] == last_vj)
                        j++;
                    continue;
                }

                std::int64_t target2 = (std::int64_t)target - nums[i] - nums[j];

                std::size_t m = j + 1, n = N - 1;
                while (m < n)
                {
                    if (nums[m] + nums[n] > target2)
                    {
                        n--;
                    }
                    else if (nums[m] + nums[n] < target2)
                    {
                        m++;
                    }
                    else 
                    {
                        quadruples.emplace_back(std::vector<int>{nums[i], nums[j], nums[m], nums[n]});

                        int left = nums[m];
                        while (m < N && nums[m] == left)
                            m++;
                        
                        int right = nums[n];
                        while (n > j && nums[n] == right)
                            n--;
                    }
                }

                int last_vj = nums[j];
                while (j < N - 2 && nums[j] == last_vj)
                    j++;
            }

            int last_vi = nums[i];
            while (i < N - 3 && nums[i] == last_vi)
                i++;
        }

        return quadruples;
    }
};

int main()
{
    Solution s;

    {
        std::vector<int> nums{1,0,-1,0,-2,2};
        int target = 0;
        std::cout << util::toString(s.fourSum(nums, target)) << std::endl;
    }
    {
        std::vector<int> nums{2,2,2,2,2};
        int target = 8;
        std::cout << util::toString(s.fourSum(nums, target)) << std::endl;
    }
    {
        std::vector<int> nums{-1,0,1,2,-1,-4};
        int target = -1;
        std::cout << util::toString(s.fourSum(nums, target)) << std::endl;
    }
}