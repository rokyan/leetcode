// https://leetcode.com/problems/heaters/description/

class Solution
{
public:
    int findRadius(std::vector<int>& houses, std::vector<int>& heaters)
    {
        std::sort(std::begin(houses), std::end(houses));
        std::sort(std::begin(heaters), std::end(heaters));

        auto res = 0;

        for (auto i = 0, j = 0; i < std::size(houses); i++)
        {
            while (j + 1 < std::size(heaters) && heaters[j + 1] <= houses[i])
            {
                j++;
            }

            if (houses[i] >= heaters[j])
            {
                auto d = houses[i] - heaters[j];

                if (j + 1 < std::size(heaters))
                {
                    d = std::min(d, heaters[j + 1] - houses[i]);
                }

                res = std::max(res, d);
            }
            else
            {
                res = std::max(res, heaters[j] - houses[i]);
            }
        }

        return res;
    }
};