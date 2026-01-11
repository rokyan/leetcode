// https://leetcode.com/problems/number-of-centered-subarrays/description/

class Solution
{
public:
    int centeredSubarrays(const std::vector<int>& nums)
    {
        const int n = nums.size();
        int res = 0;

        for (int l = 0; l < n; l++)
        {
            std::unordered_set<int> probe;
            int sum = 0;

            for (int r = l; r < n; r++)
            {
                probe.insert(nums[r]);
                sum += nums[r];

                if (probe.count(sum))
                {
                    res++;
                }
            }
        }

        return res;
    }
};