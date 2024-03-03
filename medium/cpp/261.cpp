// https://leetcode.com/problems/graph-valid-tree/description/

class Solution
{
public:
    bool validTree(int n, vector<vector<int>>& edges)
    {
        const auto m = std::size(edges);

        if (m + 1 != n)
        {
            return false;
        }

        std::vector<std::vector<int>> graph(n);

        for (const auto& e : edges)
        {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        std::vector<char> visited(n);
        visited[0] = true;

        std::queue<int> q;
        q.push(0);

        while (!q.empty())
        {
            const auto v = q.front();
            q.pop();

            for (const auto to : graph[v])
            {
                if (!visited[to])
                {
                    visited[to] = true;
                    q.push(to);
                }
            }
        }

        return std::all_of(std::cbegin(visited), std::cend(visited), [](auto e) { return e; });
    }
};