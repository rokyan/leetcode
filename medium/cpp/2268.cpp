// https://leetcode.com/problems/minimum-number-of-keypresses/description/

class Solution
{
public:
    int minimumKeypresses(std::string s)
    {
        std::array<int, 26> freq{ 0 };

        for (auto c : s)
        {
            freq[c - 'a']++;
        }

        std::sort(std::begin(freq), std::end(freq), std::greater<>{});

        std::array<int, 3> cnt{ 9, 9, 9 };
        auto p = 0;
        auto res = 0;

        for (auto i = 0; i < 26 && freq[i] > 0; i++)
        {
            if (cnt[p] == 0)
            {
                p++;
            }

            res += (p + 1) * freq[i];
            cnt[p]--;
        }

        return res;
    }
};