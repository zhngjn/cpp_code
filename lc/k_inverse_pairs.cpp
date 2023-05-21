#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

class Solution 
{
public:
    int kInversePairs(int n, int k) 
    {
        if (n < 2 || k < 1)
            return 0;
        if (k > n * (n - 1) / 2)
            return 0;

        int inverse_pairs = 0;
        for (std::size_t i = 1; i < n; i++)
        {
            inverse_pairs += kInversePairsStep(n, k, i);
        }
        return inverse_pairs;
    }

private:
    int kInversePairsStep(int n, int k, int i)
    {
        int reverse_pairs = 2 * i - 1;

        std::vector<int> nums(n - 1);
        std::iota(nums.begin(), nums.end(), 0);
        std::swap(nums[0], nums[i - 1]);

        reverse_pairs -= inversionPairs(nums);

        return kInversePairs(n - 1, k - reverse_pairs);
    }

    int inversionPairs(std::vector<int> permutation)
    {
        int inversion_pairs = 0;
        int j = permutation.size() - 1;
        for (std::size_t i = 0; i < permutation.size() - 1; i++)
        {
            if (permutation[i] == i)
                continue;

            while (permutation[j] == j)
                j--;
            bool inversed = permutation[i] > permutation[j];
            std::swap(permutation[i], permutation[j]);
            int increased_inversion_pairs = 2 * std::abs(static_cast<int>(permutation[i]) - static_cast<int>(permutation[j])) - 1;
            if (!inversed)
                increased_inversion_pairs = -increased_inversion_pairs;
            inversion_pairs += increased_inversion_pairs;

            i--;
        }

        return inversion_pairs;
    }
};

int main()
{
    Solution s;

    std::cout << s.kInversePairs(3, 0) << std::endl;
    std::cout << s.kInversePairs(3, 1) << std::endl;
}