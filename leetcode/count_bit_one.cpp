#include <iostream>
#include <vector>

class Solution 
{
public:
    int countDigitOne(int n) 
    {
        if (n < 0)
            return 0;

        int base = 1, k = 1;
        std::vector<int> pows;
        pows.emplace_back(base);
        while (base < n)
        {
            base <<= 1;
            k += 1;
            pows.emplace_back(base);
        }

        int one_count = 0;
        for (int i = k - 1; i >= 0; i--)
        {
            if (n / pows[i])
                one_count += n - pows[i] + 1;
            if (i > 0)
                one_count += pows[i - 1] * i;
            n = n % pows[i];
            base >>= 1;
        }

        return one_count;
    }
};

int main()
{
    Solution s;

    std::cout << s.countDigitOne(0) << std::endl;
    std::cout << s.countDigitOne(13) << std::endl;
}