#include <iostream>
#include <vector>

class Solution 
{
public:
    bool isBipartite(std::vector<std::vector<int>>& graph) 
    {
        std::size_t N = graph.size();
        std::vector<Color> colors(N);
        std::size_t counter = 0;
        while (counter < N)
        {
            std::size_t u = 0;
            while (colors[u] != Unfilled)
                u++;
            
            // a new cc
            colors[u] = Red;
            counter++;
            bool is_cc_bipartite = dfs(graph, u, colors, counter);
            if (!is_cc_bipartite)
                return false;
        }

        return true;
    }

private:
    using Color = int;
    static constexpr Color Unfilled = 0;
    static constexpr Color Red = 1;
    static constexpr Color Green = 2;

    bool dfs(const std::vector<std::vector<int>>& graph, std::size_t u, std::vector<Color>& colors, std::size_t& counter)
    {
        bool res = true;
        for (const auto v : graph[u])
        {
            if (colors[v] == Unfilled)
            {
                colors[v] = 3 - colors[u];
                counter++;
                res = res && dfs(graph, v, colors, counter);
            }
            else if (colors[v] == colors[u])
                res = false;
        }
        return res;
    }
};

int main()
{
    Solution s;

    {
        std::vector<std::vector<int>> graph{{1,2,3},{0,2},{0,1,3},{0,2}};
        std::cout << s.isBipartite(graph) << std::endl;
    }
    {
        std::vector<std::vector<int>> graph{{1,3},{0,2},{1,3},{0,2}};
        std::cout << s.isBipartite(graph) << std::endl;
    }
    {
        std::vector<std::vector<int>> graph{{3,4,6},{3,6},{3,6},{0,1,2,5},{0,7,8},{3},{0,1,2,7},{4,6},{4},{}};
        std::cout << s.isBipartite(graph) << std::endl;
    }
}