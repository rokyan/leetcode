// https://leetcode.com/problems/minimum-k-to-reduce-array-within-limit/description/

class Solution
{
public:
    int minimumK(const std::vector<int>& nums)
    {
        int lo = 1;
        int hi = 1000'000'000;

        while (lo < hi)
        {
            const int mid = lo + (hi - lo) / 2;
            int cnt = 0;

            for (int i = 0; i < nums.size() && cnt <= 1LL * mid * mid; i++)
            {
                cnt += (nums[i] + mid - 1) / mid;
            }

            if (cnt <= 1LL * mid * mid)
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
};