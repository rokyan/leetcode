// https://leetcode.com/problems/zigzag-conversion/

class Solution
{
public:
    std::string convert(std::string s, int numRows)
    {
        if (numRows == 1)
        {
            return s;
        }
        
        std::size_t len = std::size(s);
        
        std::vector<std::vector<char>> table(numRows);
        
        for (auto& row : table)
        {
            row.resize(len);
        }
        
        int i = 0;
        int j = 0;
        
        int dir = 0;
        
        for (std::size_t pos = 0; pos < len; pos++)
        {
            table[i][j] = s[pos];
            
            if (dir == 0)
            {               
                if (i == numRows - 1)
                {
                    i--;
                    j++;
                    
                    if (numRows > 2)
                    {
                        dir = 1;
                    }
                }
                else
                {
                    i++;
                }
            }
            else
            {               
                if (i == 0)
                {
                    dir = 0;
                    i++;
                }
                else
                {
                    i--;
                    j++;
                }
            }
        }
        
        std::string answer;
        answer.resize(len);
        
        int pos = 0;
        
        for (std::size_t i = 0; i < numRows; i++)
        {
            for (std::size_t j = 0; j < len; j++)
            {
                if (table[i][j] != 0)
                {
                    answer[pos++] = table[i][j];
                }
            }
        }
        
        return answer;
    }
};