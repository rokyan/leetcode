// https://leetcode.com/problems/longest-repeating-substring/description/

class Solution
{
public:
    int longestRepeatingSubstring(std::string s)
    {
        const auto n = static_cast<int>(std::size(s));
        auto lo = 0;
        auto hi = n;

        const auto sw = std::string_view{ s };

        auto res = 0;

        while (lo < hi)
        {
            const auto mid = lo + (hi - lo + 1) / 2;

            std::unordered_map<std::string_view, int> freq;

            auto found = false;

            for (auto i = 0; i + mid - 1 < n; i++)
            {
                if (freq[sw.substr(i, mid)]++ == 1)
                {
                    found = true;
                    break;
                }
            }

            if (found)
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