class Solution
{
public:
    int subarraySum(const std::vector<int>& nums, int k)
    {
        std::unordered_map<int, int> pref_sum_freq;
        pref_sum_freq[0] = 1;

        auto res = 0;

        for (auto pos = 0, sum = 0; pos < std::size(nums); pos++)
        {
            sum += nums[pos];
            res += pref_sum_freq[sum - k];
            pref_sum_freq[sum]++;
        }

        return res;
    }
};