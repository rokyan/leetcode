// https://leetcode.com/problems/all-divisions-with-the-highest-score-of-a-binary-array/description/

class Solution
{
public:
    std::vector<int> maxScoreIndices(std::vector<int>& nums)
    {
        const auto n = std::size(nums);
        
        auto zeroes = 0;
        auto ones = std::count(std::begin(nums), std::end(nums), 1);

        std::vector<int> res;
        auto score = 0;

        for (auto i = 0; i <= n; i++)
        {
            const auto cur = zeroes + ones;

            if (cur > score)
            {
                res.clear();
                res.push_back(i);
                score = cur;
            }
            else if (cur == score)
            {
                res.push_back(i);
            }

            if (i < n)
            {
                zeroes += nums[i] == 0;
                ones -= nums[i] == 1;
            }
        }

        return res;
    }
};