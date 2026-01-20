// https://leetcode.com/problems/find-the-last-marked-nodes-in-tree/description/

class Solution
{
public:
    std::vector<int> lastMarkedNodes(const std::vector<std::vector<int>>& edges)
    {
        const int n = edges.size() + 1;

        std::vector<std::vector<int>> graph(n);

        for (const auto& edge : edges)
        {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        std::vector<int> dst(n, -1);
        dst[0] = 0;

        dfs(0, graph, dst);

        const int v = std::distance(dst.begin(), std::max_element(dst.begin(), dst.end()));

        std::fill(dst.begin(), dst.end(), -1);
        dst[v] = 0;

        dfs(v, graph, dst);

        const int u = std::distance(dst.begin(), std::max_element(dst.begin(), dst.end()));

        std::vector<int> dst2(n, -1);
        dst2[u] = 0;

        dfs(u, graph, dst2);

        std::vector<int> res(n);

        for (int i = 0; i < n; i++)
        {
            if (dst[i] > dst2[i])
            {
                res[i] = v;
            }
            else
            {
                res[i] = u;
            }
        }

        return res;
    }

private:
    void dfs(int v, const std::vector<std::vector<int>>& graph, std::vector<int>& dst)
    {
        for (int to : graph[v])
        {
            if (dst[to] == -1)
            {
                dst[to] = dst[v] + 1;
                dfs(to, graph, dst);
            }
        }
    }
};