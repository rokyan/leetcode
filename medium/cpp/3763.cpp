// https://leetcode.com/problems/maximum-total-sum-with-threshold-constraints/description/

class Solution
{
public:
    long long maxSum(const std::vector<int>& nums, const std::vector<int>& threshold)
    {
        const int n = std::size(nums);
    
        std::vector<std::pair<int, int>> pairs;
        pairs.reserve(n);

        for (int i = 0; i < n; i++)
        {
            pairs.emplace_back(threshold[i], nums[i]);
        }

        std::ranges::sort(pairs, [](const auto& lhs, const auto& rhs) {
            return lhs.first < rhs.first || lhs.first == rhs.first && lhs.second > rhs.second;
        });

        int step = 1;
        long long res = 0LL;

        for (int i = 0; i < n; i++)
        {
            if (pairs[i].first <= step)
            {
                step++;
                res += pairs[i].second;
            }
        }

        return res;
    }
};