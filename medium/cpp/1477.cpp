// https://leetcode.com/problems/find-two-non-overlapping-sub-arrays-each-with-target-sum/description/

class Solution
{
public:
    int minSumOfLengths(std::vector<int>& arr, int target)
    {
        const auto n = std::size(arr);

        std::vector<int> dp(n, - 1);

        auto res = -1;

        for (auto l = 0, r = 0, s = 0; r < n; r++)
        {
            if (r > 0)
            {
                dp[r] = dp[r - 1];
            }

            s += arr[r];

            while (s > target)
            {
                s -= arr[l++];
            }

            if (s == target)
            {
                if (l > 0 && dp[l - 1] != -1)
                {
                    res = res == -1 ? dp[l - 1] + r - l + 1 : std::min(res, dp[l - 1] + r - l + 1);
                }

                dp[r] = dp[r] == -1 ? r - l + 1 : std::min(dp[r], r - l + 1);
            }
        }

        return res;
    }
};