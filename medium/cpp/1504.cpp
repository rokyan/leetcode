// https://leetcode.com/problems/count-submatrices-with-all-ones/

class Solution
{
public:
    int numSubmat(std::vector<std::vector<int>>& mat)
    {
        const auto n = std::size(mat);
        const auto m = std::size(mat.front());
        
        std::vector<std::vector<int>> dp(n, std::vector<int>(m));
        
        dp[0] = mat[0];
        
        for (int j = 0; j < m; j++)
        {
            for (int i = 1; i < n; i++)
            {
                dp[i][j] = mat[i][j] == 1 ? dp[i - 1][j] + 1 : 0;
            }
        }
        
        auto ans = 0;
        
        std::vector<int> st;
        std::vector<int> acc(m);
        
        for (int i = 0; i < n; i++)
        {
            st.clear();

            std::fill(std::begin(acc), std::end(acc), 0);
            
            for (int j = 0; j < m; j++)
            {
                while (!st.empty() && dp[i][st.back()] >= dp[i][j])
                {
                    st.pop_back();
                }
                
                if (!st.empty())
                {
                    const auto idx = st.back();
                    
                    acc[j] = (j - idx) * dp[i][j] + acc[idx];
                }
                else
                {
                    acc[j] = (j + 1) * dp[i][j];
                }
                
                st.push_back(j);
                
                ans += acc[j];
            }
        }
        
        return ans;
    }
};