// https://leetcode.com/problems/stable-subarrays-with-equal-boundary-and-interior-sum/description/

class Solution
{
public:
    long long countStableSubarrays(const std::vector<int>& capacity)
    {
        const int n = std::size(capacity);

        std::unordered_map<int, std::unordered_map<long long, int>> prefSums;
        long long sum = 0;
        long long res = 0;

        for (int i = 0; i < n; i++)
        {
            sum += capacity[i];

            if (i > 1)
            {
                prefSums[capacity[i - 2]][sum - capacity[i] - capacity[i - 1]]++;
            }

            if (const auto it = prefSums.find(capacity[i]); it != std::cend(prefSums))
            {
                res += it->second[sum - 2 * capacity[i]];
            }
        }

        return res;
    }
};