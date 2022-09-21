// https://leetcode.com/problems/most-beautiful-item-for-each-query/

class Solution
{
public:
    std::vector<int> maximumBeauty(std::vector<std::vector<int>>& items, std::vector<int>& queries)
    {
        std::sort(std::begin(items), std::end(items));
                
        std::vector<int> ans;
        ans.reserve(std::size(queries));
        
        std::vector<int> max_on_pref(std::size(items));
        max_on_pref[0] = items[0][1];
        
        for (std::size_t i = 1; i < std::size(max_on_pref); i++)
        {
            max_on_pref[i] = std::max(max_on_pref[i - 1], items[i][1]);
        }
        
        for (const auto query : queries)
        {
            auto it = std::upper_bound(std::begin(items), std::end(items), query, [](auto value, const auto& item) {
                return value < item[0];
            });
            
            const auto n = std::distance(std::begin(items), it);
            
            ans.push_back(n == 0 ? 0 : max_on_pref[n - 1]);
        }
        
        return ans;
    }
};