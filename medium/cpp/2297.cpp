// https://leetcode.com/problems/jump-game-viii/description/

class Solution
{
public:
    long long minCost(const std::vector<int>& nums, const std::vector<int>& costs)
    {
        const int n = std::size(nums);

        std::vector<int> st;
        st.reserve(n);

        std::vector<std::vector<int>> prev(n);

        for (auto i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && nums[st.back()] < nums[i])
            {
                st.pop_back();
            }

            if (!st.empty())
            {
                prev[st.back()].push_back(i);
            }

            st.push_back(i);
        }

        st.clear();

        for (auto i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && nums[st.back()] >= nums[i])
            {
                st.pop_back();
            }

            if (!st.empty())
            {
                prev[st.back()].push_back(i);
            }

            st.push_back(i);
        }

        std::vector<long long> dp(n, -1);
        dp[0] = 0;

        for (auto i = 1; i < n; i++)
        {
            for (auto idx : prev[i])
            {
                dp[i] = dp[i] == -1
                    ? costs[i] + dp[idx]
                    : std::min(dp[i], costs[i] + dp[idx]);
            }
        }

        return dp.back();
    }
};