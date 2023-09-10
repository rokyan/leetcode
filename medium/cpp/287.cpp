// https://leetcode.com/problems/find-the-duplicate-number/description/

class Solution
{
public:
    int findDuplicate(std::vector<int>& nums)
    {
        for (auto i = 0; i < std::size(nums); i++)
        {
            if (nums[abs(nums[i]) - 1] < 0)
            {
                return abs(nums[i]);
            }

            nums[abs(nums[i]) - 1] *= -1;
        }

        return -1;
    }
};