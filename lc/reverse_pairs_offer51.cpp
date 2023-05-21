#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

class Solution 
{
public:
    int reversePairs(std::vector<int>& nums) 
    {
        if (nums.size() < 2)
            return 0;

        std::vector<std::size_t> permutation(nums.size());
        std::iota(permutation.begin(), permutation.end(), 0);
        std::stable_sort(
            permutation.begin(), 
            permutation.end(), 
            [&nums](std::size_t i, std::size_t j){
                return nums[i] < nums[j];
        });
        
        std::cout << "------------" << std::endl;

        return inversionPairs(permutation);
    }

private:
    int inversionPairs(std::vector<std::size_t>& permutation)
    {
        for (auto x : permutation)
        {
            std::cout << x << ",";
        }
        std::cout << std::endl;

        // return 0;

        int inversion_pairs = 0;
        // int j = permutation.size() - 1;
        for (int i = 0; i < permutation.size(); i++)
        {
                        std::cout << "------3333------" << i << std::endl;

            if (permutation[i] == i)
                continue;

            
            int j = permutation[i];
            bool inversed = permutation[i] > permutation[j];
            std::swap(permutation[i], permutation[j]);
            int increased_inversion_pairs = 2 * std::abs(static_cast<int>(permutation[i]) - static_cast<int>(permutation[j])) - 1;
            if (!inversed)
                increased_inversion_pairs = -increased_inversion_pairs;
            inversion_pairs += increased_inversion_pairs;

            i--;

            std::cout << "------2222------" << i << std::endl;

        }

        std::cout << "------1111------" << std::endl;

        return inversion_pairs;
    }
};

int main()
{
    Solution s;

    {
        std::vector<int> nums{7, 5, 6, 4};
        std::cout << s.reversePairs(nums) << std::endl;
    }
    {
        std::vector<int> nums{1, 2, 1, 2, 1};
        std::cout << s.reversePairs(nums) << std::endl;
    }
}