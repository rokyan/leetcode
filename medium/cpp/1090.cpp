// https://leetcode.com/problems/largest-values-from-labels/

class Solution
{
public:
    int largestValsFromLabels(std::vector<int>& values, std::vector<int>& labels, int numWanted, int useLimit)
    {
        const auto n = std::size(values);
        
        std::vector<std::pair<int, int>> combined(n);
        
        for (std::size_t i = 0; i < n; i++)
        {
            combined[i] = { values[i], labels[i] };
        }
        
        std::sort(std::begin(combined), std::end(combined), std::greater<>());
        
        std::unordered_map<int, int> label_count;
        
        int taken = 0;
        int ans = 0;
        
        for (std::size_t i = 0; i < n && taken < numWanted; i++)
        {
            const int value = combined[i].first;
            const int label = combined[i].second;
            
            auto it = label_count.find(label);
            
            if (it == std::end(label_count))
            {
                taken++;
                ans += value;
                label_count.emplace(label, 1);
            }
            else
            {
                it->second++;
                
                if (it->second <= useLimit)
                {
                    taken++;
                    ans += value;
                }
            }
        }
        
        return ans;
    }
};