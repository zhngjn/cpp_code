#include <iostream>
#include <vector>
#include <algorithm>

// class Solution 
// {
// public:
//     int firstMissingPositive(std::vector<int>& nums) 
//     {
//         int i = 0, j = nums.size() - 1;
//         while (i <= j)
//         {
//             if (nums[i] == i + 1)
//             {
//                 i++;
//                 continue;
//             }

//             if (nums[i] <= 0 || nums[i] > j + 1)
//             {
//                 std::swap(nums[i], nums[j]);
//                 j--;
//                 continue;
//             }

//             if (i < nums[i] - 1 && nums[i] != nums[nums[i] - 1])
//             {
//                 std::swap(nums[i], nums[nums[i] - 1]);
//             }
//             else
//             {
//                 std::swap(nums[i], nums[j]);
//                 j--;
//             }
//         }
//         return i + 1;
//     }
// };

class Solution 
{
public:
    int firstMissingPositive(std::vector<int>& nums) 
    {
        int i = 0, j = nums.size() - 1;
        while (i <= j)
        {
            while (i <= j && nums[i] == i + 1)
                i++;
            if (i > j)
                break;

            if (nums[i] < i + 1 || nums[i] > j + 1 || nums[i] == nums[nums[i] - 1])
                std::swap(nums[i], nums[j--]);
            else
                std::swap(nums[i], nums[nums[i] - 1]);
        }
        return i + 1;
    }
};

int main()
{
    Solution s;

    {
        std::vector<int> nums{1};
        std::cout << s.firstMissingPositive(nums) << std::endl;
    }
    {
        std::vector<int> nums{1, 2, 0};
        std::cout << s.firstMissingPositive(nums) << std::endl;
    }
    {
        std::vector<int> nums{3, 4, -1, 1};
        std::cout << s.firstMissingPositive(nums) << std::endl;
    }
    {
        std::vector<int> nums{7, 8, 9, 11, 12};
        std::cout << s.firstMissingPositive(nums) << std::endl;
    }
    {
        std::vector<int> nums{1, 2, 3, 4};
        std::cout << s.firstMissingPositive(nums) << std::endl;
    }
    {
        std::vector<int> nums{1, 1};
        std::cout << s.firstMissingPositive(nums) << std::endl;
    }
    {
        std::vector<int> nums{2, 2};
        std::cout << s.firstMissingPositive(nums) << std::endl;
    }
}