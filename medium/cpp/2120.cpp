// https://leetcode.com/problems/execution-of-all-suffix-instructions-staying-in-a-grid/

class Solution
{
public:
    std::vector<int> executeInstructions(int n, std::vector<int>& startPos, std::string s)
    {
        std::vector<int> answer(std::size(s));
        
        for (std::size_t i = 0; i < std::size(s); i++)
        {
            int x = startPos[1];
            int y = startPos[0];
            
            int count = 0;
            
            for (std::size_t j = i; j < std::size(s); j++)
            {
                if (s[j] == 'L')
                {
                    x--;
                }
                
                if (s[j] == 'R')
                {
                    x++;
                }
                
                if (s[j] == 'U')
                {
                    y--;
                }
                
                if (s[j] == 'D')
                {
                    y++;
                }

                if (x < 0 || x == n || y < 0 || y == n)
                {
                    break;
                }
                
                count++;
            }
            
            answer[i] = count;
        }
        
        return answer;
    }
};