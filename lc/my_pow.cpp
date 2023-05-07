#include <iostream>
#include <limits>

class Solution 
{
public:
    double myPow(double x, int n) 
    {
        if (n == 0)
            return 1;
        else if (n > 0)
            return pow(x, n);
        else 
        {
            if (n != std::numeric_limits<int>::min())
                return 1.0 / pow(x, -n);
            else 
                return 1.0 / x / pow(x, -(n + 1));
        }
    }

private:
    double pow(double x, int n)
    {
        double res = 1;
        double val = x;
        while (n)
        {
            if (n & 0x1)
                res *= val;
            
            n >>= 1;
            val *= val;
        }
        return res;
    }
};

int main()
{
    Solution s;
    std::cout << s.myPow(2.0, 10) << std::endl;
    std::cout << s.myPow(2.1, 3) << std::endl;
    std::cout << s.myPow(2.0, -2) << std::endl;
}