// https://leetcode.com/problems/is-graph-bipartite/description/

class Solution
{
public:
    bool isBipartite(std::vector<std::vector<int>>& graph)
    {
        const auto n = std::size(graph);

        std::vector<char> color(n);        
        
        for (auto v = 0; v < n; v++)
        {
            if (!color[v])
            {
                std::queue<int> q;
                q.push(v);
                color[v] = 1;

                while (!q.empty())
                {
                    const auto u = q.front();
                    q.pop();

                    for (auto to : graph[u])
                    {
                        if (color[to] == color[u])
                        {
                            return false;
                        }

                        if (color[to] == 0)
                        {
                            color[to] = color[u] == 1 ? 2 : 1;
                            q.push(to);
                        }
                    }
                }
            }
        }

        return true;
    }
};