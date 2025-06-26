// https://leetcode.com/problems/painting-a-grid-with-three-different-colors/description/

class Solution
{
private:
    static constexpr int MOD = 1000 * 1000 * 1000 + 7;
    
public:
    int colorTheGrid(int m, int n)
    {
        const auto masks = gen_masks(m);
        const auto sz = std::size(masks);
        
        std::vector<int> dp(sz, 1);
        
        for (int i = 1; i < n; i++)
        {
            std::vector<int> n_dp(sz);
            
            for (int j = 0; j < sz; j++)
            {
                for (int k = 0; k < sz; k++)
                {
                    bool match = true;
                    
                    for (int h = 0; h < m; h++)
                    {
                        if (masks[j][h] == masks[k][h])
                        {
                            match = false;
                            break;
                        }
                    }
                    
                    if (match)
                    {
                        n_dp[k] += dp[j];
                        n_dp[k] %= MOD;
                    }
                }
            }
            
            dp = n_dp;
        }
        
        int ans = 0;
        
        for (int i = 0; i < sz; i++)
        {
            ans += dp[i];
            ans %= MOD;
        }
        
        return ans;
    }
    
private:
    std::vector<std::vector<int>> gen_masks(int len)
    {
        if (len == 1)
        {
            return { { 0 }, { 1 }, { 2 } };
        }
        
        auto masks = gen_masks(len - 1);
        
        std::vector<std::vector<int>> upd_masks;
        
        for (const auto& mask : masks)
        {
            for (int color = 0; color < 3; color++)
            {
                if (mask.back() != color)
                {
                    auto upd_mask = mask;
                    upd_mask.push_back(color);
                    upd_masks.push_back(upd_mask);
                }
            }
        }
        
        return upd_masks;
    }
};