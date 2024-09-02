// https://leetcode.com/problems/alternating-groups-ii/description/

class Solution
{
public:
    int numberOfAlternatingGroups(const std::vector<int>& colors, int k)
    {
        const auto n = std::size(colors);

        auto val = 1;
        auto res = 0;

        for (auto i = 1; i < n + k - 1; i++)
        {
            const auto prev = colors[(i - 1) % n];
            const auto cur = colors[i % n];

            if (cur != prev)
            {
                val++;
            }
            else
            {
                val = 1;
            }

            if (val >= k)
            {
                res++;
            }
        }

        return res;
    }
};