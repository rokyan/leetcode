// https://leetcode.com/problems/the-maze/description/

class Solution
{
public:
    bool hasPath(std::vector<std::vector<int>>& maze, std::vector<int>& start, std::vector<int>& destination)
    {
        std::queue<std::pair<int, int>> q;
        q.push({ start[0], start[1] });
        maze[start[0]][start[1]] = -1;
 
        std::array<int, 4> dr{ 1, 0, -1, 0 };
        std::array<int, 4> dc{ 0, -1, 0, 1 };

        const auto n = std::size(maze);
        const auto m = std::size(maze.front());

        while (!q.empty() && maze[destination[0]][destination[1]] != -1)
        {
            const auto [row, col] = q.front();
            q.pop();

            // std::cout << row << " " << col << std::endl;

            for (auto d = 0; d < 4; d++)
            {
                auto nrow = row + dr[d];
                auto ncol = col + dc[d];

                while (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && maze[nrow][ncol] != 1)
                {
                    nrow += dr[d];
                    ncol += dc[d];
                }

                nrow -= dr[d];
                ncol -= dc[d];

                if ((nrow != row || ncol != col) && maze[nrow][ncol] != -1)
                {
                    maze[nrow][ncol] = -1;
                    q.push({ nrow, ncol });
                }
            }
        }

        return maze[destination[0]][destination[1]] == -1;
    }
};