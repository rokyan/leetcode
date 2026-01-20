// https://leetcode.com/problems/sum-of-consecutive-subsequences/description/

class Solution
{
private:
    static constexpr int mod = 1000'000'007;

public:
    int getSum(const std::vector<int>& nums)
    {
        const int n = nums.size();

        std::unordered_map<int, std::pair<int, int>> inc, dec;

        for (int i = 0; i < n; i++)
        {
            if (const auto it = inc.find(nums[i] - 1); it == inc.end())
            {
                inc[nums[i]].first++;
                inc[nums[i]].first %= mod;
                inc[nums[i]].second += nums[i];
                inc[nums[i]].second %= mod;
            }
            else
            {
                inc[nums[i]].first += 1 + it->second.first;
                inc[nums[i]].first %= mod;
                inc[nums[i]].second += (1LL * nums[i] * (1 + it->second.first) % mod + it->second.second) % mod;
                inc[nums[i]].second %= mod;
            }

            if (const auto it = dec.find(nums[i] + 1); it == dec.end())
            {
                dec[nums[i]].first++;
                dec[nums[i]].first %= mod;
                dec[nums[i]].second += nums[i];
                dec[nums[i]].second %= mod;
            }
            else
            {
                dec[nums[i]].first += 1 + it->second.first;
                dec[nums[i]].first %= mod;
                dec[nums[i]].second += (1LL * nums[i] * (1 + it->second.first) % mod + it->second.second) % mod;
                dec[nums[i]].second %= mod;
            }
        }

        int res = 0;

        for (const auto [_, val] : inc)
        {
            res += val.second;
            res %= mod;
        }

        for (const auto [_, val] : dec)
        {
            res += val.second;
            res %= mod;
        }

        for (int num : nums)
        {
            res = (res - num + mod) % mod;
        }

        return res;
    }
};