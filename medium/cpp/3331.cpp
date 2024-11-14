// https://leetcode.com/problems/find-subtree-sizes-after-changes/description/

class Solution
{
public:
    std::vector<int> findSubtreeSizes(const std::vector<int>& parent, const std::string& s)
    {
        const auto n = std::size(parent);

        std::vector<std::vector<int>> graph(n);

        for (auto v = 0; v < n; v++)
        {
            const auto p = parent[v];

            if (p != -1)
            {
                graph[p].push_back(v);
            }
        }

        std::vector<int> last(26, -1);
        std::vector<std::vector<int>> ngraph(n);

        dfs(0, -1, graph, last, s, ngraph);

        std::vector<int> ss(n, -1);

        for (auto v = 0; v < n; v++)
        {
            if (ss[v] == -1)
            {
                dfs2(v, ngraph, ss);
            }
        }

        return ss;
    }

private:
    void dfs(int v, int p, const std::vector<std::vector<int>>& graph,
        std::vector<int>& last, const std::string& s, std::vector<std::vector<int>>& ngraph)
    {
        auto u = last[s[v] - 'a'];

        if (u != -1)
        {
            ngraph[u].push_back(v);
        }
        else if (p != -1)
        {
            ngraph[p].push_back(v);
        }

        last[s[v] - 'a'] = v;

        for (auto to : graph[v])
        {
            dfs(to, v, graph, last, s, ngraph);
        }

        last[s[v] - 'a'] = u;
    }

    void dfs2(int v, const std::vector<std::vector<int>>& graph, std::vector<int>& ss)
    {
        ss[v] = 1;

        for (auto to : graph[v])
        {
            dfs2(to, graph, ss);
            ss[v] += ss[to];
        }
    }
};