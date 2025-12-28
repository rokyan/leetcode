// https://leetcode.com/problems/maximum-score-of-a-split/description/

class Solution
{
public:
    long long maximumScore(const std::vector<int>& nums)
    {
        long long pref = 0LL;

        std::vector<int> min_num(nums);

        const int n = std::size(nums);

        for (int i = n - 2; i >= 0; i--)
        {
            min_num[i] = std::min(min_num[i + 1], nums[i]);
        }

        long long max_score = nums[0] - min_num[1];

        for (int i = 0; i + 1 < n; i++)
        {
            pref += nums[i];
            max_score = std::max(max_score, pref - min_num[i + 1]);
        }

        return max_score;
    }
};