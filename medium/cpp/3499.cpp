// https://leetcode.com/problems/maximize-active-section-with-trade-i/description/

class Solution
{
public:
    int maxActiveSectionsAfterTrade(const std::string& s)
    {
        auto ones = 0;
        auto zeroes = 0;

        for (auto c : s)
        {
            if (c == '1')
            {
                ones++;
            }
            else
            {
                zeroes++;
            }
        }

        auto res = ones;

        const int n = std::size(s);

        std::vector<int> cntl(n);

        for (auto i = 0; i < n; i++)
        {
            if (s[i] == '0')
            {
                cntl[i] = 1 + (i > 0 ? cntl[i - 1] : 0);
            }
        }

        std::vector<int> cntr(n);

        for (auto i = n - 1; i >= 0; i--)
        {
            if (s[i] == '0')
            {
                cntr[i] = 1 + (i + 1 < n ? cntr[i + 1] : 0);
            }
        }

        for (auto i = 0; i < n; )
        {
            if (s[i] == '0')
            {
                i++;
            }
            else
            {
                auto j = i;

                while (j < n && s[j] == '1')
                {
                    j++;
                }

                if (i > 0 && s[i - 1] == '0' && j < n && s[j] == '0')
                {
                    res = std::max(res, ones + cntl[i - 1] + cntr[j]);
                }

                i = j;
            }
        }

        return res;
    }
};