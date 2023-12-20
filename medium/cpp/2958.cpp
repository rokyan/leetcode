// https://leetcode.com/problems/length-of-longest-subarray-with-at-most-k-frequency/description/

class Solution
{
public:
    int maxSubarrayLength(std::vector<int>& nums, int k)
    {
        const auto n = std::size(nums);

        std::unordered_map<int, int> freq;

        auto res = 0;

        for (auto left = 0, right = 0; right < n; right++)
        {
            if (freq[nums[right]]++ == k)
            {
                while (freq[nums[right]] == k + 1)
                {
                    freq[nums[left++]]--;
                }
            }

            res = std::max(res, right - left + 1);
        }
        
        return res;
    }
};