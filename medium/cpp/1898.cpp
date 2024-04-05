// https://leetcode.com/problems/maximum-number-of-removable-characters/description/

class Solution
{
public:
    int maximumRemovals(std::string s, std::string p, std::vector<int>& removable)
    {
        const auto n = static_cast<int>(std::size(removable));

        auto lo = 0;
        auto hi = n;

        while (lo < hi)
        {
            std::vector<char> removed(std::size(s));

            const auto mid = lo + (hi - lo + 1) / 2;

            for (auto i = 0; i < mid; i++)
            {
                removed[removable[i]] = true;
            }

            auto pos = 0;

            for (auto i = 0; i < std::size(s) && pos < std::size(p); i++)
            {
                if (!removed[i] && s[i] == p[pos])
                {
                    pos++;
                }
            }

            if (pos == std::size(p))
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