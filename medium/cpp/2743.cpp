// https://leetcode.com/problems/count-substrings-without-repeating-character/description/

class Solution
{
public:
    int numberOfSpecialSubstrings(std::string s)
    {
        const auto n = std::size(s);

        auto res = 0;

        std::array<int, 26> cnt { 0 };

        for (auto left = 0, right = 0; right < n; right++)
        {
            cnt[s[right] - 'a']++;

            while (cnt[s[right] - 'a'] == 2)
            {
                cnt[s[left++] - 'a']--;
            }

            res += right - left + 1;
        }

        return res;
    }
};