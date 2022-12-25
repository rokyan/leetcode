// https://leetcode.com/problems/peak-index-in-a-mountain-array/description/

class Solution
{
public:
    int peakIndexInMountainArray(std::vector<int>& arr)
    {
        auto i = 0;

        while (arr[i + 1] > arr[i])
        {
            i++;
        }

        return i;
    }
};