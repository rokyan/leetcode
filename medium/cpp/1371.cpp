// https://leetcode.com/problems/find-the-longest-substring-containing-vowels-in-even-counts/

class Solution
{
public:
    int findTheLongestSubstring(std::string s)
    {
        auto mask = 0;

        std::unordered_map<int, int> pref;
        pref[mask] = -1;

        auto res = 0;

        for (auto i = 0; i < std::size(s); i++)
        {
            if (s[i] == 'a') mask ^= 1 << 0;
            if (s[i] == 'e') mask ^= 1 << 1;
            if (s[i] == 'i') mask ^= 1 << 2;
            if (s[i] == 'o') mask ^= 1 << 3;
            if (s[i] == 'u') mask ^= 1 << 4;

            if (const auto it = pref.find(mask); it != std::end(pref))
            {
                res = std::max(res, i - it->second);
            }
            else
            {
                pref[mask] = i;
            }
        }

        return res;
    }
};