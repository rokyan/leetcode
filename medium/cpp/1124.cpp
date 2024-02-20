// https://leetcode.com/problems/longest-well-performing-interval/

class Solution
{
public:
    int longestWPI(std::vector<int>& hours)
    {
        std::unordered_map<int, int> first_occ;

        auto res = 0;

        for (auto r = 0, s = 0; r < std::size(hours); r++)
        {
            s += hours[r] > 8 ? 1 : -1;

            if (s > 0)
            {
                res = r + 1;
            }
            else
            {
                const auto target = s - 1;

                if (const auto it = first_occ.find(target); it != std::end(first_occ))
                {
                    res = std::max(res, r - it->second);
                }
            }

            if (const auto it = first_occ.find(s); s < 0 && it == std::end(first_occ))
            {
                first_occ.emplace(s, r);
            }
        }

        return res;
    }
};