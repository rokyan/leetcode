// https://leetcode.com/problems/smallest-palindromic-rearrangement-i/description/

class Solution
{
public:
    std::string smallestPalindrome(const std::string& s)
    {
        const auto n = std::size(s);

        std::string res;
        res.resize(n);

        std::array<int, 26> cnt;
        cnt.fill(0);

        for (auto c : s)
        {
            cnt[c - 'a']++;
        }

        auto last = -1;
        auto p = 0;

        for (auto c = 0; c < 26; c++)
        {
            while (cnt[c] > 1)
            {
                res[p] = res[n - 1 - p] = c + 'a';
                p++;
                cnt[c] -= 2;
            }

            if (cnt[c] == 1)
            {
                last = c;
            }
        }

        if (last != -1)
        {
            res[p++] = last + 'a';
        }

        return res;
    }
};