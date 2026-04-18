// https://leetcode.com/problems/valid-subarrays-with-exactly-one-peak/description/

class Solution
{
public:
    long long validSubarrays(const std::vector<int>& nums, int k)
    {
        std::vector<int> positions;
        positions.reserve(nums.size());

        for (int i = 1; i + 1 < nums.size(); i++)
        {
            if (nums[i - 1] < nums[i] && nums[i] > nums[i + 1])
            {
                positions.push_back(i);
            }
        }

        if (positions.empty())
        {
            return 0;
        }

        positions.push_back(nums.size());

        long long res = 0;
        int prev = -1;

        for (int i = 0; i + 1 < positions.size(); i++)
        {
            res += 1LL * std::min(k + 1, (positions[i] - prev)) * std::min(k + 1, (positions[i + 1] - positions[i]));
            prev = positions[i];
        }

        return res;
    }
};