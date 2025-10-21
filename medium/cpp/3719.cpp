// https://leetcode.com/problems/longest-balanced-subarray-i/description/

class Solution
{
public:
    int longestBalanced(std::vector<int>& nums)
    {
        const int n = std::size(nums);
        int res = 0;

        for (int i = 0; i < n; i++)
        {
            std::unordered_set<int> even, odd;

            for (int j = i; j < n; j++)
            {
                if (nums[j] % 2 == 0)
                {
                    even.insert(nums[j]);
                }
                else
                {
                    odd.insert(nums[j]);
                }

                if (std::size(even) == std::size(odd))
                {
                    res = std::max(res, j - i + 1);
                }
            }
        }

        return res;
    }
};