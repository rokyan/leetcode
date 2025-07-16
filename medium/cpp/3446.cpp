// https://leetcode.com/problems/sort-matrix-by-diagonals/description/

class Solution
{
public:
    std::vector<std::vector<int>> sortMatrix(std::vector<std::vector<int>>& grid)
    {
        const auto n = std::size(grid);

        std::vector<int> buffer(n);

        for (auto r = 0; r < n; r++)
        {
            auto c = 0;
            auto rr = r;
            auto p = 0;

            while (rr < n && c < n)
            {
                buffer[p++] = grid[rr++][c++];
            }

            std::sort(std::begin(buffer), std::next(std::begin(buffer), p), std::greater<>{});

            c = 0;
            rr = r;
            p = 0;

            while (rr < n && c < n)
            {
                grid[rr++][c++] = buffer[p++];
            }
        }

        for (auto c = 1; c < n; c++)
        {
            auto r = 0;
            auto cc = c;
            auto p = 0;

            while (r < n && cc < n)
            {
                buffer[p++] = grid[r++][cc++];
            }

            std::sort(std::begin(buffer), std::next(std::begin(buffer), p));

            r = 0;
            cc = c;
            p = 0;

            while (r < n && cc < n)
            {
                grid[r++][cc++] = buffer[p++];
            }
        }

        return grid;
    }
};