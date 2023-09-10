// https://leetcode.com/problems/count-number-of-homogenous-substrings/description/

class Solution
{
public:
    int countHomogenous(std::string s)
    {
        auto res = 0;
        const auto mod = 1000 * 1000 * 1000 + 7;

        auto prev = s[0];
        auto cnt = 1;

        for (auto i = 1; i < std::size(s); i++)
        {
            if (s[i] == s[i - 1])
            {
                cnt++;
            }
            else
            {
                res += 1LL * cnt * (cnt + 1) / 2 % mod;
                cnt = 1;
            }
        }

        res += 1LL * cnt * (cnt + 1) / 2 % mod;

        return res;
    }
};