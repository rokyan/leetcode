// https://leetcode.com/problems/minimum-moves-to-spread-stones-over-grid/description/

class Solution
{
public:
    int minimumMoves(std::vector<std::vector<int>>& grid)
    {
        std::string state;

        for (auto i = 0; i < 3; i++)
        {
            for (auto j = 0; j < 3; j++)
            {
                state.push_back(grid[i][j]);
            }
        }

        dfs(state);

        return mem[std::string(9, 1)];
    }

private:
    void dfs(std::string& state, int d = 0)
    {
        if (const auto it = mem.find(state); it != std::end(mem) && it->second <= d)
        {
            return;
        }

        mem[state] = d;

        for (auto i = 0; i < 3; i++)
        {
            for (auto j = 0; j < 3; j++)
            {
                if (state[3 * i + j] > 1)
                {
                    if (i - 1 >= 0)
                    {
                        state[3 * i + j]--;
                        state[3 * (i - 1) + j]++;
                        dfs(state, d + 1);
                        state[3 * i + j]++;
                        state[3 * (i - 1) + j]--;
                    }

                    if (i + 1 < 3)
                    {
                        state[3 * i + j]--;
                        state[3 * (i + 1) + j]++;
                        dfs(state, d + 1);
                        state[3 * i + j]++;
                        state[3 * (i + 1) + j]--;
                    }

                    if (j - 1 >= 0)
                    {
                        state[3 * i + j]--;
                        state[3 * i + j - 1]++;
                        dfs(state, d + 1);
                        state[3 * i + j]++;
                        state[3 * i + j - 1]--;
                    }

                    if (j + 1 < 3)
                    {
                        state[3 * i + j]--;
                        state[3 * i + j + 1]++;
                        dfs(state, d + 1);
                        state[3 * i + j]++;
                        state[3 * i + j + 1]--;
                    }
                }
            }
        }
    }

private:
    std::unordered_map<std::string, int> mem;
};