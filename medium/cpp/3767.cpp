// https://leetcode.com/problems/maximize-points-after-choosing-k-tasks/description/

class Solution
{
public:
    long long maxPoints(const std::vector<int>& technique1, const std::vector<int>& technique2, int k)
    {
        const int n = std::size(technique1);

        std::vector<std::pair<int, int>> pairs;
        pairs.reserve(n);

        for (int i = 0; i < n; i++)
        {
            pairs.emplace_back(technique1[i], technique2[i]);
        }

        std::nth_element(std::begin(pairs), std::next(std::begin(pairs), k), std::end(pairs),
        [](const auto& lhs, const auto& rhs)
        {
            return lhs.first - rhs.first > lhs.second - rhs.second;
        });

        long long res = 0LL;

        for (int i = 0; i < k; i++)
        {
            res += pairs[i].first;
        }

        for (int i = k; i < n; i++)
        {
            res += std::max(pairs[i].first, pairs[i].second);
        }

        return res;
    }
};