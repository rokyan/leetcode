// https://leetcode.com/problems/path-with-maximum-probability/description/

class Solution
{
private:
    using graph_type = std::vector<std::vector<std::pair<int, double>>>;

public:
    double maxProbability(int n, std::vector<std::vector<int>>& edges, std::vector<double>& succProb,
        int start_node, int end_node)
    {
        auto graph = transform(n, edges, succProb);

        std::vector<double> dst(n, 0.);
        dst[start_node] = 1.;

        std::set<std::pair<double, int>, std::greater<>> meow;
        meow.insert({ 1., start_node });

        while (!meow.empty())
        {
            const auto [_, v] = *std::begin(meow);
            meow.erase(std::begin(meow));

            for (const auto [to, prob] : graph[v])
            {
                if (dst[to] < dst[v] * prob)
                {
                    meow.erase({ dst[to], to });
                    dst[to] = dst[v] * prob;
                    meow.insert({ dst[to], to });
                }
            }
        }

        return dst[end_node];
    }

private:
    graph_type transform(int n, const std::vector<std::vector<int>>& edges, const std::vector<double>& succProb)
    {
        graph_type graph(n);

        for (auto i = 0; i < std::size(edges); i++)
        {
            graph[edges[i][0]].push_back({ edges[i][1], succProb[i] });
            graph[edges[i][1]].push_back({ edges[i][0], succProb[i] });
        }

        return graph;
    }
};