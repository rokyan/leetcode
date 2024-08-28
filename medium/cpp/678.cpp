// https://leetcode.com/problems/valid-parenthesis-string/description/

class Solution
{
public:
    bool checkValidString(const std::string& s)
    {
        const auto n = std::size(s);

        std::vector<std::vector<bool>> dp(n, std::vector<bool>(n, false));

        for (auto len = 1; len <= n; len++)
        {
            for (auto start = 0; start + len - 1 < n; start++)
            {
                auto end = start + len - 1;

                if (s[start] == '*' && s[end] != '(' ||
                    s[end] == '*' && s[start] != ')' ||
                    s[start] == '(' && s[end] == ')')
                {
                    dp[start][end] = len > 2 ? dp[start + 1][end - 1] : true;
                }

                if (len > 1)
                {
                    if (!dp[start][end])
                    {
                        if (s[start] == '*' && dp[start + 1][end])
                        {
                            dp[start][end] = true;
                        }

                        if (s[end] == '*' && dp[start][end - 1])
                        {
                            dp[start][end] = true;
                        }
                    }
                    
                    if (!dp[start][end])
                    {
                        for (auto cur_end = start; cur_end < start + len - 1; cur_end++)
                        {
                            if (dp[start][cur_end] && dp[cur_end + 1][end])
                            {
                                dp[start][end] = true;
                                break;
                            }
                        }
                    }
                }
            }
        }

        return dp[0][n - 1];
    }
};