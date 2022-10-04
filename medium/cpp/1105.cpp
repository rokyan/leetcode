// https://leetcode.com/problems/filling-bookcase-shelves/

class Solution
{
public:
    int minHeightShelves(std::vector<std::vector<int>>& books, int shelfWidth)
    {
        const auto n = std::size(books);
                
        std::vector<int> dp(n);
        
        for (int i = 0; i < n; i++)
        {
            dp[i] = books[i][1] + (i > 0 ? dp[i - 1] : 0);
            
            int width = books[i][0];
            int cur = books[i][1];
            
            for (int j = i - 1; j >= 0; j--)
            {
                if (width + books[j][0] <= shelfWidth)
                {
                    width += books[j][0];
                    cur = std::max(cur, books[j][1]);
                    dp[i] = std::min(dp[i], cur + (j > 0 ? dp[j - 1] : 0));
                }
                else
                {
                    break;
                }
            }
        }
        
        return dp.back();
    }
};