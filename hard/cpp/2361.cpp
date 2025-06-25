// https://leetcode.com/problems/minimum-costs-using-the-train-line/description/

class Solution
{
public:
    std::vector<long long> minimumCosts(std::vector<int>& regular, std::vector<int>& express, int expressCost)
    {
        const auto n = std::size(regular);

        std::vector<long long> res(n);

        std::vector<long long> cur{0, expressCost};
        std::vector<long long> next(2);

        for (auto i = 0; i < n; i++)
        {
            next[0] = std::min(regular[i] + cur[0], express[i] + cur[1]);
            next[1] = std::min(express[i] + cur[1], regular[i] + cur[0] + expressCost);

            cur = next;
            res[i] = cur[0];
        }

        return res;
    }
};