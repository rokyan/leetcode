// https://leetcode.com/problems/longest-binary-subsequence-less-than-or-equal-to-k/

class Solution
{
public:
    int longestSubsequence(std::string s, int k)
    {
        const auto n = static_cast<int>(std::size(s));

        auto res = 0;

        for (auto len = 1; len <= n; len++)
        {
            std::string st;

            for (auto i = 0; i < n; i++)
            {
                while (!st.empty() && st.back() > s[i] && std::size(st) + n - i - 1 >= len)
                {
                    st.pop_back();
                }

                if (std::size(st) < len)
                {
                    st.push_back(s[i]);
                }
            }

            auto m = 0LL;
            auto num = 0LL;
            auto too_long = false;

            while (!st.empty())
            {
                if (st.back() == '1')
                {
                    if (m > 30)
                    {
                        too_long = true;
                        break;
                    }

                    num += 1 << m;
                }

                if (num > k)
                {
                    break;
                }

                st.pop_back();
                m++;
            }

            if (!too_long && num <= k)
            {
                res = len;
            }
        }

        return res;
    }
};