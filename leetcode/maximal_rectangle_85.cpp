#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

class Solution 
{
public:
    int maximalRectangle(std::vector<std::vector<char>>& matrix) 
    {
        if (matrix.empty() || matrix[0].empty())
            return 0;

        std::size_t R = matrix.size(), C = matrix[0].size();
        
        std::vector<std::vector<Span>> span_matrix(R);
        for (std::size_t i = 0; i < R; i++)
            span_matrix[i].resize(C);

        std::size_t max_area = 0;

        // boundary
        for (std::size_t j = 0; j < C; j++) {
            if (matrix[0][j] == '0') {
                span_matrix[0][j].r = 0;
                span_matrix[0][j].c = 0;
            }
            else {
                span_matrix[0][j].r = j > 0 ? span_matrix[0][j - 1].r + 1 : 1;
                span_matrix[0][j].c = 1;
                max_area = std::max(max_area, span_matrix[0][j].r);
            }
        }
        for (std::size_t i = 0; i < R; i++) {
            if (matrix[i][0] == '0') {
                span_matrix[i][0].r = 0;
                span_matrix[i][0].c = 0;
            }
            else {
                span_matrix[i][0].r = 1;
                span_matrix[i][0].c = i > 0 ? span_matrix[i - 1][0].c + 1 : 1;
                max_area = std::max(max_area, span_matrix[i][0].c);
            }
        }

        // dp
        for (std::size_t i = 1; i < R; i++) {
            for (std::size_t j = 1; j < C; j++) {
                if (matrix[i][j] == '0') {
                    span_matrix[i][j].r = 0;
                    span_matrix[i][j].c = 0;
                }
                else {
                    span_matrix[i][j].r = span_matrix[i][j - 1].r + 1;
                    span_matrix[i][j].c = span_matrix[i - 1][j].c + 1;

                    if (span_matrix[i][j].r * span_matrix[i][j].c <= max_area)
                        continue;

                    if (span_matrix[i][j].r >= span_matrix[i][j].c) {
                        std::size_t width = span_matrix[i][j].r;
                        std::size_t col_span = span_matrix[i][j].c;
                        for (std::size_t k = 0; k < width; k++) {
                            col_span = std::min(col_span, span_matrix[i][j - k].c);
                            max_area = std::max(max_area, (k + 1) * col_span); 
                        }
                    }
                    else {
                        std::size_t height = span_matrix[i][j].c;
                        std::size_t row_span = span_matrix[i][j].r;
                        for (std::size_t k = 0; k < height; k++) {
                            row_span = std::min(row_span, span_matrix[i - k][j].r);
                            max_area = std::max(max_area, (k + 1) * row_span); 
                        }
                    }
                }
            }
        }

        return max_area;
    }

private:
    struct Span 
    {
        std::size_t r;
        std::size_t c;
    };
};

int main()
{
    Solution s;

    {
        std::vector<std::vector<char>> nums = {
            {'1','0','1','0','0'},
            {'1','0','1','1','1'},
            {'1','1','1','1','1'},
            {'1','0','0','1','0'}
        };
        std::cout << s.maximalRectangle(nums) << std::endl;
    }
}