#include <string>
#include <vector>
#include <iostream>

class Solution
{
public:
    std::vector<std::string> generateParenthesis(int n) 
    {
        std::vector<std::string> all_parenthesis;
        
        generateParenthesis(n, 0, 0, "", all_parenthesis);

        return all_parenthesis;
    }

private:
    void generateParenthesis(
        int n, int x, int y, std::string parenthesis, std::vector<std::string>& all_parenthesis)
    {
        if (y >= n)
        {
            all_parenthesis.emplace_back(parenthesis);
            return;
        }

        if (x < n)
            generateParenthesis(n, x + 1, y, parenthesis + "(", all_parenthesis);
        if (y < x)
            generateParenthesis(n, x, y + 1, parenthesis + ")", all_parenthesis);
    }
};

int main()
{
    Solution s;

    {
        const auto res = s.generateParenthesis(1);
        for (const auto& v : res)
            std::cout << v << ", ";
        std::cout << std::endl;
    }
    {
        const auto res = s.generateParenthesis(3);
        for (const auto& v : res)
            std::cout << v << ", ";
        std::cout << std::endl;
    }
}