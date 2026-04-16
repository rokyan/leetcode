// https://leetcode.com/problems/sum-of-sortable-integers/description/

class Solution
{
public:
    int sortableIntegers(const std::vector<int>& nums)
    {
        const int n = nums.size();

        int res = 0;

        for (int k = 1; k * k <= n; k++)
        {
            if (n % k != 0)
            {
                continue;
            }

            if (solve(nums, k))
            {
                res += k;
            }

            if (k * k != n && solve(nums, n / k))
            {
                res += n / k;
            }
        }

        return res;
    }

private:
    bool solve(const std::vector<int>& nums, int k)
    {
        const int n = nums.size();
        int lastMax = -1;

        for (int start = 0; start < n; start += k)
        {
            const int end = start + k;
            int pos = start;

            while (pos + 1 < end && nums[pos] <= nums[pos + 1])
            {
                pos++;
            }

            if (pos == end - 1)
            {
                // sorted
                const int minVal = nums[start];
                const int maxVal = nums[end - 1];

                if (minVal < lastMax)
                {
                    return false;
                }

                lastMax = maxVal;
            }
            else
            {
                const int maxVal = nums[pos];
                const int minVal = nums[pos + 1];
                pos++;

                while (pos + 1 < end && nums[pos] <= nums[pos + 1])
                {
                    pos++;
                }

                if (pos < end - 1)
                {
                    return false;
                }

                if (nums[end - 1] > nums[start])
                {
                    return false;
                }

                if (minVal < lastMax)
                {
                    return false;
                }

                lastMax = maxVal;
            }
        }

        return true;
    }
};