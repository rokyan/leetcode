// https://leetcode.com/problems/find-duplicate-file-in-system/

class Solution
{
public:
    std::vector<std::vector<std::string>> findDuplicate(std::vector<std::string>& paths)
    {   
        std::unordered_map<std::string, std::vector<std::string>> gbc;
        
        for (const auto& path : paths)
        {
            auto parsed = parse(path);
            
            for (const auto& e : parsed)
            {
                gbc[e.second].push_back(e.first);
            }
        }
        
        std::vector<std::vector<std::string>> res;
        
        for (const auto& e : gbc)
        {
            if (std::size(e.second) > 1)
            {
                res.push_back(e.second);
            }
        }
        
        return res;
    }
    
private:
    std::vector<std::pair<std::string, std::string>> parse(const std::string& files)
    {
        auto d_pos = files.find(' ');
        
        const std::string dir = files.substr(0, d_pos);
        
        auto pos = d_pos;
        
        std::vector<std::pair<std::string, std::string>> parsed;
        
        while (++pos < std::size(files))
        {
            d_pos = files.find('(', pos);
            
            const std::string filename = files.substr(pos, d_pos - pos);
            
            pos = d_pos + 1;
            
            d_pos = files.find(')', pos);
            
            const std::string content = files.substr(pos, d_pos - pos);
            
            pos = d_pos + 1;
            
            parsed.emplace_back(dir + "/" + filename, content);
        }
        
        return parsed;
    }
};