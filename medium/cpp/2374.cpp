// https://leetcode.com/problems/node-with-highest-edge-score/description/

class Solution
{
public:
    int edgeScore(std::vector<int>& edges)
    {
        const auto n = std::size(edges);

        std::vector<long long> acc(n);

        for (auto i = 0; i < n; i++)
        {
            acc[edges[i]] += i;
        }

        return std::max_element(std::begin(acc), std::end(acc)) - std::begin(acc);
    }
};