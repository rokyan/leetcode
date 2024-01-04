// https://leetcode.com/problems/h-index/description/

class Solution
{
public:
    int hIndex(std::vector<int>& citations)
    {
        auto lo = 0;
        auto hi = static_cast<int>(std::size(citations));

        while (lo < hi)
        {
            const auto mid = lo + (hi - lo + 1) / 2;
            auto cnt = 0;

            for (auto c : citations)
            {
                cnt += c >= mid;

                if (cnt >= mid)
                {
                    break;
                }
            }

            if (cnt >= mid)
            {
                lo = mid;
            }
            else
            {
                hi = mid - 1;
            }
        }

        return lo;
    }
};