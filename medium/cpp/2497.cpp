// https://leetcode.com/problems/maximum-star-sum-of-a-graph/description/

class Solution
{
public:
    int maxStarSum(std::vector<int>& vals, std::vector<std::vector<int>>& edges, int k)
    {
        const auto n = static_cast<int>(std::size(vals));

        std::vector<std::vector<int>> data(n);

        for (const auto& edge : edges)
        {
            const auto u = edge[0];
            const auto v = edge[1];

            data[u].push_back(vals[v]);
            data[v].push_back(vals[u]);
        }

        auto ans = vals[0];

        for (auto v = 0; v < n; v++)
        {
            std::sort(std::begin(data[v]), std::end(data[v]), std::greater<>{});

            auto res = vals[v];

            for (auto i = 0; i < std::min<int>(std::size(data[v]), k); i++)
            {
                if (data[v][i] < 0)
                {
                    break;
                }

                res += data[v][i];
            }

            ans = std::max(ans, res);
        }

        return ans;
    }
};