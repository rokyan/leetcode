// https://leetcode.com/problems/number-of-substrings-with-fixed-ratio/

class Solution
{
public:
    long long fixedRatio(std::string s, int num1, int num2)
    {
        const auto n = std::size(s);

        auto res = 0LL;

        std::unordered_map<long long, int> cnt{ { 0LL, 1 } };

        for (auto i = 0, zeroes = 0, ones = 0; i < n; i++)
        {
            zeroes += s[i] == '0';
            ones += s[i] == '1';

            const auto val = 1LL * num2 * zeroes - 1LL * num1 * ones;

            res += cnt[val]++;
        }

        return res;
    }
};