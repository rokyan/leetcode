// https://leetcode.com/problems/buildings-with-an-ocean-view/description/

class Solution
{
public:
    std::vector<int> findBuildings(std::vector<int>& heights)
    {
        std::vector<int> res;

        for (auto i = static_cast<int>(std::size(heights)) - 1, m = -1; i >= 0; i--)
        {
            if (heights[i] > m)
            {
                res.push_back(i);
            }

            m = std::max(m, heights[i]);
        }

        std::reverse(std::begin(res), std::end(res));
        return res;
    }
};