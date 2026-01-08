// https://leetcode.com/problems/minimum-subarray-length-with-distinct-sum-at-least-k/description/

class Solution
{
public:
    int minLength(const std::vector<int>& nums, int k)
    {
        const int n = nums.size();

        std::map<int, int> freq;
        int sum = 0;
        int res = 2 * n;

        for (int l = 0, r = 0; l < n; l++)
        {
            while (r < n && sum < k)
            {
                if (freq[nums[r]]++ == 0)
                {
                    sum += nums[r];
                }

                r++;
            }

            if (sum >= k)
            {
                res = std::min(res, r - l);
            }

            if (freq[nums[l]]-- == 1)
            {
                sum -= nums[l];
            }
        }

        return res == 2 * n ? -1 : res;
    }
};