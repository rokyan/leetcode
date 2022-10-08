// https://leetcode.com/problems/find-kth-largest-xor-coordinate-value/

class Solution
{
public:
    int kthLargestValue(std::vector<std::vector<int>>& matrix, int k)
    {
        const auto n = std::size(matrix);
        const auto m = std::size(matrix.front());
        
        std::vector<std::vector<int>> par_xor(n, std::vector<int>(m));
        
        std::priority_queue<int, std::vector<int>, std::greater<int> > min_heap;
        
        for (std::size_t i = 0; i < n; i++)
        {
            for (std::size_t j = 0; j < m; j++)
            {
                par_xor[i][j] = matrix[i][j];
                
                if (i > 0)
                {
                    par_xor[i][j] ^= par_xor[i - 1][j];
                }
                
                if (j > 0)
                {
                    par_xor[i][j] ^= par_xor[i][j - 1];
                }
                
                if (i > 0 && j > 0)
                {
                    par_xor[i][j] ^= par_xor[i - 1][j - 1];
                }
                
                min_heap.push(par_xor[i][j]);
                
                if (min_heap.size() > k)
                {
                    min_heap.pop();
                }
            }
        }
        
        return min_heap.top();
    }
};