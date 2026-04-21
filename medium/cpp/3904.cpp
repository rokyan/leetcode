// https://leetcode.com/problems/smallest-stable-index-ii/description/

class Solution
{
public:
    int firstStableIndex(const std::vector<int>& nums, int k)
    {
        std::vector<int> minOnSuff(nums);

        const int n = nums.size();

        for (int i = n - 2; i >= 0; i--)
        {
            minOnSuff[i] = std::min(minOnSuff[i], minOnSuff[i + 1]);
        }

        int maxSoFar = nums[0];

        for (int i = 0; i < n; i++)
        {
            maxSoFar = std::max(maxSoFar, nums[i]);

            if (maxSoFar - minOnSuff[i] <= k)
            {
                return i;
            }
        }

        return -1;
    }
};