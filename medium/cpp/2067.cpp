// https://leetcode.com/problems/number-of-equal-count-substrings/

class Solution
{
public:
    int equalCountSubstrings(std::string s, int count)
    {
        const auto n = std::size(s);

        std::vector<std::vector<int>> pref(26, std::vector<int>(n));

        auto res = 0;

        for (auto i = 0; i < n; i++)
        {
            pref[s[i] - 'a'][i]++;

            if (i > 0)
            {
                for (auto j = 0; j < 26; j++)
                {
                    pref[j][i] += pref[j][i - 1];
                }
            }

            for (auto t = 1; t <= 26; t++)
            {
                const auto start = i - count * t + 1;

                if (start < 0)
                {
                    break;
                }

                auto cnt = 0;

                for (auto j = 0; j < 26; j++)
                {
                    const auto cur = pref[j][i] - (start > 0 ? pref[j][start - 1] : 0);
                    cnt += cur == count;
                }

                if (cnt == t)
                {
                    res++;
                }
            }
        }

        return res;
    }
};