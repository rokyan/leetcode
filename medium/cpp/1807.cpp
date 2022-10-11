// https://leetcode.com/problems/evaluate-the-bracket-pairs-of-a-string/

class Solution
{
public:
    std::string evaluate(std::string s, std::vector<std::vector<std::string>>& knowledge)
    {
        std::sort(std::begin(knowledge), std::end(knowledge));
        
        const auto n = std::size(s);
        
        std::string res;
        res.reserve(n);
        
        std::string to_replace;
        bool within_brackets = false;
        
        for (std::size_t pos = 0; pos < n; pos++)
        {
            if (s[pos] == '(')
            {
                within_brackets = true;
            }
            else if (s[pos] == ')')
            {
                within_brackets = false;
                
                const auto it = std::lower_bound(std::begin(knowledge), std::end(knowledge), to_replace,
                    [] (const auto& value, const std::string& to_replace) {
                        return value[0] < to_replace;
                    });
                
                if (it != std::cend(knowledge) && (*it)[0] == to_replace)
                {
                    res += (*it)[1];
                }
                else
                {
                    res.push_back('?');
                }
                
                to_replace.clear();
            }
            else if (within_brackets)
            {
                to_replace.push_back(s[pos]);
            }
            else
            {
                res.push_back(s[pos]);
            }
        }
                                  
        return res;
    }
};