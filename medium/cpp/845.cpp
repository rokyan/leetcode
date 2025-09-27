// https://leetcode.com/problems/longest-mountain-in-array/description/

class Solution
{
public:
    int longestMountain(vector<int>& arr)
    {
        const auto n = std::size(arr);

        auto res = 0;
        auto i = 0;

        while (i < n)
        {
            auto j = i;

            while (j + 1 < n && arr[j + 1] > arr[j])
            {
                j++;
            }

            if (j == i)
            {
                i++;
                continue;
            }

            auto k = j;

            while (k + 1 < n && arr[k + 1] < arr[k])
            {
                k++;
            }

            if (k == j)
            {
                i = k;
                continue;
            }

            res = std::max(res, k - i + 1);
            i = k;
        }

        return res;
    }
};