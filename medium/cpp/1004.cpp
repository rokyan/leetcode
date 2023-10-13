// https://leetcode.com/problems/max-consecutive-ones-iii/description/

class Solution
{
public:
    int longestOnes(std::vector<int>& nums, int k)
    {
        auto res = 0;
        auto cnt = 0;

        for (auto r = 0, l = 0; r < std::size(nums); r++)
        {
            if (nums[r] == 0)
            {
                cnt++;
            }

            while (cnt == k + 1)
            {
                cnt -= nums[l] == 0;
                l++;
            }

            res = std::max(res, r - l + 1);
        }

        return res;
    }
};