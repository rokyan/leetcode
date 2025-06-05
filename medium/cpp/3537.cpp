// https://leetcode.com/problems/fill-a-special-grid/description/

class Solution
{
public:
    std::vector<std::vector<int>> specialGrid(int n)
    {
        std::vector<std::vector<int>> res(1 << n, std::vector<int>(1 << n));

        fill(res, 1 << n, 0, 0, (1 << n) - 1);

        return res;
    }

private:
    void fill(std::vector<std::vector<int>>& res, int side, int num, int i, int j)
    {
        if (side == 1)
        {
            res[i][j] = num;
        }
        else
        {
            const auto nextSide = side >> 1;

            fill(res, nextSide, num, i, j);
            fill(res, nextSide, num + nextSide * nextSide, i + nextSide, j);
            fill(res, nextSide, num + 2 * nextSide * nextSide, i + nextSide, j - nextSide);
            fill(res, nextSide, num + 3 * nextSide * nextSide, i, j - nextSide);
        }
    }
};