// https://leetcode.com/problems/count-unguarded-cells-in-the-grid/description/

class Solution
{
public:
    int countUnguarded(int m, int n, std::vector<std::vector<int>>& guards, std::vector<std::vector<int>>& walls)
    {
        std::vector<std::vector<char>> grid(m, std::vector<char>(n));

        for (const auto& guard : guards)
        {
            grid[guard[0]][guard[1]] = 1;
        }

        for (const auto& wall : walls)
        {
            grid[wall[0]][wall[1]] = 2;
        }

        for (auto i = 0; i < m; i++)
        {
            for (auto j = 0, last = 0; j < n; j++)
            {
                update(grid[i][j], last);
            }

            for (auto j = n - 1, last = 0; j >= 0; j--)
            {
                update(grid[i][j], last);
            }
        }

        for (auto j = 0; j < n; j++)
        {
            for (auto i = 0, last = 0; i < m; i++)
            {
                update(grid[i][j], last);
            }

            for (auto i = m - 1, last = 0; i >= 0; i--)
            {
                update(grid[i][j], last);
            }
        }

        auto res = 0;

        for (auto i = 0; i < m; i++)
        {
            for (auto j = 0; j < n; j++)
            {
                if (grid[i][j] == 0)
                {
                    res++;
                }
            }
        }

        return res;
    }

private:
    void update(char& value, int& last)
    {
        if (value == 0)
        {
            if (last == 1)
            {
                value = -1;
            }
        }
        else if (value == 1)
        {
            last = 1;
        }
        else if (value == 2)
        {
            last = 0;
        }  
    }
};