// https://leetcode.com/problems/put-marbles-in-bags/description/

class Solution
{
public:
    long long putMarbles(std::vector<int>& weights, int k)
    {
        const auto n = static_cast<int>(std::size(weights));

        std::vector<int> ps(n - 1);

        for (auto i = 0; i + 1 < n; i++)
        {
            ps[i] = weights[i] + weights[i + 1];
        }

        std::sort(std::begin(ps), std::end(ps));

        auto mins = 0LL;

        for (auto i = 0; i + 1 < k; i++)
        {
            mins += ps[i];
        }

        auto maxs = 0LL;

        for (auto i = n - 2; i >= n - k; i--)
        {
            maxs += ps[i];
        }

        return maxs - mins;
    }
};