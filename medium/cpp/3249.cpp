// https://leetcode.com/problems/count-the-number-of-good-nodes/description/

class Solution
{
public:
    int countGoodNodes(std::vector<std::vector<int>>& edges)
    {
        const auto n = std::size(edges) + 1;

        std::vector<std::vector<int>> graph(n);

        for (const auto& edge : edges)
        {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        auto res = 0;

        static_cast<void>(dfs(0, -1, graph, res));

        return res;
    }

private:
    int dfs(int v, int parent, const std::vector<std::vector<int>>& graph, int& res)
    {
        auto s = -1;
        auto tot = 1;
        auto valid = true;

        for (auto to : graph[v])
        {
            if (to != parent)
            {
                auto ss = dfs(to, v, graph, res);

                if (s == -1)
                {
                    s = ss;
                }
                else
                { 
                    valid &= s == ss;
                }

                tot += ss;
            }
        }

        if (valid)
        {
            res++;
        }

        return tot;
    }
};