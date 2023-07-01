#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>

#include "util/to_string.hpp"

class Solution 
{
public:
    std::vector<std::string> removeInvalidParentheses(std::string s) 
    {
        if (s.empty())
            return {""};

        std::vector<std::string> valid_parentheses;

        int left_paren_num = 0, right_paren_num = 0;
        for (const auto c : s)
        {
            if (c == '(') 
                left_paren_num++;
            else if (c == ')') 
                right_paren_num++;
        }
        if (left_paren_num == 0 && right_paren_num == 0)
            return {s};
        
        // bfs
        std::size_t max_length = 0;
        std::queue<State> Q;
        Q.push({"", 0, 0, 0});
        while (!Q.empty())
        {
            State cur = Q.front();
            Q.pop();

            if (cur.next_pos == s.size())
            {
                if (cur.valid() && cur.str.size() >= max_length)
                {
                    valid_parentheses.emplace_back(cur.str);
                    max_length = cur.str.size();
                }
                continue;
            }

            // prune
            if (right_paren_num - cur.right_counter < cur.left_counter - cur.right_counter)
                continue;
            if (cur.str.size() + (s.size() - cur.next_pos) < max_length)
                continue;

            char c = s[cur.next_pos];
            if (c == '(')
            {
                std::size_t i = cur.next_pos;
                while (i < s.size() && s[i] == '(')
                    i++;
                // greedy to speedup
                for (int j = i - cur.next_pos; j >= 0; j--)
                {
                    // prune
                    if (right_paren_num - cur.right_counter < cur.left_counter + j - cur.right_counter)
                        continue;
                    if (cur.str.size() + j + (s.size() - i) < max_length)
                        break;

                    Q.push({cur.str + std::string(j, '('), i, cur.left_counter + j, cur.right_counter});
                }
            }
            else if (c == ')')
            {
                std::size_t i = cur.next_pos;
                while (i < s.size() && s[i] == ')')
                    i++;
                std::size_t k = std::min(i - cur.next_pos, cur.left_counter - cur.right_counter);
                // greedy to speedup
                for (int j = k; j >= 0; j--)
                {
                    // prune, but don't needed here
                    if (right_paren_num - cur.right_counter < cur.left_counter - cur.right_counter)
                        continue;
                    if (cur.str.size() + j + (s.size() - i) < max_length)
                        break;

                    Q.push({cur.str + std::string(j, ')'), i, cur.left_counter, cur.right_counter + j});
                }
            }
            else
            {   
                std::size_t i = cur.next_pos;
                while (i < s.size() && s[i] != '(' && s[i] != ')')
                    i++;
                Q.push({cur.str + s.substr(cur.next_pos, i - cur.next_pos), i, cur.left_counter, cur.right_counter});
            }
        }

        if (valid_parentheses.empty())
            return valid_parentheses;

        std::sort(
            valid_parentheses.begin(), 
            valid_parentheses.end(), 
            [](const std::string& lhs, const std::string& rhs){
                return lhs.size() > rhs.size()
                    || (lhs.size() == rhs.size() && lhs < rhs);
            });
        valid_parentheses.erase(
            std::find_if(
                valid_parentheses.begin(), 
                valid_parentheses.end(), 
                [&valid_parentheses](const std::string& s){
                    return s.size() != valid_parentheses[0].size();
                }),
            valid_parentheses.end());
        valid_parentheses.erase(
            std::unique(
                valid_parentheses.begin(), 
                valid_parentheses.end()),
            valid_parentheses.end());
        
        return valid_parentheses;
    }

private:
    struct State
    {
        bool valid() const
        {
            return left_counter == right_counter;
        }

        std::string str;
        std::size_t next_pos;
        std::size_t left_counter;
        std::size_t right_counter;
    };
};

int main()
{
    Solution s;

    std::cout << util::toString(s.removeInvalidParentheses("()())()")) << std::endl;
    std::cout << util::toString(s.removeInvalidParentheses("(a)())()")) << std::endl;
    std::cout << util::toString(s.removeInvalidParentheses(")(")) << std::endl;
}