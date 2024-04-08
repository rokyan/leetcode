// https://leetcode.com/problems/most-profit-assigning-work/description/

class Solution
{
public:
    int maxProfitAssignment(std::vector<int>& difficulty, std::vector<int>& profit, std::vector<int>& worker)
    {
        const auto n = std::size(difficulty);

        std::vector<std::pair<int, int>> dp_pairs(n);

        for (auto i = 0; i < n; i++)
        {
            dp_pairs[i] = { difficulty[i], profit[i] };
        }

        std::sort(std::begin(dp_pairs), std::end(dp_pairs));

        std::sort(std::begin(worker), std::end(worker));

        auto p = 0;
        auto mv = -1;
        auto res = 0;

        for (const auto& w : worker)
        {
            while (p < std::size(dp_pairs) && dp_pairs[p].first <= w)
            {
                mv = std::max(mv, dp_pairs[p].second);
                p++;
            }

            if (mv != -1)
            {
                res += mv;
            }
        }

        return res;
    }
};