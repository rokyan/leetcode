// https://leetcode.com/problems/groups-of-special-equivalent-strings/

class Solution
{
public:
    int numSpecialEquivGroups(std::vector<std::string>& words)
    {
        for (auto& word : words)
        {
            string even;
            string odd;
            
            for (std::size_t pos = 0; pos < std::size(word); pos++)
            {
                if (pos % 2 == 0)
                {
                    even += word[pos];
                }
                else
                {
                    odd += word[pos];
                }
            }
            
            std::sort(std::begin(even), std::end(even));
            std::sort(std::begin(odd), std::end(odd));
                        
            for (std::size_t pos = 0; pos < std::size(word); pos++)
            {
                if (pos % 2 == 0)
                {
                    word[pos] = even[pos / 2];
                }
                else
                {
                    word[pos] = odd[pos / 2];
                }
            }
        }
        
        std::sort(std::begin(words), std::end(words));
        
        int count = 1;
        
        for (std::size_t pos = 1; pos < std::size(words); pos++)
        {
            if (words[pos] != words[pos - 1])
            {
                count++;
            }
        }
        
        return count;
    }
};