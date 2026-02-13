// https://leetcode.com/problems/delayed-count-of-equal-elements/description/

class Solution
{
public:
    std::vector<int> delayedCount(const std::vector<int>& nums, int k)
    {
        const int n = nums.size();
        std::unordered_map<int, int> freq;
        std::vector<int> res(n);

        for (int i = n - 1, j = n - 1; i >= 0; i--)
        {
            while (i + k < j)
            {
                freq[nums[j--]]++;
            }

            res[i] = freq[nums[i]];
        }

        return res;
    }
};