// https://leetcode.com/problems/remove-colored-pieces-if-both-neighbors-are-the-same-color/

class Solution
{
public:
    bool winnerOfGame(std::string colors)
    {
        int alice_cnt = 0;
        int bob_cnt = 0;
        
        int pos = 0;
        
        while (pos < std::size(colors))
        {
            int cnt = 0;
            
            while (pos < std::size(colors) && colors[pos] == 'A')
            {
                cnt++;
                pos++;
            }
            
            if (cnt >= 3)
            {
                alice_cnt += cnt - 2;
            }
            
            cnt = 0;
            
            while (pos < std::size(colors) && colors[pos] == 'B')
            {
                cnt++;
                pos++;
            }
            
            if (cnt >= 3)
            {
                bob_cnt += cnt - 2;
            }
        }
        
        return alice_cnt > bob_cnt;
    }
};