// https://leetcode.com/problems/count-elements-with-at-least-k-greater-values/description/

class Solution
{
public:
    int countElements(std::vector<int>& nums, int k)
    {
        if (k == 0)
        {
            return std::size(nums);
        }
    
        std::ranges::sort(nums, std::greater<int>{});
        int res = 0;

        for (int i = 1, g = 0; i < std::size(nums); i++)
        {
            if (nums[i - 1] > nums[i])
            {
                g = i;

                if (g >= k)
                {
                    return std::size(nums) - i;
                }
            }
        }

        return 0;
    }
};