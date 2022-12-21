// https://leetcode.com/problems/longest-substring-without-repeating-characters/description/

class Solution
{
public:
    int lengthOfLongestSubstring(std::string s)
    {
        auto left = 0;
        auto right = 0;
        auto res = 0;
    
        std::unordered_set<char> checker;
    
        while (left < s.size())
        {
            while (right < s.size() && checker.count(s[right]) == 0)
            {
                checker.insert(s[right++]);
            }
    
            res = std::max(res, right - left);
    
            checker.erase(s[left++]);
        }
    
        return res;
    }
};