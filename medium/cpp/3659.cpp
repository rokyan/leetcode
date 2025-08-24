// https://leetcode.com/problems/partition-array-into-k-distinct-groups/description/

class Solution
{
public:
    bool partitionArray(const std::vector<int>& nums, int k)
    {
        const auto n = std::size(nums);

        if (n % k)
        {
            return false;
        }

        std::unordered_map<int, int> freq;

        for (auto num : nums)
        {
            if (freq[num]++ == n / k)
            {
                return false;
            }
        }

        return true;
    }
};