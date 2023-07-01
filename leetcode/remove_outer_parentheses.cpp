#include <iostream>
#include <string>
#include <stack>

class Solution 
{
public:
    std::string removeOuterParentheses(std::string s) 
    {
        if (s.empty())
            return "";

        std::string res;
        res.reserve(s.size());
        
        std::size_t counter = 0;
        std::size_t i = 0, j = i;
        while (j < s.size())
        {
            if (s[j] == '(')
            {
                counter++;
                j++;
            }
            else
            {
                counter--;
                if (counter == 0)
                {
                    res += s.substr(i + 1, j - i- 1);
                    i = j + 1;
                    j = i;
                }
                else
                    j++;
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
    std::cout << s.removeOuterParentheses("(()())(())") << std::endl;
    std::cout << s.removeOuterParentheses("(()())(())(()(()))") << std::endl;
    std::cout << s.removeOuterParentheses("()()") << std::endl;
}