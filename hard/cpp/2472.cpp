// https://leetcode.com/problems/maximum-number-of-non-overlapping-palindrome-substrings/description/

class Solution
{
public:
    int maxPalindromes(const std::string& s, int k)
    {
        const int n = s.size();

        std::vector<std::vector<char>> isPal(n, std::vector<char>(n));

        for (int i = 0; i < n; i++)
        {
            int l = i;
            int r = i;

            while (l >= 0 && r < n && s[l] == s[r])
            {
                isPal[l][r] = true;
                l--;
                r++;
            }

            l = i - 1;
            r = i;

            while (l >= 0 && r < n && s[l] == s[r])
            {
                isPal[l][r] = true;
                l--;
                r++;
            }
        }

        std::vector<int> dp(n + 1);

        for (int i = 1; i <= n; i++)
        {
            dp[i] = dp[i - 1];
            int j = i;

            while (j > 0)
            {
                if (isPal[j - 1][i - 1] && i - j + 1 >= k)
                {
                    dp[i] = std::max(dp[i], dp[j - 1] + 1);
                }

                j--;
            }
        }

        return dp.back();
    }
};