// https://leetcode.com/problems/closest-subsequence-sum/description/

class Solution
{
public:
    int minAbsDifference(const std::vector<int>& nums, int goal)
    {
        const int n = nums.size();
        const int m = n / 2;

        std::vector<int> sums;
        sums.reserve(1 << m);

        for (int mask = 0; mask < (1 << m); mask++)
        {
            int sum = 0;

            for (int i = 0; i < m; i++)
            {
                if (mask & (1 << i))
                {
                    sum += nums[i];
                }
            }

            sums.push_back(sum);
        }

        std::ranges::sort(sums);

        const int rem = n - m;

        int res = std::abs(goal - nums[0]);

        for (int mask = 0; mask < (1 << rem); mask++)
        {
            int sum = 0;

            for (int i = 0; i < rem; i++)
            {
                if (mask & (1 << i))
                {
                    sum += nums[m + i];
                }
            }

            const int target = goal - sum;

            auto it = std::lower_bound(sums.begin(), sums.end(), target);
            bool skip = false;

            if (it == sums.end())
            {
                --it;
                skip = true;
            }

            res = std::min(res, std::abs(target - *it));

            if (it != sums.begin() && !skip)
            {
                --it;
                res = std::min(res, std::abs(target - *it));
            }
        }

        return res;
    }
};