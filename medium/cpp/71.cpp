// https://leetcode.com/problems/simplify-path/

class Solution
{
public:
    std::string simplifyPath(std::string path)
    {
        std::vector<std::string> dirs;
        
        std::string current;
        
        for (std::size_t pos = 0; pos < std::size(path); pos++)
        {
            if (path[pos] == '/')
            {
                if (!current.empty())
                {
                    add(dirs, current);
                    current.clear();
                }
            }
            else
            {
                current += path[pos];
            }
        }
        
        if (!current.empty())
        {
            add(dirs, current);
        }
        
        std::string can_path;
        
        for (const auto& dir : dirs)
        {
            can_path += "/" + dir;
        }
        
        return can_path.empty() ? "/" : can_path;
    }
    
private:
    void add(std::vector<std::string>& dirs, const std::string& dir)
    {
        if (dir == ".")
        {
        }      
        else if (dir == "..")
        {
            if (dirs.size() > 0)
            {
                dirs.pop_back();
            }
        }
        else
        {
            dirs.push_back(dir);
        }
    }
};