// https://leetcode.com/problems/count-distinct-subarrays-divisible-by-k-in-sorted-array/description/

class Solution
{
public:
    long long numGoodSubarrays(const std::vector<int>& nums, int k)
    {
        const int n = std::size(nums);

        std::vector<int> pref(nums);

        for (int i = 1; i < n; i++)
        {
            pref[i] += pref[i - 1];
            pref[i] %= k;
        }

        std::unordered_map<int, int> freq;
        freq[0] = 1;

        int sum = 0;
        long long res = 0LL;
        int same_cnt = 0;
        int prev = 0;

        for (int i = 0; i < n; i++)
        {
            sum = (sum + nums[i]) % k;
            res += freq[sum];
            freq[sum]++;
            const int len = k / gcd(nums[i], k);

            if (i > 0 && nums[i] == nums[i - 1])
            {
                res -= prev;
                prev = ++same_cnt / len;
            }
            else
            {
                same_cnt = 1;
                prev = 1 / len;
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