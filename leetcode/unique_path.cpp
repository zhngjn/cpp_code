#include <iostream>
#include <vector>
#include <algorithm>

class Solution 
{
public:
    int uniquePaths(int m, int n) 
    {
        std::vector<std::vector<int>> paths;
        paths.resize(m);
        for (std::size_t i = 0; i < m; i++)
            paths[i].resize(n, 0);

        // init
        for (std::size_t i = 0; i < m; i++)
            paths[i][0] = 1;
        for (std::size_t i = 0; i < n; i++)
            paths[0][i] = 1;

        // dp
        int k = std::min(m, n);
        for (std::size_t i = 1; i < k; i++)
        {
            if (i < n)
                for (int x = i; x < m; x++)
                    paths[x][i] = paths[x][i - 1] + paths[x - 1][i];
            if (i < m)
                for (int x = i; x < n; x++)
                    paths[i][x] = paths[i][x - 1] + paths[i - 1][x];
        }

        return paths[m - 1][n - 1];
    }
};

int main()
{
    Solution s;

    // 6
    std::cout << s.uniquePaths(3, 3) << std::endl;
    // 28
    std::cout << s.uniquePaths(3, 7) << std::endl;
}