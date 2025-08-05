// https://leetcode.com/problems/properties-graph/description/

class Solution
{
public:
    int numberOfComponents(const std::vector<std::vector<int>>& properties, int k)
    {
        const auto n = std::size(properties);

        std::vector<std::vector<char>> probe(n, std::vector<char>(101));

        for (auto i = 0; i < n; i++)
        {
            for (auto e : properties[i])
            {
                probe[i][e] = 1;
            }
        }

        std::vector<std::vector<int>> graph(n);

        for (auto i = 0; i + 1 < n; i++)
        {
            for (auto j = i + 1; j < n; j++)
            {
                auto common = 0;

                for (auto k = 1; k <= 100 && common < k; k++)
                {
                    common += (probe[i][k] + probe[j][k]) == 2;
                }

                if (common >= k)
                {
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }

        auto res = 0;

        std::vector<char> visited(n);

        for (auto v = 0; v < n; v++)
        {
            if (!visited[v])
            {
                dfs(v, graph, visited);
                res++;
            }
        }

        return res;
    }

private:
    void dfs(int v, const std::vector<std::vector<int>>& graph, std::vector<char>& visited)
    {
        visited[v] = true;

        for (auto to : graph[v])
        {
            if (!visited[to])
            {
                dfs(to, graph, visited);
            }
        }
    }
};