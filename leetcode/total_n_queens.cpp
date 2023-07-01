#include <iostream>
#include <vector>
#include <queue>

class Solution 
{
public:
    int totalNQueens(int n) 
    {
        if (n < 1)
            return 0;

        std::size_t num_solutions = 0;

        std::vector<std::size_t> cols(n);
        dfs(cols, 0, num_solutions);

        return num_solutions;
    }

private:
    void dfs(std::vector<std::size_t>& cols, std::size_t i, std::size_t& num_solutions)
    {
        std::size_t N = cols.size();
        if (i == N)
        {
            num_solutions++;
            return;
        }

        std::vector<bool> avail_flags(N, true);
        for (std::size_t j = 0; j < i; j++)
        {
            avail_flags[cols[j]] = false;
            if (cols[j] + (i - j) < N)
                avail_flags[cols[j] + (i - j)] = false;
            if (cols[j] >= i - j)
                avail_flags[cols[j] - (i - j)] = false;
        }
        
        for (std::size_t j = 0; j < avail_flags.size(); j++)
        {
            if (avail_flags[j])
            {
                cols[i] = j;
                dfs(cols, i + 1, num_solutions);
            }
        }
    }
};

int main()
{
    Solution s;

    std::cout << s.totalNQueens(4) << std::endl;
    std::cout << s.totalNQueens(1) << std::endl;
    std::cout << s.totalNQueens(3) << std::endl;
}