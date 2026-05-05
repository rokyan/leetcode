// https://leetcode.com/problems/minimum-number-of-moves-to-make-palindrome/description/

class Solution
{
public:
    int minMovesToMakePalindrome(std::string& s)
    {
        const int n = s.size();
        int moves = 0;
        
        for (int left = 0, right = n - 1; left < right; ++left)
        {
            int pos = right;
            
            while (pos > left && s[pos] != s[left])
            {
                pos--;
            }
            
            if (pos == left)
            {
                moves += (n / 2 - left);
                continue;
            }
            
            while (pos < right)
            {
                std::swap(s[pos], s[pos + 1]);
                pos++;
                moves++;
            }
            
            right--;
        }
        
        return moves;
    }
};