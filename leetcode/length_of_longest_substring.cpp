#include <iostream>
#include <string>
#include <algorithm>

class Solution 
{
public:
    int lengthOfLongestSubstring(std::string s) 
    {
        int last_pos[128];
        for (std::size_t i = 0; i < 128; i++)
            last_pos[i] = -1;

        int max_length = 0;
        int last_length = 0;
        for (std::size_t i = 0; i < s.size(); i++)
        {
            if (i - last_pos[s[i]] > last_length)
                last_length += 1;
            else
                last_length = i - last_pos[s[i]];

            last_pos[s[i]] = i;

            max_length = std::max(max_length, last_length);
        }

        return max_length;
    }
};

int main()
{
    Solution s;

    std::cout << s.lengthOfLongestSubstring("abcabcbb") << std::endl;
    std::cout << s.lengthOfLongestSubstring("bbbbb") << std::endl;
    std::cout << s.lengthOfLongestSubstring("pwwkew") << std::endl;
}