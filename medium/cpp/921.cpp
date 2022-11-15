class Solution
{
public:
    int minAddToMakeValid(std::string s)
    {
        auto answer = 0;
        auto balance = 0;
        
        for (auto c : s)
        {
            if (c == '(')
            {
                balance++;
            }
            
            if (c == ')')
            {
                if (balance > 0)
                {
                    balance--; 
                }
                else
                {
                    answer++;
                }
            }
        }
        
        answer += balance;
        
        return answer;
    }
};