// https://leetcode.com/problems/longest-nice-subarray/description/

class Solution
{
public:
    int longestNiceSubarray(std::vector<int>& nums)
    {
        auto ans = 1;
        auto len = 1;
        auto mask = nums[0];
        auto left = 0;

        for (auto i = 1; i < std::size(nums); i++)
        {
            if ((mask & nums[i]) == 0)
            {
                len++;
                mask |= nums[i];
            }
            else
            {
                while ((mask & nums[i]) != 0)
                {
                    mask ^= nums[left++];
                    len--;
                }

                len++;
                mask |= nums[i];
            }

            ans = std::max(ans, len);
        }

        return ans;
    }
};