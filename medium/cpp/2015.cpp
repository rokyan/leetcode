// https://leetcode.com/problems/average-height-of-buildings-in-each-segment/description/

class Solution
{
public:
    std::vector<std::vector<int>> averageHeightOfBuildings(std::vector<std::vector<int>>& buildings)
    {
        std::map<int, std::vector<int>> heights;

        for (const auto& building : buildings)
        {
            heights[building[0]].push_back(building[2]);
            heights[building[1]].push_back(-building[2]);
        }

        std::vector<std::vector<int>> res;

        auto sum = 0;
        auto tot = 0;
        auto last = 0;
        auto open = false;

        for (const auto& e : heights)
        {
            auto prev_sum = sum;
            auto prev_tot = tot;

            for (auto height : e.second)
            {
                if (height < 0)
                {
                    tot--;
                }
                else
                {
                    tot++;
                }

                sum += height;
            }

            if (sum == 0)
            {
                if (open)
                {
                    res.push_back({ last, e.first, prev_sum / prev_tot });
                    open = false;
                }
            }
            else
            {
                if (open)
                {
                    if (prev_sum / prev_tot != sum / tot)
                    {
                        res.push_back({ last, e.first, prev_sum / prev_tot });
                        last = e.first;
                    }
                }
                else
                {
                    open = true;
                    last = e.first;
                }
            }
        }

        return res;
    }
};