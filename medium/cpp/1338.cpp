// https://leetcode.com/problems/reduce-array-size-to-the-half/

class Solution
{
public:
    int minSetSize(std::vector<int>& arr)
    {
        std::unordered_map<int, int> counts;
        
        for (auto num : arr)
        {
            counts[num]++;
        }
        
        std::vector<int> sorted_counts;
        sorted_counts.reserve(std::size(counts));
        
        for (auto entry : counts)
        {
            sorted_counts.push_back(entry.second);
        }
        
        std::sort(std::begin(sorted_counts), std::end(sorted_counts), std::greater<>{});
        
        int rem = std::size(arr) / 2;
        int res = 0;
        
        for (auto count : sorted_counts)
        {
            rem -= count;
            res++;
            
            if (rem <= 0)
            {
                break;
            }
        }
        
        return res;
    }
};