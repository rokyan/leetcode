// https://leetcode.com/problems/construct-uniform-parity-array-ii/description/

class Solution
{
public:
    bool uniformArray(const std::vector<int>& nums1)
    {
        int minOdd = -1;
        int minEven = -1;

        const int n = nums1.size();

        for (int i = 0; i < n; i++)
        {
            if (nums1[i] % 2 == 1)
            {
                minOdd = minOdd == -1 ? nums1[i] : std::min(minOdd, nums1[i]);
            }
            else
            {
                minEven = minEven == -1 ? nums1[i] : std::min(minEven, nums1[i]);
            }
        }

        if (minOdd == -1 || minEven == -1)
        {
            return true;
        }

        bool canMakeOdd = true;

        for (int i = 0; i < n; i++)
        {
            if (nums1[i] % 2 == 0 && minOdd > nums1[i])
            {
                canMakeOdd = false;
                break;
            }
        }

        if (canMakeOdd)
        {
            return true;
        }

        return false;
    }
};