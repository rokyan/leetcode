// https://leetcode.com/problems/vowels-of-all-substrings/

class Solution
{
private:
    using ll = long long;
    
public:
    ll countVowels(std::string word)
    {
        std::vector<char> vowels { 'a', 'e', 'i', 'o', 'u' };
        
        ll answer = 0;
        const int len = std::size(word);
        
        for (char c : vowels)
        {
            for (int pos = 0; pos < len; pos++)
            {
                if (word[pos] == c)
                {
                    answer += 1LL * (pos + 1) * (len - pos);
                }
            }
        }
        
        return answer;
    }
};