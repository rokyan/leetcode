// https://leetcode.com/problems/minimum-swaps-to-group-all-1s-together/description/

class Solution
{
public:
    int minSwaps(std::vector<int>& data)
    {
        const auto ones = std::accumulate(std::cbegin(data), std::cend(data), 0);
        auto cur = 0;

        for (auto i = 0; i < ones; i++)
        {
            cur += data[i];
        }

        auto res = ones - cur;

        for (auto i = ones; i < std::size(data) && res; i++)
        {
            cur += data[i] - data[i - ones];
            res = std::min(res, ones - cur);
        }

        return res;
    }
};