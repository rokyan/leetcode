// https://leetcode.com/problems/count-covered-buildings/description/

class Solution
{
public:
    int countCoveredBuildings(int n, const std::vector<std::vector<int>>& buildings)
    {
        std::unordered_map<int, std::pair<int, int>> x;
        std::unordered_map<int, std::pair<int, int>> y;

        for (const auto& building : buildings)
        {
            if (auto it = x.find(building[0]); it == std::end(x))
            {
                x.emplace(building[0], std::make_pair(building[1], building[1]));
            }
            else
            {
                it->second.first = std::min(it->second.first, building[1]);
                it->second.second = std::max(it->second.second, building[1]);
            }

            if (auto it = y.find(building[1]); it == std::end(y))
            {
                y.emplace(building[1], std::make_pair(building[0], building[0]));
            }
            else
            {
                it->second.first = std::min(it->second.first, building[0]);
                it->second.second = std::max(it->second.second, building[0]);
            }
        }

        auto res = 0;

        for (const auto& building : buildings)
        {
            if (const auto it = x.find(building[0]);
                it == std::end(x) || building[1] <= it->second.first || building[1] >= it->second.second)
            {
                continue;
            }

            if (const auto it = y.find(building[1]);
                it == std::end(y) || building[0] <= it->second.first || building[0] >= it->second.second)
            {
                continue;
            }


            res++;
        }

        return res;
    }
};