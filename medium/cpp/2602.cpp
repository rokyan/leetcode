// https://leetcode.com/problems/minimum-operations-to-make-all-array-elements-equal/

class Solution
{
public:
    std::vector<long long> minOperations(std::vector<int>& nums, std::vector<int>& queries)
    {
        std::sort(std::begin(nums), std::end(nums));

        std::vector<std::pair<int, int>> q_w_idx(std::size(queries));

        for (auto idx = 0; idx < std::size(queries); idx++)
        {
            q_w_idx[idx] = { queries[idx], idx };
        }

        std::sort(std::begin(q_w_idx), std::end(q_w_idx));

        std::vector<long long> res(std::size(queries));

        auto r_sum = std::accumulate(std::begin(nums), std::end(nums), 0LL);
        auto l_sum = 0LL;

        for (auto idx = -1, q_idx = 0; q_idx < std::size(q_w_idx); q_idx++)
        {
            while (idx + 1 < std::size(nums) && nums[idx + 1] < q_w_idx[q_idx].first)
            {
                idx++;

                l_sum += nums[idx];
                r_sum -= nums[idx];
            }

            auto cur = 0LL;

            if (idx != -1)
            {
                cur += 1LL * (idx + 1) * q_w_idx[q_idx].first - l_sum;
            }

            if (idx + 1 < std::size(nums))
            {
                cur += r_sum - 1LL * (std::size(nums) - idx - 1) * q_w_idx[q_idx].first;
            }

            res[q_w_idx[q_idx].second] = cur;
        }

        return res;
    }
};