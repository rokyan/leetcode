// https://leetcode.com/problems/maximum-element-sum-of-a-complete-subset-of-indices/description/

class Solution
{
public:
    long long maximumSum(std::vector<int>& nums)
    {
        std::unordered_map<int, long long> cnt;

        const auto n = std::size(nums);

        auto res = 0LL;

        for (auto idx = 1; idx <= n; idx++)
        {
            auto val = idx;
            auto key = 1;

            for (auto i = 2; i * i <= val; i++)
            {
                auto times = 0;

                while (val % i == 0)
                {
                    times++;
                    val /= i;
                }

                if (times % 2 == 1)
                {
                    key *= i;
                }
            }

            if (val > 1)
            {
                key *= val;
            }

            cnt[key] += nums[idx - 1];
            res = std::max(res, cnt[key]);
        }

        return res;
    }
};