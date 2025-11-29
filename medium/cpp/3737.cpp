// https://leetcode.com/problems/count-subarrays-with-majority-element-i/description/

class Solution
{
public:
    int countMajoritySubarrays(const std::vector<int>& nums, int target)
    {
        const int n = std::size(nums);

        int res = 0;

        for (int l = 0; l < n; l++)
        {
            int cnt = 0;

            for (int r = l; r < n; r++)
            {
                cnt += nums[r] == target;

                if (cnt > (r - l + 1) / 2)
                {
                    res++;
                }
            }
        }

        return res;
    }
};