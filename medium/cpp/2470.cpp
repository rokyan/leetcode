// https://leetcode.com/problems/number-of-subarrays-with-lcm-equal-to-k/description/

class Solution
{
public:
    int subarrayLCM(std::vector<int>& nums, int k)
    {
        const auto n = std::size(nums);

        auto res = 0;

        for (auto i = 0; i < n; i++)
        {
            auto v = nums[i];

            for (auto j = i; j < n; j++)
            {
                v = lcm(v, nums[j]);

                if (v == k)
                {
                    res++;
                }

                if (v > k)
                {
                    break;
                }
            }
        }

        return res;
    }

private:
    int gcd(int a, int b)
    {
        if (a == 0)
        {
            return b;
        }

        return gcd(b % a, a);
    }

    int lcm(int a, int b)
    {
        return a * b / gcd(a, b);
    }
};