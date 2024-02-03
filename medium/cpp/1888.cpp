// https://leetcode.com/problems/minimum-number-of-flips-to-make-the-binary-string-alternating/

class Solution
{
public:
    int minFlips(std::string s)
    {
        const auto n = static_cast<int>(std::size(s));

        std::vector<std::vector<int>> suff(2, std::vector<int>(n));

        for (auto i = n - 1; i >= 0; i--)
        {
            suff[0][i] = s[i] == '1';
            suff[1][i] = s[i] == '0';

            if (i < n - 1)
            {
                suff[0][i] += suff[1][i + 1];
                suff[1][i] += suff[0][i + 1];
            }
        }

        auto res = std::min(suff[0][0], suff[1][0]);

        std::vector<int> pref(2);

        for (auto i = 0, rem = n - 1; i + 1 < n; i++, rem--)
        {
            pref[0] += s[i] == ('1' - i % 2);
            pref[1] += s[i] == ('0' + i % 2);

            res = std::min(res, suff[0][i + 1] + (rem % 2 == 0 ? pref[0] : pref[1]));
            res = std::min(res, suff[1][i + 1] + (rem % 2 == 0 ? pref[1] : pref[0]));
        }

        return res;
    }
};