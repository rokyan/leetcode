// https://leetcode.com/problems/partition-labels/

class Solution
{
public:
    std::vector<int> partitionLabels(std::string s)
    {
        int last_pos[26] = { -1 };
        
        for (int pos = 0; pos < std::size(s); pos++)
        {
            last_pos[s[pos] - 'a'] = pos;
        }      
        
        std::vector<int> result;
        
        int prev = -1;
        
        for (int pos = 0; pos < std::size(s); pos++)
        {
            int last = last_pos[s[pos] - 'a'];
            
            while (pos < last)
            {
                pos++;
                last = std::max(last, last_pos[s[pos] - 'a']);
            }
            
            result.push_back(pos - prev);
            
            prev = pos;
        }
        
        return result;
    }
};