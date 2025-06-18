// https://leetcode.com/problems/count-special-triplets/description/

class Solution
{
private:
    static constexpr auto mod = 1000'000'007;

public:
    int specialTriplets(std::vector<int>& nums)
    {
        std::unordered_map<int, int> leftFreq, rightFreq;

        for (auto num : nums)
        {
            rightFreq[num]++;
        }

        auto res = 0;

        for (auto num : nums)
        {
            rightFreq[num]--;
            res += 1LL * leftFreq[num * 2] * rightFreq[num * 2] % mod;
            res %= mod;
            leftFreq[num]++;
        }

        return res;
    }
};