// https://leetcode.com/problems/minimum-number-of-operations-to-have-distinct-elements/description/

class Solution
{
public:
    int minOperations(const std::vector<int>& nums)
    {
        int pos = std::size(nums) - 1;

        std::unordered_set<int> un;

        while (pos >= 0)
        {
            if (!un.insert(nums[pos]).second)
            {
                break;
            }

            pos--;
        }

        return (pos + 3) / 3;
    }
};