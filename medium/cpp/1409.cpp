// https://leetcode.com/problems/queries-on-a-permutation-with-key/

class Solution
{
public:
    std::vector<int> processQueries(std::vector<int>& queries, int m)
    {       
        std::vector<int> permutation(m);
        
        for (std::size_t pos = 0; pos < m; pos++)
        {
            permutation[pos] = pos + 1;
        }

        std::vector<int> result(std::size(queries));
        
        for (std::size_t query_idx = 0; query_idx < std::size(queries); query_idx++)
        {
            int pos = 0;
            
            while (pos < m && permutation[pos] != queries[query_idx])
            {
                pos++;
            }
            
            for (int i = pos; i > 0; i--)
            {
                permutation[i] = permutation[i - 1];
            }
            
            permutation[0] = queries[query_idx];
            
            result[query_idx] = pos;
        }
        
        return result;
    }
};