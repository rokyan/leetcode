// https://leetcode.com/problems/evaluate-division/description/

class Solution
{
public:
    std::vector<double> calcEquation(std::vector<std::vector<std::string>>& equations,
        std::vector<double>& values, std::vector<std::vector<std::string>>& queries)
    {
        std::unordered_map<std::string, std::vector<std::pair<std::string, double>>> graph;

        for (auto i = 0; i < std::size(equations); i++)
        {
            graph[equations[i][0]].emplace_back(equations[i][1], values[i]);
            graph[equations[i][1]].emplace_back(equations[i][0], 1.0 / values[i]);
        }

        std::unordered_map<std::string, std::unordered_map<std::string, double>> ratios;

        for (const auto& [key, _] : graph)
        {
            std::queue<std::string> q;
            q.push(key);

            std::unordered_map<std::string, double> dist{ { key, 1.0 } };

            while (!q.empty())
            {
                const auto v = q.front();
                q.pop();

                for (const auto& [to, weight] : graph[v])
                {
                    if (dist.find(to) == std::end(dist))
                    {
                        dist[to] = dist[v] * weight;
                        q.push(to);
                    }
                }
            }

            ratios[key] = std::move(dist);
        }

        std::vector<double> res;
        res.reserve(std::size(queries));

        for (const auto& query : queries)
        {
            res.push_back(-1.0);

            if (const auto it0 = ratios.find(query[0]); it0 != std::end(ratios))
            {
                if (const auto it1 = it0->second.find(query[1]); it1 != std::end(it0->second))
                {
                    res.back() = it1->second;
                }
            }
        }

        return res;
    }
};