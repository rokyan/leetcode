// https://leetcode.com/problems/kth-smallest-subarray-sum/

class Solution
{
public:
    int kthSmallestSubarraySum(std::vector<int>& nums, int k)
    {
        auto lo = 0;
        auto hi = std::accumulate(std::cbegin(nums), std::cend(nums), 0);

        while (lo < hi)
        {
            const auto mid = lo + (hi - lo) / 2;
            const auto total = calc(nums, mid);

            if (total >= k)
            {
                hi = mid;
            }
            else
            {
                lo = mid + 1;
            }
        }

        return lo;
    }

private:
    static int calc(const std::vector<int>& nums, int lim)
    {
        auto total = 0;

        for (auto l = 0, r = 0, s = 0; r < std::size(nums); r++)
        {
            s += nums[r];

            while (s > lim)
            {
                s -= nums[l++];
            }

            total += r - l + 1;
        }

        return total;
    }
};