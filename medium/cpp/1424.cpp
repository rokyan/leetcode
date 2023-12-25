// https://leetcode.com/problems/diagonal-traverse-ii/

class Solution
{
private:
    struct cell
    {
    public:
        cell(int val, int row, int col)
            : val{ val }
            , row{ row }
            , col{ col }
        {}

        bool operator<(const cell& other) const
        {
            return row + col < other.row + other.col ||
                row + col == other.row + other.col && row > other.row;
        }

    public:
        int val;
        int row;
        int col;
    };

public:
    std::vector<int> findDiagonalOrder(std::vector<std::vector<int>>& nums)
    {
        std::vector<cell> cells;

        for (auto i = 0; i < std::size(nums); i++)
        {
            for (auto j = 0; j < std::size(nums[i]); j++)
            {
                cells.push_back(cell{ nums[i][j], i, j });
            }
        } 

        std::sort(std::begin(cells), std::end(cells));

        std::vector<int> res(std::size(cells));

        std::transform(std::begin(cells), std::end(cells), std::begin(res), [](auto&& e) {
            return e.val;
        });

        return res;
    }
};