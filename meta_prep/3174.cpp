class Solution
{
public:
    std::string clearDigits(const std::string& s)
    {
        std::string res;

        for (auto c : s)
        {
            if (std::isdigit(c))
            {
                if (!res.empty() && std::isalpha(res.back()))
                {
                    res.pop_back();
                }
                else
                {
                    res.push_back(c);
                }
            }
            else
            {
                res.push_back(c);
            }
        }

        return res;
    }
};