https://leetcode.com/problems/k-highest-ranked-items-within-a-price-range/description/

class Solution
{
private:
    struct cell
    {
    public:
        cell(int distance, int price, int row, int col)
            : distance{ distance }
            , price{ price }
            , row{ row }
            , col{ col }
        {}

        bool operator<(const cell& other) const noexcept
        {
            return distance < other.distance ||
                distance == other.distance && price < other.price ||
                distance == other.distance && price == other.price && row < other.row ||
                distance == other.distance && price == other.price && row == other.row && col < other.col;
        }

    public:
        int distance;
        int price;
        int row;
        int col;
    };
public:
    std::vector<std::vector<int>> highestRankedKItems(std::vector<std::vector<int>>& grid, std::vector<int>& pricing, std::vector<int>& start, int k) 
    {
        const auto n = std::size(grid);
        const auto m = std::size(grid.front());

        std::queue<std::pair<int, int>> q;
        std::vector<std::vector<char>> visited(n, std::vector<char>(m));
        std::vector<std::vector<int>> dst(n, std::vector<int>(m));
        std::vector<cell> cells;

        std::array<int, 4> di{ 0, -1, 0, 1 };
        std::array<int, 4> dj{ -1, 0, 1, 0 };

        visited[start[0]][start[1]] = true;
        q.push({ start[0], start[1] });

        while (!q.empty())
        {
            const auto [i, j] = q.front();
            q.pop();

            if (grid[i][j] >= pricing[0] && grid[i][j] <= pricing[1])
            {
                cells.emplace_back(dst[i][j], grid[i][j], i, j);
            }

            for (auto k = 0; k < 4; k++)
            {
                const auto ni = i + di[k];
                const auto nj = j + dj[k];

                if (ni >= 0 && ni < n && nj >= 0 && nj < m && !visited[ni][nj] && grid[ni][nj])
                {
                    visited[ni][nj] = true;
                    dst[ni][nj] = dst[i][j] + 1;
                    q.push({ni, nj });
                }
            }
        }

        const auto take = std::min<std::size_t>(std::size(cells), k);

        std::partial_sort(std::begin(cells), std::begin(cells) + take, std::end(cells));

        std::vector<std::vector<int>> res(take);

        for (auto i = 0; i < take; i++)
        {
            res[i] = { cells[i].row, cells[i].col };
        }

        return res;
    }
};