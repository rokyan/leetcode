// https://leetcode.com/problems/spiral-matrix/description/

class Solution
{
public:
    std::vector<int> spiralOrder(const std::vector<std::vector<int>>& matrix)
    {
        const auto n = std::size(matrix);
        const auto m = std::size(matrix.front());

        auto up = 1;
        auto right = static_cast<int>(m) - 1;
        auto down = static_cast<int>(n) - 1;
        auto left = 0;

        auto taken = 0;
        std::vector<int> res(n * m);

        auto row = 0;
        auto col = 0;

        while (taken < n * m)
        {
            while (col <= right && taken < n * m)
            {
                res[taken++] = matrix[row][col++];
            }

            right--;
            col--;
            row++;

            while (row <= down && taken < n * m)
            {
                res[taken++] = matrix[row++][col];
            }

            down--;
            col--;
            row--;

            while (col >= left && taken < n * m)
            {
                res[taken++] = matrix[row][col--];
            }

            left++;
            col++;
            row--;

            while (row >= up && taken < n * m)
            {
                res[taken++] = matrix[row--][col];
            }

            up++;
            col++;
            row++;
        }

        return res;
    }
};