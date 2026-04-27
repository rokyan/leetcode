// https://leetcode.com/problems/minimum-operations-to-make-array-non-decreasing/description/

class Solution
{
public:
    long long minOperations(const std::vector<int>& nums)
    {
        const int n = nums.size();

        long long last = nums[0];
        long long acc = 0;
        long long res = 0;

        for (int i = 1; i < n; i++)
        {
            if (nums[i] + acc < last)
            {
                const long long x = last - acc - nums[i];
                res += x;
                acc += x;
            }

            last = nums[i] + acc;
        }

        return res;
    }
};