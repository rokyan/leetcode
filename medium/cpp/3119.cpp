// https://leetcode.com/problems/maximum-number-of-potholes-that-can-be-fixed/description/

class Solution
{
public:
    int maxPotholes(const std::string& road, int budget)
    {
        const auto n = std::size(road);

        std::vector<int> lens;

        auto cnt = 0;

        for (auto i = 0; i < n; i++)
        {
            if (road[i] == 'x')
            {
                cnt++;
            }
            else
            {
                if (cnt > 0)
                {
                    lens.push_back(cnt);
                    cnt = 0;
                }
            }
        }

        if (cnt > 0)
        {
            lens.push_back(cnt);
        }

        std::ranges::sort(lens, std::greater<>{});

        auto res = 0;

        for (auto i = 0; i < std::size(lens); i++)
        {
            if (budget > lens[i])
            {
                budget -= lens[i] + 1;
                res += lens[i];
            }
            else if (budget > 0)
            {
                res += budget - 1;
                budget = 0;
            }
        }

        return res;
    }
};