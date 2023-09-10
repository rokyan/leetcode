// https://leetcode.com/problems/maximum-side-length-of-a-square-with-sum-less-than-or-equal-to-threshold/description/

class Solution
{
public:
    int maxSideLength(std::vector<std::vector<int>>& mat, int threshold)
    {
        const auto n = std::size(mat);
        const auto m = std::size(mat.front());
        
        std::vector<std::vector<int>> par(mat);
        
        for (std::size_t i = 0; i < n; i++)
        {
            for (std::size_t j = 0; j < m; j++)
            {
                if (i > 0)
                {
                    par[i][j] += par[i - 1][j];
                }
                
                if (j > 0)
                {
                    par[i][j] += par[i][j - 1];
                }
                
                if (i > 0 && j > 0)
                {
                    par[i][j] -= par[i - 1][j - 1];
                }
            }
        }
        
        int ans = -1;
        
        for (std::size_t i = 0; i < n; i++)
        {
            for (std::size_t j = 0; j < m; j++)
            {
                const auto k = std::min(i, j);
                
                for (int kk = ans + 1; kk <= k; kk++)
                {
                    if (get(i, j, kk, par) <= threshold)
                    {
                        ans = kk;
                    }
                    else
                    {
                        break;
                    }
                }
            }
        }
        
        return ans + 1;
    }
    
private:
    int get(std::size_t i, std::size_t j, int k, const std::vector<std::vector<int>>& par)
    {
        auto sum = par[i][j];
        
        const auto ii = i - k;
        const auto jj = j - k;
        
        if (ii > 0)
        {
            sum -= par[ii - 1][j];
        }
        
        if (jj > 0)
        {
            sum -= par[i][jj - 1];
        }
        
        if (ii > 0 && jj > 0)
        {
            sum += par[ii - 1][jj - 1];
        }
        
        return sum;
    }
};