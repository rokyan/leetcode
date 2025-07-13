// https://leetcode.com/problems/unit-conversion-i/description/

class Solution
{
private:
    static constexpr auto mod = 1000'000'000 + 7;

public:
    std::vector<int> baseUnitConversions(const std::vector<std::vector<int>>& conversions)
    {
        const auto n = std::size(conversions) + 1;

        std::vector<std::vector<std::pair<int, int>>> graph(n);

        for (const auto& conv : conversions)
        {
            graph[conv[0]].emplace_back(conv[1], conv[2]);
        }

        std::vector<int> res(n);
        dfs(0, graph, 1, res);

        return res;
    }

private:
    void dfs(int v, const std::vector<std::vector<std::pair<int, int>>>& graph,
        int cost, std::vector<int>& res)
    {
        res[v] = cost;

        for (const auto [to, w] : graph[v])
        {
            dfs(to, graph, 1LL * cost * w % mod, res);
        }
    }
};