// https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/

class Solution
{
public:
    int maxScore(vector<int>& cardPoints, int k)
    {
        const auto n = std::size(cardPoints);
        
        const auto sum = std::accumulate(std::begin(cardPoints), std::end(cardPoints), 0);
        
        if (k == n)
        {
            return sum;
        }
        
        auto len = n - k;
        auto cur = std::accumulate(std::begin(cardPoints), std::begin(cardPoints) + len - 1, 0);
        
        auto ans = -1;
        
        for (std::size_t i = 0; i + len - 1 < n; i++)
        {
            cur += cardPoints[i + len - 1];
            
            ans = std::max(ans, sum - cur);
            
            cur -= cardPoints[i];
        }
        
        return ans;
    }
};