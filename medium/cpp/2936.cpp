// https://leetcode.com/problems/number-of-equal-numbers-blocks/description/

/**
 * Definition for BigArray.
 * class BigArray {
 * public:
 *     BigArray(vector<int> elements);
 *     int at(long long index);
 *     long long size();
 * };
 */
class Solution
{
public:
    int countBlocks(BigArray* nums)
    {
        auto res = 0;
        auto last = 0LL;
        const auto n = nums->size();

        while (last < n)
        {
            auto lo = last;
            auto hi = n - 1;
            const auto val = nums->at(last);

            while (lo < hi)
            {
                const auto mid = lo + (hi - lo + 1) / 2;

                if (nums->at(mid) != val)
                {
                    hi = mid - 1;
                }
                else
                {
                    lo = mid;
                }
            }

            res++;

            last = lo + 1;
        }

        return res;
    }
};