// https://leetcode.com/problems/restore-ip-addresses/description/

class Solution
{
public:
    std::vector<std::string> restoreIpAddresses(std::string s)
    {
        std::vector<std::string> addrs;
        
        for (std::size_t pos_0 = 1; pos_0 < std::size(s); pos_0++)
        {
            for (std::size_t pos_1 = pos_0 + 1; pos_1 < std::size(s); pos_1++)
            {
                for (std::size_t pos_2 = pos_1 + 1; pos_2 < std::size(s); pos_2++)
                {
                    if (is_valid(s, 0, pos_0) && is_valid(s, pos_0, pos_1) &&
                        is_valid(s, pos_1, pos_2) && is_valid(s, pos_2, std::size(s)))
                    {
                        addrs.push_back(s.substr(0, pos_0) + "." +
                                       s.substr(pos_0, pos_1 - pos_0) + "." +
                                       s.substr(pos_1, pos_2 - pos_1) + "." +
                                       s.substr(pos_2, std::size(s) - pos_2));
                    }
                }
            }
        }
        
        return addrs;
    }
    
private:
    bool is_valid(const std::string& s, std::size_t first, std::size_t last)
    {
        if (s[first] == '0' && first + 1 < last)
        {
            return false;
        }
        
        int acc = 0;
        
        while (first < last)
        {
            acc = 10 * acc + s[first++] - '0';
            
            if (acc > 255)
            {
                return false;
            }
        }
        
        return true;
    }
};