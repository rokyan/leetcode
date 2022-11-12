// https://leetcode.com/problems/find-the-winner-of-the-circular-game/

class Solution
{
public:
    int findTheWinner(int n, int k)
    {
        std::vector<int> used(n);
        
        int pos = 0;
        int left = n;
        
        while (left > 1)
        {          
            int kk = k;
            
            while (kk-- > 0)
            {
                while (used[pos])
                {
                    pos = (pos + 1) % n;
                } 
                
                if (kk > 0)
                {
                    pos = (pos + 1) % n;   
                }
            }
            
            used[pos] = true;
            
            left--;
        }
        
        pos = 0;
        
        while (used[pos])
        {
            pos = (pos + 1) % n;
        }
        
        return pos + 1;
    }
};