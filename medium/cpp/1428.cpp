// https://leetcode.com/problems/leftmost-column-with-at-least-a-one/description/

/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int row, int col);
 *     vector<int> dimensions();
 * };
 */

class Solution
{
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix)
    {
        auto res = -1;

        const auto& dim = binaryMatrix.dimensions();

        for (auto i = 0; i < dim[0]; i++)
        {
            auto lo = 0;
            auto hi = dim[1] - 1;

            if (binaryMatrix.get(i, hi) == 0)
            {
                continue;
            }

            while (lo < hi)
            {
                const auto mid = lo + (hi - lo) / 2;

                if (binaryMatrix.get(i, mid) == 1)
                {
                    hi = mid;
                }
                else
                {
                    lo = mid + 1;
                }
            }

            if (res == -1)
            {
                res = lo;
            }
            else
            {
                res = std::min(res, lo);
            }
        }

        return res;
    }
};