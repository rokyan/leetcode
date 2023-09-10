// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/description/

class Solution
{
public:
    std::vector<int> twoSum(std::vector<int>& numbers, int target)
    {
        for (int i = 0, j = std::size(numbers) - 1; i < j; i++)
        {
            while (i < j && numbers[i] + numbers[j] > target)
            {
                j--;
            }
            
            if (i < j && numbers[i] + numbers[j] == target)
            {
                return { i + 1, j + 1 };
            }
        }
        
        return {};
    }
};