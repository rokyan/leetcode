// https://leetcode.com/problems/minimum-consecutive-cards-to-pick-up/

class Solution
{
public:
    int minimumCardPickup(std::vector<int>& cards)
    {
        const auto n = std::size(cards);
        
        std::unordered_map<int, int> last_pos;
        
        int ans = -1;
        
        for (int pos = 0; pos < n; pos++)
        {
            const auto it = last_pos.find(cards[pos]);
            
            if (it != std::end(last_pos))
            {
                ans = (ans == -1) ? pos - it->second + 1 : std::min(ans, pos - it->second + 1);
                it->second = pos;
            }
            else
            {
                last_pos.emplace(cards[pos], pos);
            }
        }
        
        return ans;
    }
};