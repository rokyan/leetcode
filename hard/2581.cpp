// https://leetcode.com/problems/count-number-of-possible-root-nodes/description/

class Solution
{
public:
    int rootCount(std::vector<std::vector<int>>& edges, std::vector<std::vector<int>>& guesses, int k)
    {
        const auto n = std::size(edges) + 1;

        std::vector<std::vector<int>> graph(n);

        for (const auto& edge : edges)
        {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        std::vector<std::unordered_set<int>> probe(n);

        for (const auto& guess : guesses)
        {
            probe[guess[0]].insert(guess[1]);
        }

        const auto ra = dfs(0, -1, graph, probe);

        int res = ra >= k;

        dfs2(0, -1, ra, 0, res, k, graph, probe);

        return res;
    }

private:
    int dfs(int v, int p, const std::vector<std::vector<int>>& graph, const std::vector<std::unordered_set<int>>& probe)
    {
        auto tot = 0;

        for (auto to : graph[v])
        {
            if (to != p)
            {
                if (const auto it = probe[v].find(to); it != std::end(probe[v]))
                {
                    tot++;
                }

                tot += dfs(to, v, graph, probe);
            }
        }

        return tot;
    }

    void dfs2(int v, int p, int tot, int cur, int& res, int k,
        const std::vector<std::vector<int>>& graph, const std::vector<std::unordered_set<int>>& probe)
    {
        for (auto to : graph[v])
        {
            if (to != p)
            {
                auto ntot = tot;

                if (const auto it = probe[v].find(to); it != std::end(probe[v]))
                {
                    ntot--;
                }

                auto ncur = cur;

                if (const auto it = probe[to].find(v); it != std::end(probe[to]))
                {
                    ncur++;
                }

                res += ntot + ncur >= k;

                dfs2(to, v, ntot, ncur, res, k, graph, probe);
            }
        }
    }
};