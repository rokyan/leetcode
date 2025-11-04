// https://leetcode.com/problems/split-array-with-minimum-difference/description/

class Solution
{
public:
    long long splitArray(const std::vector<int>& nums)
    {
        const int n = std::size(nums);

        int l = 0;
        long long lsum = nums.front();

        for (int i = 1; i < n; i++)
        {
            if (nums[i] > nums[i - 1])
            {
                lsum += nums[i];
                l++;
            }
            else
            {
                break;
            }
        }

        int r = n - 1;
        long long rsum = nums.back();

        for (int i = n - 2; i >= 0; i--)
        {
            if (nums[i] > nums[i + 1])
            {
                rsum += nums[i];
                r--;
            }
            else
            {
                break;
            }
        }

        if (l == r)
        {
            return std::min(std::abs(rsum - (lsum - nums[l])), std::abs(lsum - (rsum - nums[l])));
        }

        if (l + 1 == r)
        {
            return std::abs(lsum - rsum);
        }

        return -1;
    }
};