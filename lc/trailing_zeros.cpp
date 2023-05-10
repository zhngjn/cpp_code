#include <iostream>
#include <cmath>

class Solution 
{
public:
    int trailingZeroes(int n) 
    {
        if (n <= 0)
            return 0;
    
        int res = 0;

        long long base = 5;
        while (n >= base)
        {
            res += n / base;
            base *= 5;
        }

        return res;
    }
};

int main()
{
    Solution s;
    // 1
    std::cout << s.trailingZeroes(5) << std::endl;
    // 10
    std::cout << s.trailingZeroes(45) << std::endl;
    // 33
    std::cout << s.trailingZeroes(137) << std::endl;
    // 156
    std::cout << s.trailingZeroes(625) << std::endl;
    // 253
    std::cout << s.trailingZeroes(1024) << std::endl;
}