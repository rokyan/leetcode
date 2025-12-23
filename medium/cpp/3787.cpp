// https://leetcode.com/problems/find-diameter-endpoints-of-a-tree/description/

class Solution
{
private:
    using graph_type = std::vector<std::vector<int>>;

public:
    std::string findSpecialNodes(int n, const std::vector<std::vector<int>>& edges)
    {
        graph_type graph = build_graph(n, edges);

        std::queue<int> q;
        q.push(0);

        std::vector<int> dst(n, 2 * n);
        dst[0] = 0;

        int max_dst = 0;

        while (!q.empty())
        {
            const int v = q.front();
            q.pop();

            for (int to : graph[v])
            {
                if (dst[to] == 2 * n)
                {
                    dst[to] = dst[v] + 1;
                    q.push(to);
                    max_dst = std::max(max_dst, dst[to]);
                }
            }
        }

        std::string res(n, '0');

        int next_start = 0;

        for (int v = 0; v < n; v++)
        {
            if (dst[v] == max_dst)
            {
                res[v] = '1';
                next_start = v;
            }
        }

        std::ranges::fill(dst, 2 * n);
        dst[next_start] = 0;

        q.push(next_start);

        max_dst = 0;

        while (!q.empty())
        {
            const int v = q.front();
            q.pop();

            for (int to : graph[v])
            {
                if (dst[to] == 2 * n)
                {
                    dst[to] = dst[v] + 1;
                    q.push(to);
                    max_dst = std::max(max_dst, dst[to]);
                }
            }
        }

        for (int v = 0; v < n; v++)
        {
            if (dst[v] == max_dst)
            {
                res[v] = '1';
            }
        }

        return res;
    }

private:
    graph_type build_graph(int n, const std::vector<std::vector<int>>& edges)
    {
        graph_type graph(n);

        for (const auto& edge : edges)
        {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        return graph;
    }
};