// https://leetcode.com/problems/minimum-operations-to-reach-target-array/description/

class Solution
{
public:
    int minOperations(const std::vector<int>& nums, const std::vector<int>& target)
    {
        std::unordered_set<int> un;

        const int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            if (nums[i] != target[i])
            {
                un.insert(nums[i]);
            }
        }

        return un.size();
    }
};