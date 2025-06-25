// https://leetcode.com/problems/maximum-score-words-formed-by-letters/description/

class Solution
{
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score)
    {
        const int n = std::size(words);
        
        std::vector<int> counts(26);
        
        for (auto c : letters)
        {
            counts[c - 'a']++;
        }
        
        std::vector<int> cur_counts(26);
        
        int ans = 0;
        
        for (int mask = 1; mask < (1 << n); mask++)
        {
            std::fill(std::begin(cur_counts), std::end(cur_counts), 0);
            
            auto fits = true;
            auto cur_score = 0;
            
            for (int i = 0; i < n; i++)
            {
                if ((1 << i) & mask)
                {                    
                    for (auto c : words[i])
                    {
                        cur_counts[c - 'a']++;
                        
                        if (cur_counts[c - 'a'] > counts[c - 'a'])
                        {
                            fits = false;
                            break;
                        }
                        
                        cur_score += score[c - 'a'];
                    }
                }
            }
            
            if (fits)
            {
                ans = std::max(ans, cur_score);
            }
        }
        
        return ans;
    }
};