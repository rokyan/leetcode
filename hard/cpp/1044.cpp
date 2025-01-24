// https://leetcode.com/problems/longest-duplicate-substring/description/

class Solution
{
public:
    std::string longestDupSubstring(const std::string& s)
    {
        auto lo = 0;
        auto hi = static_cast<int>(std::size(s)) - 1;

        std::string_view sw{s};
        std::string_view res;

        while (lo < hi)
        {
            const auto mid = lo + (hi - lo + 1) / 2;

            std::unordered_set<std::string_view> probe;
            auto found = false;

            for (auto i = 0; i + mid - 1 < std::size(sw) && !found; i++)
            {
                if (!probe.insert(sw.substr(i, mid)).second)
                {
                    found = true;

                    if (mid > std::size(res))
                    {
                        res = sw.substr(i, mid);
                    }
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

        return std::string{res};
    }
};