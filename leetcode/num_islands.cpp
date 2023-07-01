#include <vector>
#include <iostream>

class Solution 
{
public:
    int numIslands(std::vector<std::vector<char>>& grid) 
    {
        std::size_t m = grid.size();
        std::size_t n = grid[0].size();

        int num_islands = 0;
        for (std::size_t i = 0; i < m; i++)
        {
            for (std::size_t j = 0; j < n; j++)
            {
                if (grid[i][j] == '1')
                {
                    dfs(grid, i, j);
                    num_islands++;
                }
            }
        }

        return num_islands;
    }

private:
    void dfs(std::vector<std::vector<char>>& grid, std::size_t i, std::size_t j)
    {
        std::size_t m = grid.size();
        std::size_t n = grid[0].size();

        if (grid[i][j] != '1')
            return;

        grid[i][j] = '2';
        
        if (j > 0)
            dfs(grid, i, j - 1);
        if (i > 0)
            dfs(grid, i - 1, j);
        if (j < n - 1)
            dfs(grid, i, j + 1);
        if (i < m - 1)
            dfs(grid, i + 1, j);
    }
};

int main()
{
    Solution s;

    {
        std::vector<std::vector<char>> grid = 
        {
            {'1','1','0','0','0'},
            {'1','1','0','0','0'},
            {'0','0','1','0','0'},
            {'0','0','0','1','1'}
        };
        std::cout << s.numIslands(grid) << std::endl;
    }
    {
        std::vector<std::vector<char>> grid = 
        {
            {'1','1','1'},
            {'0','1','0'},
            {'1','1','1'}
        };
        std::cout << s.numIslands(grid) << std::endl;
    }
}