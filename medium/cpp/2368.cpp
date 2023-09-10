// https://leetcode.com/problems/reachable-nodes-with-restrictions/description/

class Solution
{
public:
    int reachableNodes(int n, std::vector<std::vector<int>>& edges, std::vector<int>& restricted)
    {
        std::vector<std::vector<int>> graph(n);

        for (const auto& edge : edges)
        {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]); 
        }
        auto res = 0;

        std::queue<int> q;
        q.push(0);

        std::vector<char> visited(n);
        visited[0] = true;

        for (auto v : restricted)
        {
            visited[v] = true;
        }

        while (!q.empty())
        {
            const auto v = q.front();
            q.pop();

            res++;

            for (const auto to : graph[v])
            {
                if (!visited[to])
                {
                    visited[to] = true;
                    q.push(to);
                }
            }
        }

        return res;    
    }
};