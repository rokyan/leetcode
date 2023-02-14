// https://leetcode.com/problems/most-profitable-path-in-a-tree/description/

class Solution
{
public:
    int mostProfitablePath(std::vector<std::vector<int>>& edges, int bob, std::vector<int>& amount)
    {
        const auto n = std::size(amount);

        std::vector<std::vector<int>> graph(n);

        for (const auto& edge : edges)
        {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        std::vector<int> dst(n);
        std::vector<int> par(n, -1);
        par[0] = 0;

        dfs(0, 0, graph, dst, par);

        const auto bob_dst = dst[bob];

        for (auto i = 0; i < (bob_dst + 1) / 2; i++)
        {
            amount[bob] = 0;
            bob = par[bob];
        }

        if (bob_dst % 2 == 0)
        {
            amount[bob] /= 2;
        }

        auto res = std::numeric_limits<int>::min();

        std::fill(std::begin(par), std::end(par), -1);
        par[0] = 0;

        solve(0, 0, res, par, graph, amount);

        return res;
    }

private:
    void dfs(int v, int d, const std::vector<std::vector<int>>& graph, std::vector<int>& dst, std::vector<int>& par)
    {
        for (auto to : graph[v])
        {
            if (par[to] == -1)
            {
                par[to] = v;
                dst[to] = dst[v] + 1;

                dfs(to, d + 1, graph, dst, par);
            }
        }
    }

    void solve(int v, int acc, int& res, std::vector<int>& par, const std::vector<std::vector<int>>& graph, const std::vector<int>& amount)
    {
        auto leaf = true;
        acc += amount[v];
  
        for (auto to : graph[v])
        {
            if (par[to] == -1)
            {
                leaf = false;
                par[to] = v;

                solve(to, acc, res, par, graph, amount);
            }
        }

        if (leaf)
        {
            res = std::max(res, acc);
        }
    }
};