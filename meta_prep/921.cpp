class Solution
{
public:
    int minAddToMakeValid(const std::string& s)
    {
        auto balance = 0;
        auto cnt = 0;

        for (auto c : s)
        {
            if (c == '(')
            {
                balance++;
            }
            else
            {
                if (balance > 0)
                {
                    balance--;
                }
                else
                {
                    cnt++;
                }
            }
        }

        cnt += balance;
        return cnt;
    }
};