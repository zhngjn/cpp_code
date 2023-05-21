#include <iostream>
#include <vector>

#include "util/to_string.hpp"

class Solution 
{
public:
    void solve(std::vector<std::vector<char>>& board) 
    {
        std::size_t m = board.size();
        std::size_t n = board[0].size();

        if (m < 3 || n < 3)
            return;

        for (std::size_t i = 0; i < m; i++)
        {
            for (std::size_t j = 0; j < n; j++)
            {
                if (board[i][j] == 'O')
                {
                    bool is_surrounded = dfsFound(board, i, j);
                    if (is_surrounded)
                        dfsModify(board, i, j, 'X');
                }
            }
        }

        for (std::size_t i = 0; i < m; i++)
        {
            for (std::size_t j = 0; j < n; j++)
            {
                if (board[i][j] == 'A')
                {
                    board[i][j] = 'O';
                }
            }
        }
    }

private:
    bool dfsFound(std::vector<std::vector<char>>& board, std::size_t i, std::size_t j)
    {
        std::size_t m = board.size();
        std::size_t n = board[0].size();

        bool is_surrounded = true;

        if (board[i][j] != 'O') 
            return is_surrounded;

        board[i][j] = 'A';

        if (i == 0 || i == m - 1 || j == 0 || j == n - 1)
            is_surrounded = false;
        
        if (j > 0)
        {
            bool ret = dfsFound(board, i, j - 1);
            is_surrounded = is_surrounded && ret;
        }
        if (i > 0)
        {
            bool ret = dfsFound(board, i - 1, j);
            is_surrounded = is_surrounded && ret;
        }
        if (j < n - 1)
        {
            bool ret = dfsFound(board, i, j + 1);
            is_surrounded = is_surrounded && ret;
        }
        if (i < m - 1)
        {
            bool ret = dfsFound(board, i + 1, j);
            is_surrounded = is_surrounded && ret;
        }

        return is_surrounded;
    }

    void dfsModify(std::vector<std::vector<char>>& board, std::size_t i, std::size_t j, char c)
    {
        std::size_t m = board.size();
        std::size_t n = board[0].size();

        if (board[i][j] != 'A')
            return;

        board[i][j] = c;
        
        if (j > 0)
            dfsModify(board, i, j - 1, c);
        if (i > 0)
            dfsModify(board, i - 1, j, c);
        if (j < n - 1)
            dfsModify(board, i, j + 1, c);
        if (i < m - 1)
            dfsModify(board, i + 1, j, c);
    }
};

int main()
{
    Solution s;

    {
        std::vector<std::vector<char>> board = 
        {
            {'X','X','X','X'},
            {'X','O','O','X'},
            {'X','X','O','X'},
            {'X','O','X','X'}
        };
        s.solve(board);
        std::cout << util::toString(board) << std::endl;
    }
    {
        std::vector<std::vector<char>> board = 
        {
            {'X','O','X'},
            {'O','X','O'},
            {'X','O','X'}
        };
        s.solve(board);
        std::cout << util::toString(board) << std::endl;
    }
    {
        std::vector<std::vector<char>> board = 
        {
            {'O','X','O','O','O','O','O','O','O'},
            {'O','O','O','X','O','O','O','O','X'},
            {'O','X','O','X','O','O','O','O','X'},
            {'O','O','O','O','X','O','O','O','O'},
            {'X','O','O','O','O','O','O','O','X'},
            {'X','X','O','O','X','O','X','O','X'},
            {'O','O','O','X','O','O','O','O','O'},
            {'O','O','O','X','O','O','O','O','O'},
            {'O','O','O','O','O','X','X','O','O'}
        };
        s.solve(board);
        std::cout << util::toString(board) << std::endl;
    }
}