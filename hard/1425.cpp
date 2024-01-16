// https://leetcode.com/problems/constrained-subsequence-sum/

class Solution
{
public:
    int constrainedSubsetSum(std::vector<int>& nums, int k)
    {
        const auto n = std::size(nums);

        std::priority_queue<std::pair<int, int>> pq;
        pq.push({ nums[0], 0 });

        auto res = nums[0];

        for (auto i = 1; i < n; i++)
        {
            if (i > k)
            {
                auto last = i - k - 1;

                while (pq.top().second <= last)
                {
                    pq.pop();
                }
            }

            const auto val = nums[i] + std::max(pq.top().first, 0);

            pq.push({ val, i });

            res = std::max(res, val);
        }

        return res;
    }
};