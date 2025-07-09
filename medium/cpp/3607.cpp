// https://leetcode.com/problems/power-grid-maintenance/description/

class Solution
{
public:
    std::vector<int> processQueries(
        int c,
        const std::vector<std::vector<int>>& connections,
        const std::vector<std::vector<int>>& queries)
    {
        std::vector<std::vector<int>> graph(c);

        for (const auto& connection : connections)
        {
            graph[connection[0] - 1].push_back(connection[1] - 1);
            graph[connection[1] - 1].push_back(connection[0] - 1);
        }

        std::vector<int> comp(c, -1);

        std::unordered_map<int, std::set<int>> ids;

        for (auto v = 0, compId = 0; v < c; v++)
        {
            if (comp[v] == -1)
            {
                std::queue<int> q;
                q.push(v);
                comp[v] = compId;

                while (!q.empty())
                {
                    const auto u = q.front();
                    q.pop();
                    ids[compId].insert(u);

                    for (auto to : graph[u])
                    {
                        if (comp[to] == -1)
                        {
                            comp[to] = compId;
                            q.push(to);
                        }
                    }
                }

                compId++;
            }
        }

        std::vector<int> res;
        res.reserve(std::size(queries));

        for (const auto& query : queries)
        {
            if (query[0] == 1)
            {
                if (const auto it = ids.find(comp[query[1] - 1]); it != std::end(ids) && !it->second.empty())
                {
                    if (it->second.find(query[1] - 1) != std::end(it->second))
                    {
                        res.push_back(query[1]);
                    }
                    else
                    {
                        res.push_back(*std::begin(it->second) + 1);
                    }
                }
                else
                {
                    res.push_back(-1);
                }
            }
            else
            {
                if (const auto it = ids.find(comp[query[1] - 1]); it != std::end(ids) && !it->second.empty())
                {
                    it->second.erase(query[1] - 1);
                }
            }
        }

        return res;
    }
};