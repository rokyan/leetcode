// https://leetcode.com/problems/subdomain-visit-count/

class Solution
{
public:
    std::vector<std::string> subdomainVisits(std::vector<std::string>& cpdomains)
    {
        std::unordered_map<std::string, int> counts;
        
        for (const std::string& cpdomain : cpdomains)
        {
            const auto space_pos = cpdomain.find(' ');
            
            int count = std::stoi(cpdomain.substr(0, space_pos));
            std::string domain = cpdomain.substr(space_pos + 1);
            
            counts[domain] += count;
            
            auto dot_pos = domain.find('.');
            
            while (dot_pos != std::string::npos)
            {
                domain = domain.substr(dot_pos + 1);
                counts[domain] += count;
                dot_pos = domain.find('.');
            }
        }
        
        std::vector<std::string> results;
        results.reserve(std::size(counts));
        
        for (const auto& count : counts)
        {
            results.push_back(std::to_string(count.second) + " " + count.first);
        }
        
        return results;
    }
};