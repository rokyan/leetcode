// https://leetcode.com/problems/cyclically-rotating-a-grid/description/

class Solution
{
public:
    std::vector<std::vector<int>> rotateGrid(std::vector<std::vector<int>>& grid, int k)
    {
        const int n = grid.size();
        const int m = grid.front().size();

        int row = 0;
        int col = 0;
        int height = n;
        int width = m;

        for (int times = 0; times < std::min(n / 2, m / 2); times++)
        {
            // Rotate

            std::vector<int> elems;
            elems.reserve(2 * (n + m));

            for (int i = 0; i + 1 < width; i++)
            {
                elems.push_back(grid[row][col++]);
            }

            for (int i = 0; i + 1 < height; i++)
            {
                elems.push_back(grid[row++][col]);
            }

            for (int i = 0; i + 1 < width; i++)
            {
                elems.push_back(grid[row][col--]);
            }

            for (int i = 0; i + 1 < height; i++)
            {
                elems.push_back(grid[row--][col]);
            }

            std::rotate(elems.begin(), elems.begin() + k % elems.size(), elems.end());

            int pos = 0;

            for (int i = 0; i + 1 < width; i++)
            {
                grid[row][col++] = elems[pos++];
            }

            for (int i = 0; i + 1 < height; i++)
            {
                grid[row++][col] = elems[pos++];
            }

            for (int i = 0; i + 1 < width; i++)
            {
                grid[row][col--] = elems[pos++];
            }

            for (int i = 0; i + 1 < height; i++)
            {
                grid[row--][col] = elems[pos++];
            }

            // Move next
            row++;
            col++;

            width -= 2;
            height -= 2;
        }

        return grid;
    }
};