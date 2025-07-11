// https://leetcode.com/problems/make-a-positive-array/description/

class Solution
{
public:
    int makeArrayPositive(std::vector<int>& nums)
    {
        std::vector<long long> lnums(std::size(nums));
        lnums[0] = nums[0];
        lnums[1] = nums[1];

        auto res = 0;

        for (auto i = 2; i < std::size(nums); i++)
        {
            lnums[i] = nums[i];

            auto sum = lnums[i] + lnums[i - 1] + lnums[i - 2];

            if (sum <= 0)
            {
                res++;
                lnums[i] = 1e18;
                continue;
            }

            if (i >= 3)
            {
                sum += lnums[i - 3];

                if (sum <= 0)
                {
                    res++;
                    lnums[i] = 1e18;
                    continue;
                }
            }

            if (i >= 4)
            {
                sum += lnums[i - 4];

                if (sum <= 0)
                {
                    res++;
                    lnums[i] = 1e18;
                }
            }
        }

        return res;
    }
};