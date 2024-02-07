// https://leetcode.com/problems/find-longest-awesome-substring/

class Solution
{
public:
    int longestAwesome(std::string s)
    {
        auto mask = 0;

        std::unordered_map<int, int> pref;
        pref[mask] = -1;

        auto res = -1;

        for (auto i = 0; i < std::size(s); i++)
        {
            mask ^= 1 << (s[i] - '0');

            if (const auto it = pref.find(mask); it != std::end(pref))
            {
                res = std::max(res, i - it->second);
            }
            else
            {
                pref.emplace(mask, i);
            }

            for (auto bit = 0; bit <= 9; bit++)
            {
                const auto nmask = mask ^ (1 << bit);

                if (const auto it = pref.find(nmask); it != std::end(pref))
                {
                    res = std::max(res, i - it->second);
                }
            }
        }

        return res;
    }
};