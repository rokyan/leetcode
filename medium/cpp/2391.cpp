// https://leetcode.com/problems/minimum-amount-of-time-to-collect-garbage/description/

class Solution
{
public:
    int garbageCollection(std::vector<string>& garbage, vector<int>& travel)
    {
        auto res = 0;

        for (auto gt : { 'M', 'P', 'G'})
        {
            auto comm = 0;

            for (auto i = 0; i < std::size(garbage); i++)
            {
                auto acc = 0;

                for (auto c : garbage[i])
                {
                    if (c == gt)
                    {
                        acc++;
                    }
                }

                if (acc > 0)
                {
                    res += acc + comm;
                    comm = 0;
                }

                if (i < std::size(travel))
                {
                    comm += travel[i];
                }
            }
        }

        return res;
    }
};