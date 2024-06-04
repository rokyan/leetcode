// https://leetcode.com/problems/count-nodes-with-the-highest-score/description/

class Solution
{
public:
    int countHighestScoreNodes(std::vector<int>& parents)
    {
        const auto n = std::size(parents);

        std::vector<std::vector<int>> graph(n);

        for (auto v = 1; v < n; v++)
        {
            graph[parents[v]].push_back(v);
        }

        auto res = 0;
        auto hsf = 0LL;

        dfs(0, -1, n, graph, res, hsf);

        return res;
    }

private:
    int dfs(int v, int p, int n, const std::vector<std::vector<int>>& graph, int& res, long long& hsf)
    {
        auto tot = 1;
        auto m = 1LL;

        for (auto to : graph[v])
        {
            if (to != p)
            {
                const auto s = dfs(to, v, n, graph, res, hsf);
                tot += s;
                m *= s;
            }
        }

        m *= std::max(1, n - tot);

        if (m > hsf)
        {
            hsf = m;
            res = 1;
        }
        else if (m == hsf)
        {
            res++;
        }

        return tot;
    }
};