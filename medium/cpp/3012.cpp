// https://leetcode.com/problems/minimize-length-of-array-using-operations/description/

class Solution
{
public:
    int minimumArrayLength(std::vector<int>& nums)
    {
        const auto n = std::size(nums);

        if (n == 1)
        {
            return 1;
        }

        std::ranges::sort(nums);

        auto cnt = 0;

        for (auto i = 0; i < n; i++)
        {
            if (nums[i] == nums[0])
            {
                cnt++;
            }
            else if (nums[i] % nums[0])
            {
                return 1;
            }
        }

        return (cnt + 1) / 2;
    }
};