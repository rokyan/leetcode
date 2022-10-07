// https://leetcode.com/problems/maximum-element-after-decreasing-and-rearranging/

class Solution
{
public:
    int maximumElementAfterDecrementingAndRearranging(std::vector<int>& arr)
    {
        std::sort(std::begin(arr), std::end(arr));
        
        if (arr[0] > 1)
        {
            arr[0] = 1;
        }
        
        for (int i = 1; i < std::size(arr); i++)
        {
            if (arr[i] - arr[i - 1] > 1)
            {
                arr[i] = arr[i - 1] + 1;
            }
        }
        
        return arr.back();
    }
};