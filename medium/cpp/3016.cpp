// https://leetcode.com/problems/minimum-number-of-pushes-to-type-word-ii/description/

class Solution
{
public:
    int minimumPushes(std::string word)
    {
        std::array<int, 26> cnt{ 0 };

        for (auto c : word)
        {
            cnt[c - 'a']++;
        }

        std::sort(std::begin(cnt), std::end(cnt), std::greater<>{});

        std::array<int, 8> b{ 0 };

        auto res = 0;

        for (auto i = 0, p = 0; i < 26 && cnt[i] > 0; i++, p = (p + 1) % 8)
        {
            res += (b[p] + 1) * cnt[i];
            b[p]++;
        }

        return res;
    }
};