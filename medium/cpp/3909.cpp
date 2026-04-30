// https://leetcode.com/problems/compare-sums-of-bitonic-parts/description/

class Solution
{
public:
    int compareBitonicSums(const std::vector<int>& nums)
    {
        const int n = nums.size();

        int peak_idx = 0;
        long long left_sum = 0;

        while (peak_idx + 1 < n && nums[peak_idx] < nums[peak_idx + 1])
        {
            left_sum += nums[peak_idx++];
        }

        long long right_sum = 0;

        for (int i = peak_idx + 1; i < n; i++)
        {
            right_sum += nums[i];
        }

        return left_sum > right_sum ? 0 : left_sum < right_sum ? 1 : -1;
    }
};