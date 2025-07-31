// https://leetcode.com/problems/maximum-number-of-subsequences-after-one-inserting/description/

class Solution
{
public:
    long long numOfSubsequences(const std::string& s)
    {
        const int n = std::size(s);

        std::array<long long, 3> cnt;
        cnt.fill(0);

        for (auto i = 0; i < n; i++)
        {
            if (s[i] == 'L')
            {
                cnt[0]++;
            }
            else if (s[i] == 'C')
            {
                cnt[1] += cnt[0];
            }
            else if (s[i] == 'T')
            {
                cnt[2] += cnt[1];
            }
        }

        auto base = cnt[2];
        auto res = cnt[1];

        cnt.fill(0);

        for (auto i = n - 1; i >= 0; i--)
        {
            if (s[i] == 'C')
            {
                cnt[1] += cnt[2];
            }
            else if (s[i] == 'T')
            {
                cnt[2]++;
            }            
        }

        res = std::max(res, cnt[1]);

        cnt.fill(0);

        for (auto i = 0; i < n; i++)
        {
            if (s[i] == 'T')
            {
                cnt[2]++;
            }
        }

        for (auto i = 0; i < n; i++)
        {
            if (s[i] == 'L')
            {
                cnt[0]++;
                res = std::max(res, cnt[0] * cnt[2]);
            }
            else if (s[i] == 'T')
            {
                cnt[2]--;
            }
        }

        std::cout << base << std::endl;

        return res + base;
    }
};