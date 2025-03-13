/**
 * // This is the robot's control interface.
 * // You should not implement it, or speculate about its implementation
 * class Robot {
 *   public:
 *     // Returns true if the cell in front is open and robot moves into the cell.
 *     // Returns false if the cell in front is blocked and robot stays in the current cell.
 *     bool move();
 *
 *     // Robot will stay in the same cell after calling turnLeft/turnRight.
 *     // Each turn will be 90 degrees.
 *     void turnLeft();
 *     void turnRight();
 *
 *     // Clean the current cell.
 *     void clean();
 * };
 */

class Solution
{
private:
    static constexpr std::array<int, 4> drow{-1, 0, 1, 0};
    static constexpr std::array<int, 4> dcol{0, 1, 0, -1};

public:
    void cleanRoom(Robot& robot)
    {
        dfs(robot);
    }

private:
    void dfs(Robot& robot, int dir = 0, int row = 0, int col = 0)
    {
        visited.insert(hash(row, col));
        robot.clean();

        for (auto d = 0; d < 4; d++)
        {
            const auto ndir = (dir + d) % 4;
            const auto nrow = row + drow[ndir];
            const auto ncol = col + dcol[ndir];

            if (visited.find(hash(nrow, ncol)) == std::end(visited) && robot.move())
            {
                dfs(robot, ndir, nrow, ncol);

                for (auto times = 0; times < 2; times++)
                {
                    robot.turnRight();
                }

                robot.move();

                for (auto times = 0; times < 2; times++)
                {
                    robot.turnLeft();
                }
            }

            robot.turnRight();
        }
    }

    int hash(int row, int col)
    {
        return row * 1000 + col;
    }

private:
    std::unordered_set<int> visited;
};