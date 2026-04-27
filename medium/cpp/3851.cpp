// https://leetcode.com/problems/maximum-requests-without-violating-the-limit/description/

class Solution
{
public:
    int maxRequests(const std::vector<std::vector<int>>& requests, int k, int window)
    {
        std::unordered_map<int, std::vector<int>> userRequests;

        for (const auto& request : requests)
        {
            userRequests[request[0]].push_back(request[1]);
        }

        int res = 0;

        for (auto& [_, rs] : userRequests)
        {
            std::ranges::sort(rs);

            const int n = rs.size();

            std::vector<int> dp(n);
            dp[0] = 1;

            for (int i = 1; i < n; i++)
            {
                dp[i] = dp[i - 1];

                const int prev = rs[i] - window;
                const auto pos = std::lower_bound(rs.begin(), rs.begin() + i, prev) - rs.begin();
                const int upd = (pos > 0 ? dp[pos - 1] : 0) + std::min<int>(i - pos + 1, k);
                dp[i] = std::max(dp[i], upd);
            }

            res += dp.back();
        }

        return res;
    }
};