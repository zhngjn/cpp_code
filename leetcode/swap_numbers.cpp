#include <iostream>
#include <vector>

class Solution 
{
public:
    std::vector<int> swapNumbers(std::vector<int>& numbers) 
    {
        // a ^ b
        numbers[0] = numbers[0] ^ numbers[1];
        // (a ^ b) ^ b => a
        numbers[1] = numbers[0] ^ numbers[1];
        // (a ^ b) ^ a => b
        numbers[0] = numbers[0] ^ numbers[1];
    }
};