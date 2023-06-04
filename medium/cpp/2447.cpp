// https://leetcode.com/problems/number-of-subarrays-with-gcd-equal-to-k/description/

class Solution
{
public:
    int subarrayGCD(vector<int>& nums, int k)
    {
        const auto n = std::size(nums);

        auto res = 0;

        for (auto i = 0; i < n; i++)
        {
            auto val = nums[i];

            for (auto j = i; j < n; j++)
            {
                val = gcd(val, nums[j]);

                if (val == k)
                {
                    res++;
                }

                if (val < k)
                {
                    break;
                }
            }
        }
        
        return res;
    }

private:
    int gcd(int x, int y)
    {
        if (x == 0)
        {
            return y;
        }

        return gcd(y % x, x);
    }
};