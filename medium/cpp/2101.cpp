// https://leetcode.com/problems/detonate-the-maximum-bombs/description/

class Solution
{
public:
    int maximumDetonation(std::vector<std::vector<int>>& bombs)
    {
        const auto n = std::size(bombs);

        std::vector<std::vector<int>> g(n);

        for (auto i = 0; i < n; i++)
        {
            const auto& from = bombs[i];

            for (auto j = 0; j < n; j++)
            {
                if (j != i)
                {
                    const auto& to = bombs[j];

                    if (sq(from[0] - to[0]) + sq(from[1] - to[1]) <= sq(from[2]))
                    {
                        g[i].push_back(j);
                    }
                }
            }
        }

        std::vector<char> used(n);
        auto res = 0;

        for (auto i = 0; i < n; i++)
        {
            std::fill(std::begin(used), std::end(used), false);
            res = std::max(res, dfs(i, used, g));
        }

        return res;
    }

private:
    long long sq(int x)
    {
        return 1LL * x * x;
    }

    int dfs(int v, std::vector<char>& used, const std::vector<std::vector<int>>& g)
    {
        used[v] = true;
        auto tot = 0;

        for (auto to : g[v])
        {
            if (!used[to])
            {
                tot += dfs(to, used, g);
            }
        }

        return 1 + tot;
    }
};