// https://leetcode.com/problems/distant-barcodes/

class Solution
{
public:
    std::vector<int> rearrangeBarcodes(std::vector<int>& barcodes)
    {
        const auto n = std::size(barcodes);
        
        std::unordered_map<int, int> counter;
        
        for (auto barcode : barcodes)
        {
            counter[barcode]++;
        }
        
        std::vector<std::pair<int, int>> freq;
        freq.reserve(n);
        
        for (const auto& entry : counter)
        {
            freq.emplace_back(entry.second, entry.first);
        }
        
        std::sort(std::begin(freq), std::end(freq), std::greater<>{});
        
        std::vector<int> placement(n);
        
        std::size_t i = 0;
        std::size_t pos = 0;
        
        while (i < std::size(freq))
        {
            placement[pos] = freq[i].second;
            
            pos += 2;
            
            if (pos >= n)
            {
                pos = 1;
            }
            
            freq[i].first--;
            
            if (freq[i].first == 0)
            {
                i++;
            }
        }
        
        return placement;
    }
};