// https://leetcode.com/problems/maximum-sum-obtained-of-any-permutation/

class Solution
{
private:
    static constexpr auto mod = 1000'000'000 + 7;

public:
    int maxSumRangeQuery(std::vector<int>& nums, std::vector<std::vector<int>>& requests)
    {
        const auto n = std::size(nums);

        std::vector<int> freq(n);

        for (const auto& req : requests)
        {
            freq[req[0]]++;

            if (req[1] + 1 < n)
            {
                freq[req[1] + 1]--;
            }
        }

        for (auto i = 1; i < n; i++)
        {
            freq[i] += freq[i - 1];
        }

        std::sort(std::begin(freq), std::end(freq));
        std::sort(std::begin(nums), std::end(nums));

        auto res = 0;

        for (auto i = 0; i < n; i++)
        {
            res += 1LL * freq[i] * nums[i] % mod;
            res %= mod;
        }

        return res;
    }
};