// https://leetcode.com/problems/check-if-a-string-can-break-another-string/

class Solution
{
public:
    bool checkIfCanBreak(string s1, string s2)
    {
        const auto n = std::size(s1);
        
        std::vector<int> cnt1(26);
        std::vector<int> cnt2(26);
        
        for (auto c : s1)
        {
            cnt1[c - 'a']++;
        }
        
        for (auto c : s2)
        {
            cnt2[c - 'a']++;
        }
               
        bool first = false;
        bool second = false;
        
        auto p1 = 0;
        auto p2 = 0;
        
        while (p1 < 26 && p2 < 26)
        {  
            int mv = std::min(cnt1[p1], cnt2[p2]);
            
            cnt1[p1] -= mv;
            cnt2[p2] -= mv;
            
            if (cnt1[p1] == 0)
            {
                p1++;
            }
            
            if (cnt2[p2] == 0)
            {
                p2++;
            }
            
            if (p1 > p2)
            {
                first = true;
            }
            
            if (p2 > p1)
            {
                second = true;
            }
            
            if (first && second)
            {
                return false;
            }
        }
        
        return true;
    }
};