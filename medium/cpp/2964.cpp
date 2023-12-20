// https://leetcode.com/problems/number-of-divisible-triplet-sums/description/

class Solution
{
public:
    int divisibleTripletCount(std::vector<int>& nums, int d)
    {
        const auto n = std::size(nums);

        auto res = 0;

        for (auto i = 0; i + 2 < n; i++)
        {
            std::unordered_map<int, int> cnt;
            cnt[nums[i + 1] % d]++;

            for (auto j = i + 2; j < n; j++)
            {
                auto val = (d - (nums[i] + nums[j]) % d) % d;

                if (const auto it = cnt.find(val); it != std::end(cnt))
                {
                    res += it->second;
                }

                cnt[nums[j] % d]++;
            }
        }

        return res;
    }
};