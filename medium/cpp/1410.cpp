// https://leetcode.com/problems/html-entity-parser/

class Solution
{
public:
    string entityParser(string text)
    {        
        std::map<std::string, char> mapping
        {
            { "quot", '"' },
            { "apos", '\'' },
            { "amp", '&' },
            { "gt", '>' },
            {"lt", '<' },
            {"frasl", '/' }
        };
        
        std::string res;
        res.reserve(std::size(text));
        
        for (std::size_t pos = 0; pos < std::size(text); pos++)
        {
            bool match = false;
            
            if (text[pos] == '&')
            {
                for (const auto& [s, c]: mapping)
                {
                    if (pos + 1 + std::size(s) < std::size(text) && text[pos + 1 + std::size(s)] == ';')
                    {
                        match = true;
                        
                        for (std::size_t i = 0; i < std::size(s); i++)
                        {
                            if (s[i] != text[pos + 1 + i])
                            {
                                match = false;
                                break;
                            }
                        }
                        
                        if (match)
                        {
                            pos += std::size(s) + 1;
                            res.push_back(c);
                            break;
                        }    
                    }  
                }
            }
            
            if (!match)
            {
                res.push_back(text[pos]);
            }
        }
        
        return res;
    }
};