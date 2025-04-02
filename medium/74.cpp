// https://leetcode.com/problems/search-a-2d-matrix/description/

class Solution
{
public:
    bool searchMatrix(const std::vector<std::vector<int>>& matrix, int target)
    {
        const int n = std::size(matrix);
        const int m = std::size(matrix.front());

        int lo = 0;
        int hi = n * m - 1;

        while (lo <= hi)
        {
            const auto mid = lo + (hi - lo) / 2;
            const auto value = matrix[mid / m][mid % m];

            if (value < target)
            {
                lo = mid + 1;
            }
            else if (value > target)
            {
                hi = mid - 1;
            }
            else
            {
                return true;
            }
        }

        return false;
    }
};