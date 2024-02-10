// https://leetcode.com/problems/subarrays-with-k-different-integers/

class Solution
{
public:
    int subarraysWithKDistinct(vector<int>& nums, int k)
    {
        return count(nums, k) - count(nums, k + 1);
    }

private:
    int count(const std::vector<int>& nums, int k)
    {
        auto total = 0;

        std::unordered_map<int, int> freq;

        for (auto l = 0, r = 0, diff = 0; r < std::size(nums); r++)
        {
            if (freq[nums[r]]++ == 0)
            {
                diff++;
            }

            while (freq[nums[l]] > 1 || freq[nums[l]] == 1 && diff > k)
            {
                if (freq[nums[l++]]-- == 1)
                {
                    diff--;
                }
            }

            if (diff == k)
            {
                total += l + 1;
            }
        }

        return total;
    }
};