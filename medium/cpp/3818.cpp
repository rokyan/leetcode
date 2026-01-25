// https://leetcode.com/problems/minimum-prefix-removal-to-make-array-strictly-increasing/description/

class Solution
{
public:
    int minimumPrefixLength(const std::vector<int>& nums)
    {
        const int n = nums.size();

        int count = 1;

        for (int i = n - 2; i >= 0; i--)
        {
            if (nums[i] < nums[i + 1])
            {
                count++;
            }
            else
            {
                break;
            }
        }

        return n - count;
    }
};