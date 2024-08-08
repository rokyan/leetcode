// https://leetcode.com/problems/longest-valid-parentheses/description/

class Solution
{
public:
    int longestValidParentheses(std::string s)
    {
        const auto n = std::size(s);

        std::vector<int> dp(n);
        std::vector<int> st;
        st.reserve(n);

        for (auto i = 0; i < n; i++)
        {
            if (s[i] == '(')
            {
                st.push_back(i);
            }
            else
            {
                if (!st.empty())
                {
                    dp[i] = i - st.back() + 1;
                    st.pop_back();
                }
            }
        }

        auto res = 0;

        for (auto i = 1; i < n; i++)
        {
            if (dp[i] > 0 && i >= dp[i])
            {
                dp[i] += dp[i - dp[i]];
            }

            res = std::max(res, dp[i]);
        }

        return res;
    }
};