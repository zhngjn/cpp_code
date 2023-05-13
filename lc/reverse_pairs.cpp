#include <vector>
#include <algorithm>
#include <numeric>

class Solution 
{
public:
    int reversePairs(std::vector<int>& nums) 
    {
        std::vector<std::size_t> ascending(nums.size());
        std::iota(ascending.begin(), ascending.end(), 0);
        int reverse_pairs = 0;
        std::sort(ascending.begin(), ascending.end(), [&nums, &ascending, &reverse_pairs](std::size_t i, std::size_t j){
            if ()
            return nums[ascending[i]] > 2 * nums[ascending[j]];
        });
    }
};

int main()
{

}