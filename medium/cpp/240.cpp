// https://leetcode.com/problems/search-a-2d-matrix-ii/

class Solution
{
public:
    bool searchMatrix(std::vector<std::vector<int>>& matrix, int target)
    {
        const auto n = std::size(matrix);
        const auto m = std::size(matrix.front());
        
        int i = 0;
        int j = m - 1;
        
        while (i < n && j >= 0)
        {
            if (matrix[i][j] == target)
            {
                return true;
            }
            
            if (matrix[i][j] > target)
            {
                j--;
            }
            else
            {
                i++;
            }
        }
        
        return false;
    }
};