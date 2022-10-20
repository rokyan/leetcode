// https://leetcode.com/problems/minimum-number-of-steps-to-make-two-strings-anagram-ii/

class Solution
{
public:
    int minSteps(std::string s, std::string t)
    {
        std::vector<int> sc(26);
        
        for (auto c : s) sc[c - 'a']++;
        
        std::vector<int> st(26);
        
        for (auto c : t) st[c - 'a']++;
        
        int answer = 0;
        
        for (int i = 0; i < 26; i++)
        {
            answer += std::abs(sc[i] - st[i]);
        }
        
        return answer;
    }
};