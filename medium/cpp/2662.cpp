// https://leetcode.com/problems/minimum-cost-of-a-path-with-special-roads/description/

class Solution
{
private:
    static constexpr auto inf = 1000'000'000;

public:
    int minimumCost(std::vector<int>& start, std::vector<int>& target, std::vector<std::vector<int>>& specialRoads)
    {
        std::map<std::vector<int>, int> edges;        
        std::map<std::pair<int, int>, int> dist{{{start[0], start[1]}, inf}, {{target[0], target[1]}, inf}};

        for (const auto& road : specialRoads)
        {
            if (road[4] < std::abs(road[0] - road[2]) + std::abs(road[1] - road[3]))
            {
                const auto key = std::vector(std::cbegin(road), std::begin(road) + 4);

                if (const auto it = edges.find(key); it != std::end(edges))
                {
                    it->second = std::min(it->second, road[4]);
                }
                else
                {
                    edges.emplace(std::move(key), road[4]);
                }
            }

            dist[{ road[0], road[1] }] = dist[{ road[2], road[3] }] = inf;
        }

        dist[{start[0], start[1]}] = 0;

        std::priority_queue<std::pair<int, std::pair<int, int>>> heap;
        heap.push({0, {start[0], start[1]}});

        while (!heap.empty())
        {
            const auto [d, node] = heap.top();
            heap.pop();

            for (const auto& [to, to_d] : dist)
            {
                auto w = std::abs(node.first - to.first) + std::abs(node.second - to.second);

                if (const auto it = edges.find({node.first, node.second, to.first, to.second}); it != std::end(edges))
                {
                    w = std::min(w, it->second);
                }

                if (-d + w < to_d)
                {
                    dist[to] = -d + w;
                    heap.push({-(-d + w), to});
                }
            }
        }

        return dist[{target[0], target[1]}];
    }
};