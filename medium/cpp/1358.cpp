// https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/

class Solution
{
public:
    int numberOfSubstrings(std::string s)
    {
        std::array<int, 3> cnt{ 0 };

        auto res = 0;

        for (auto l = 0, r = 0; r < std::size(s); r++)
        {
            cnt[s[r] - 'a']++;

            while (cnt[s[l] - 'a'] > 1)
            {
                cnt[s[l] - 'a']--;
                l++;
            }

            if (*std::min_element(std::begin(cnt), std::end(cnt)) == 1)
            {
                res += l + 1;
            }
        }

        return res;
    }
};