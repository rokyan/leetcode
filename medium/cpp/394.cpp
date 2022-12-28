// https://leetcode.com/problems/decode-string/description/

class Solution
{
public:
    std::string decodeString(std::string s)
    {
        std::string decoded;
        
        for (auto pos = 0; pos < s.size();)
        {
            if (std::isdigit(s[pos]))
            {
                auto mult = s[pos++] - '0';
                
                while (std::isdigit(s[pos]))
                {
                    mult = 10 * mult + s[pos++] - '0';
                }

                auto balance = 0;
                std::string substr;
                
                do
                {
                    if (s[pos] == '[')
                    {
                        ++balance;
                    }
                    else if (s[pos] == ']')
                    {
                        --balance;
                    }
                    
                    substr.push_back(s[pos++]);
                }
                while (balance != 0);
                
                substr = decodeString(substr.substr(1, substr.size() - 2));
                
                for (auto counter = 0; counter < mult; ++counter)
                {
                    decoded += substr;
                }
            }
            else
            {
                decoded.push_back(s[pos++]);
            }
        }
        
        return decoded;
    }
};