// https://leetcode.com/problems/the-skyline-problem/description/

class Solution
{
public:
    std::vector<std::vector<int>> getSkyline(std::vector<std::vector<int>>& buildings)
    {
        std::map<int, std::vector<int>> heights;

        for (const auto& building : buildings)
        {
            heights[building[0]].push_back(building[2]);
            heights[building[1]].push_back(-building[2]);
        }

        std::multiset<int, greater<int>> acc;
        std::vector<std::vector<int>> res;

        for (const auto& entry : heights)
        {
            for (auto h : entry.second)
            {
                if (h > 0)
                {
                    acc.insert(h);
                }
                else
                {
                    acc.erase(acc.find(-h));
                }
            }

            const auto cur_height = acc.empty() ? 0 : *std::cbegin(acc);

            if (res.empty() || res.back()[1] != cur_height)
            {
                res.push_back({ entry.first, cur_height });
            }
        }

        return res;
    }
};