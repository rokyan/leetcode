// https://leetcode.com/problems/longest-subsequence-with-non-zero-bitwise-xor/description/

class Solution
{
public:
    int longestSubsequence(const std::vector<int>& nums)
    {
        const int n = std::size(nums);

        int zeroes = 0;
        int nonZeroesXor = 0;

        for (int i = 0; i < n; i++)
        {
            if (nums[i] == 0)
            {
                zeroes++;
            }
            else
            {
                nonZeroesXor ^= nums[i];
            }
        }

        if (zeroes == n)
        {
            return 0;
        }

        if (nonZeroesXor == 0)
        {
            return n - 1;
        }

        return n;
    }
};