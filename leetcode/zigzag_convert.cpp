#include <string>
#include <vector>
#include <iostream>

class Solution 
{
public:
    std::string convert(std::string s, int numRows) 
    {
        if (numRows <= 1)
            return s;

        int T = numRows + (numRows - 2);
        int periods = s.size() / T;
        if (s.size() % T)
            periods += 1;

        std::string res;
        res.reserve(s.size());

        for (std::size_t i = 0; i < numRows; i++)
        {
            for (std::size_t j = 0; j < periods; j++)
            {
                std::size_t idx1 = j * T + i;
                if (idx1 < s.size())
                    res.push_back(s[idx1]);

                if (i != 0 && i != numRows - 1)
                {
                    std::size_t idx2 = (j + 1) * T - i;
                    if (idx2 < s.size())
                        res.push_back(s[idx2]);
                }
            }
        }

        return res;
    }
};

int main()
{
    Solution s;

    {
        std::string str("PAYPALISHIRING");
        std::cout << s.convert(str, 3) << std::endl;
    }
    {
        std::string str("PAYPALISHIRING");
        std::cout << s.convert(str, 4) << std::endl;
    }
}