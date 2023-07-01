#include <iostream>
#include <string>
#include <vector>
#include <numeric>

class Solution 
{
public:
    std::string getPermutation(int n, int k) 
    {
        if (n < 1 || k < 1)
            return "";

        std::vector<int> factorials = calcFactorials(n);
        std::vector<int> flags(n, 0);
        
        std::string res;
        k--;
        for (int i = n - 1; i >= 0; i--)
        {
            int num = calcNumAtPos(k, i, factorials, flags);
            res += ('0' + num);
        }

        return res;
    }

private:
    std::vector<int> calcFactorials(int n)
    {
        std::vector<int> factorials(n);
        int k = 1;
        factorials[0] = k;
        for (int i = 2; i < n; i++)
        {
            k *= i;
            factorials[i - 1] = k;
        }
        return factorials;
    }

    int calcNumAtPos(int& k, int i, const std::vector<int>& factorials, std::vector<int>& flags)
    {
        if (i == 0)
        {
            for (int i = 0; i < flags.size(); i++)
                if (!flags[i])
                    return i + 1;
            // this should not happen when k is in valid range
            return 0;
        }
        else
        {
            int q = k / factorials[i - 1];
            k = k % factorials[i - 1];

            int c = 0, i = 0;
            for (; i < flags.size() && c < q + 1; i++)
                if (!flags[i])
                    c++;
            flags[i - 1] = 1;

            return i;
        }
    }
};

int main()
{
    Solution s;

    std::cout << s.getPermutation(3, 3) << std::endl;
    std::cout << s.getPermutation(4, 9) << std::endl;
    std::cout << s.getPermutation(3, 1) << std::endl;
}