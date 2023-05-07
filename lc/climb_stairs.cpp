#include <numeric>
#include <vector>
#include <iostream>

class Solution 
{
public:
    unsigned long long climbStairs(unsigned long long n) 
    {
        if (n <= 1)
            return 1;

        unsigned long long k = n / 2;
        // C(n - k, k) when k = 0
        unsigned long long num = 0;
        unsigned long long next = 1;

        num += next;
        for (unsigned long long i = 0; i < k; i++)
        {
            next = next * (n - 2 * i) * (n - 2 * i - 1) / (i + 1) / (n - i);
            num += next;
        }

        return num;
    }
};

int main()
{
    Solution s;

    std::cout << s.climbStairs(2) << std::endl;
    std::cout << s.climbStairs(3) << std::endl;
}