// https://leetcode.com/problems/maximum-frequency-score-of-a-subarray/

class Solution
{
private:
    static constexpr auto mod = 1000'000'000 + 7;

public:
    int maxFrequencyScore(std::vector<int>& nums, int k)
    {
        std::unordered_map<int, int> freq;

        for (auto i = 0; i < k; i++)
        {
            freq[nums[i]]++;
        }

        auto sum = 0;

        for (const auto& e : freq)
        {
            sum += pow(e.first, e.second);
            sum %= mod;
        }

        auto res = sum;

        for (auto i = k; i < std::size(nums); i++)
        {
            if (const auto it = freq.find(nums[i]); it != std::end(freq))
            {
                sum -= pow(nums[i], it->second);
                sum = (sum + mod) % mod;
                it->second++;
                sum += pow(nums[i], it->second);
                sum %= mod;
            }
            else
            {
                sum += nums[i];
                sum %= mod;
                freq.emplace(nums[i], 1);
            }

            const auto it = freq.find(nums[i - k]);
            sum -= pow(nums[i - k], it->second);
            sum = (sum + mod) % mod;
            it->second--;

            if (it->second > 0)
            {
                sum += pow(nums[i - k], it->second);
                sum %= mod;
            }
            else
            {
                freq.erase(it);
            }

            res = std::max(res, sum);
        }

        return res;
    }

private:
    int pow(int x, int p)
    {
        if (p == 0)
        {
            return 1;
        }
 
        if (p % 2 == 1)
        {
            return 1LL * x * pow(x, p - 1) % mod;
        }

        const auto temp = pow(x, p / 2);
        return 1LL * temp * temp % mod; 
    }
};