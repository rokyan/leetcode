// https://leetcode.com/problems/search-suggestions-system/

class Solution
{       
public:
    std::vector<std::vector<std::string>> suggestedProducts(std::vector<std::string>& products, std::string searchWord)
    {     
        std::sort(std::begin(products), std::end(products));
        
        std::string prefix;
        
        std::vector<std::vector<std::string>> res;
        res.reserve(std::size(searchWord));
        
        for (std::size_t pos = 0; pos < std::size(searchWord); pos++)
        {
            prefix.push_back(searchWord[pos]);
            
            auto prefix_pos = std::lower_bound(std::begin(products), std::end(products), prefix);
            
            std::vector<std::string> suggs;
            suggs.reserve(3);
            
            for (int att = 0; att < 3; att++)
            {
                if (prefix_pos == std::end(products) || (*prefix_pos).substr(0, pos + 1) != prefix)
                {
                    break;
                }
                
                suggs.push_back(*prefix_pos);
                prefix_pos++;
            }
            
            res.push_back(suggs);
        }
        
        return res;
    }
};