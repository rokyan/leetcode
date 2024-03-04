// https://leetcode.com/problems/possible-bipartition/description/

class Solution
{
public:
    bool possibleBipartition(int n, std::vector<std::vector<int>>& dislikes)
    {
        std::vector<std::vector<int>> graph(n);

        for (const auto& e : dislikes)
        {
            graph[e[0] - 1].push_back(e[1] - 1);
            graph[e[1] - 1].push_back(e[0] - 1);
        }

        std::vector<int> part(n);

        for (auto v = 0; v < n; v++)
        {
            if (part[v] == 0)
            {
                std::queue<int> q;
                q.push(v);

                part[v] = 1;

                while (!q.empty())
                {
                    const auto u = q.front();
                    q.pop();

                    for (auto to : graph[u])
                    {
                        if (part[to] == part[u])
                        {
                            return false;
                        }

                        if (part[to] == 0)
                        {
                            part[to] = part[u] == 1 ? 2 : 1;
                            q.push(to);
                        }
                    }
                }
            }
        }

        return true;
    }
};