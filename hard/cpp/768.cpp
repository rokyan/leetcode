// https://leetcode.com/problems/max-chunks-to-make-sorted-ii/

class Solution
{
public:
    int maxChunksToSorted(std::vector<int>& arr)
    {
        std::map<int, int> mapper;
        
        for (const auto num : arr)
        {
            mapper[num]++;
        }
        
        auto acc = 0;
        
        for (auto& entry : mapper)
        {
            const auto cnt = entry.second;
            entry.second = acc;
            acc += cnt;
        }
        
        auto max_num = 0;
        auto ans = 0;
        
        for (std::size_t pos = 0; pos < std::size(arr); pos++)
        {
            auto& num = mapper[arr[pos]];
            max_num = std::max(max_num, num);
            
            if (max_num == pos)
            {
                ans++;
            }
            
            num++;
        }

        return ans;
    }
};