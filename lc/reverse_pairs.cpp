// #include <vector>
// #include <algorithm>
// #include <numeric>
// #include <cstdlib>
// #include <iostream>

// class Solution 
// {
// public:
//     int reversePairs(std::vector<int>& nums) 
//     {
//         if (nums.size() < 2)
//             return 0;

//         std::vector<std::size_t> permutation(nums.size());
//         std::iota(permutation.begin(), permutation.end(), 0);
//         std::stable_sort(
//             permutation.begin(), 
//             permutation.end(), 
//             [&nums](std::size_t i, std::size_t j){
//                 return nums[i] < nums[j];
//         });

//         return inversionPairs(permutation);
//     }

// private:
//     int inversionPairs(std::vector<std::size_t>& permutation)
//     {
//         int inversion_pairs = 0;
//         int j = permutation.size() - 1;
//         for (std::size_t i = 0; i < permutation.size() - 1; i++)
//         {
//             if (permutation[i] == i)
//                 continue;

//             while (permutation[j] == j)
//                 j--;
//             bool inversed = permutation[i] > permutation[j];
//             std::swap(permutation[i], permutation[j]);
//             int increased_inversion_pairs = 2 * std::abs(static_cast<int>(permutation[i]) - static_cast<int>(permutation[j])) - 1;
//             if (!inversed)
//                 increased_inversion_pairs = -increased_inversion_pairs;
//             inversion_pairs += increased_inversion_pairs;

//             i--;
//         }

//         return inversion_pairs;
//     }
// };

// int main()
// {
//     Solution s;

//     {
//         std::vector<int> nums{1,3,2,3,1};
//         std::cout << s.reversePairs(nums) << std::endl;
//     }
//     {
//         std::vector<int> nums{2,4,3,5,1};
//         std::cout << s.reversePairs(nums) << std::endl;
//     }
// }