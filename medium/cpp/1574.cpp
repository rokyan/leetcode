// https://leetcode.com/problems/shortest-subarray-to-be-removed-to-make-array-sorted/description/

class Solution
{
public:
    int findLengthOfShortestSubarray(std::vector<int>& arr)
    {
        const auto n = static_cast<int>(std::size(arr));
        auto l = 0;

        while (l + 1 < n && arr[l + 1] >= arr[l])
        {
            l++;
        }

        if (l == n - 1)
        {
            return 0;
        }

        auto r = n - 1;

        while (r - 1 >= 0 && arr[r - 1] <= arr[r])
        {
            r--;
        }

        auto tot = std::max(l + 1, n - r);

        for (auto i = 0, p = r; i <= l; i++)
        {
            while (p < n && arr[p] < arr[i])
            {
                p++;
            }

            if (p == n)
            {
                break;
            }

            tot = std::max(tot, i + 1 + n - p);
        }

        return n - tot;
    }
};