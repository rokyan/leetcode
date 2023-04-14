// https://leetcode.com/problems/minimum-deletions-to-make-array-beautiful/description/

class Solution
{
public:
    int minDeletion(std::vector<int>& nums)
    {
        auto cnt = 0;
        auto p = 0;

        for (auto i = 1; i < std::size(nums); i++)
        {
            if (nums[i] != nums[p])
            {
                cnt++;
                p = i + 1;
                i++;
            }
        }

        return std::size(nums) - cnt * 2;
    }
};