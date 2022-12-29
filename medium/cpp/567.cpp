// https://leetcode.com/problems/permutation-in-string/description/

class Solution
{
public:
    bool checkInclusion(std::string s1, std::string s2)
    {
        if (std::size(s1) > std::size(s2))
        {
            return false;
        }
        
        std::array<int, 26> cnt1 { 0 };
        std::array<int, 26> cnt2 { 0 };

        const auto n = static_cast<int>(std::size(s1));
        
        for (auto i = 0; i < n; ++i)
        {
            cnt1[s1[i] - 'a']++;
            cnt2[s2[i] - 'a']++;
        }

        if (cnt1 == cnt2)
        {
            return true;
        }
        
        for (auto i = n; i < std::size(s2); i++)
        {
            cnt2[s2[i] - 'a']++;
            cnt2[s2[i - n] - 'a']--;
            
            if (cnt1 == cnt2)
            {
                return true;
            }
        }

        return false;
    }
};