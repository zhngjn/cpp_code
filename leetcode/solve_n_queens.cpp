#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>

#include "util/to_string.hpp"

class Solution 
{
public:
    std::vector<std::vector<std::string>> solveNQueens(int n) 
    {
        if (n < 1)
            return {};

        std::vector<std::vector<std::size_t>> solutions;

        std::queue<State> Q;
        for (std::size_t i = 0; i < n; i++)
            Q.push(State{n, {i}});
        while (!Q.empty()) 
        {
            State cur = Q.front();
            Q.pop();

            if (cur.finished())
            {
                solutions.emplace_back(cur.sol);
                continue;
            }

            std::vector<std::size_t> next_positions = cur.findNextPositions();
            if (next_positions.empty())
                continue;

            for (const auto next_position : next_positions)
            {
                std::vector<std::size_t> next_sol = cur.sol;
                next_sol.emplace_back(next_position);
                Q.push(State{n, next_sol});
            }
        }

        std::vector<std::vector<std::string>> solutions_str;
        for (const auto& solution : solutions)
        {
            solutions_str.emplace_back(std::move(convertSolution(solution)));
        }

        return solutions_str;
    }

private:
    struct State
    {
        bool finished() const
        {
            return sol.size() == N;
        }

        std::vector<std::size_t> findNextPositions() const
        {
            std::size_t cur_row = sol.size();
            std::vector<bool> avail_flags(N, true);
            for (std::size_t i = 0; i < sol.size(); i++)
            {
                avail_flags[sol[i]] = false;
                if (sol[i] + (cur_row - i) < N)
                    avail_flags[sol[i] + (cur_row - i)] = false;
                if (sol[i] >= cur_row - i)
                    avail_flags[sol[i] - (cur_row - i)] = false;
            }

            std::vector<std::size_t> avail_positions;
            for (std::size_t i = 0; i < avail_flags.size(); i++)
                if (avail_flags[i])
                    avail_positions.emplace_back(i);

            return avail_positions;
        }

        int N;
        std::vector<std::size_t> sol;
    };

    std::vector<std::string> convertSolution(const std::vector<std::size_t>& solution)
    {
        std::size_t N = solution.size();

        std::vector<std::string> solution_str(N);
        for (std::size_t i = 0; i < N; i++)
            solution_str[i].resize(N, '.');

        for (std::size_t i = 0; i < solution.size(); i++)
            solution_str[i][solution[i]] = 'Q';

        return solution_str;
    }
};

int main()
{
    Solution s;

    std::cout << util::toString(s.solveNQueens(3)) << std::endl;
    std::cout << util::toString(s.solveNQueens(4)) << std::endl;
    std::cout << util::toString(s.solveNQueens(1)) << std::endl;
}