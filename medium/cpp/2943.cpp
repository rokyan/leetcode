// https://leetcode.com/problems/maximize-area-of-square-hole-in-grid/description/

class Solution
{
public:
    int maximizeSquareHoleArea(int n, int m, std::vector<int>& hBars, std::vector<int>& vBars)
    {
        std::ranges::sort(vBars);

        auto longest = 0;
        auto cur = 1;

        for (auto i = 1; i < std::size(vBars); i++)
        {
            if (vBars[i] == vBars[i - 1] + 1)
            {
                cur++;
            }
            else
            {
                longest = std::max(longest, cur);
                cur = 1;
            }
        }

        longest = std::max(longest, cur);

        std::ranges::sort(hBars);
        cur = 1;

        auto res = 0;

        for (auto i = 1; i < std::size(hBars); i++)
        {
            if (hBars[i] == hBars[i - 1] + 1)
            {
                cur++;
            }
            else
            {
                const auto side = std::min(cur + 1, longest + 1);
                res = std::max(res, side * side);
                cur = 1;
            }
        }

        const auto side = std::min(cur + 1, longest + 1);
        return std::max(res, side * side);
    }
};