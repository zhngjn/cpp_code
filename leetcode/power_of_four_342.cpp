#include <iostream>

class Solution 
{
public:
    bool isPowerOfFour(int n) 
    {
        if (n <= 0)
            return false;
        if (n == 1)
            return true;

        if (n & (n - 1))
            return false;

        while (n > 1)
            n >>= 2;
        return n == 1;
    }
};

int main()
{
    Solution s;

    std::cout << s.isPowerOfFour(16) << std::endl;
    std::cout << s.isPowerOfFour(5) << std::endl;
}