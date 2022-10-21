// https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/

class Solution
{
public:
    int maxVowels(std::string s, int k)
    {
        const std::vector<char> vowels { 'a', 'e', 'i', 'o', 'u' };
        
        const auto vowels_count = std::size(vowels);
        
        auto counter = 0;
        
        for (std::size_t pos = 0; pos < k; pos++)
        {
            for (std::size_t v_pos = 0; v_pos < vowels_count; v_pos++)
            {
                if (vowels[v_pos] == s[pos])
                {
                    counter++;
                    break;
                }
            }
        }
        
        auto answer = counter;
        
        for (std::size_t pos = k; pos < std::size(s); pos++)
        {
            for (std::size_t v_pos = 0; v_pos < vowels_count; v_pos++)
            {
                if (vowels[v_pos] == s[pos])
                {
                    counter++;
                    break;
                }
            }
            
            for (std::size_t v_pos = 0; v_pos < vowels_count; v_pos++)
            {
                if (vowels[v_pos] == s[pos - k])
                {
                    counter--;
                    break;
                }
            }
            
            answer = std::max(answer, counter);
        }
        
        return answer;
    }
};