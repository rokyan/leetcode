// https://leetcode.com/problems/can-you-eat-your-favorite-candy-on-your-favorite-day/

class Solution
{
public:
    std::vector<bool> canEat(std::vector<int>& candiesCount, std::vector<std::vector<int>>& queries)
    {
        std::vector<long long> pref(std::size(candiesCount));

        for (auto i = 0; i < std::size(candiesCount); i++)
        {
            pref[i] = candiesCount[i];

            if (i > 0)
            {
                pref[i] += pref[i - 1];
            }
        }

        std::vector<bool> res;
        res.reserve(std::size(queries));

        for (const auto& query : queries)
        {
            const auto type = query[0];
            const auto day = query[1] + 1;
            const auto cap = query[2];

            const auto maxDays = pref[type];
            const auto minDays = type == 0 ? 1 : (pref[type - 1] / cap + 1);
            res.push_back(minDays <= day && day <= maxDays);
        }

        return res;
    }
};