// https://leetcode.com/problems/maximum-erasure-value/description/

class Solution
{
public:
    int maximumUniqueSubarray(std::vector<int>& nums)
    {
        std::unordered_map<int, int> freq;
        auto res = 0;

        for (auto l = 0, r = 0, s = 0; r < std::size(nums); r++)
        {
            s += nums[r];

            if (freq[nums[r]]++ == 1)
            {
                while (freq[nums[r]] == 2)
                {
                    s -= nums[l];
                    freq[nums[l++]]--;
                }
            }

            res = std::max(res, s);
        }

        return res;
    }
};