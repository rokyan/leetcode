// https://leetcode.com/problems/remove-sub-folders-from-the-filesystem/

class Solution
{
public:
    std::vector<std::string> removeSubfolders(std::vector<std::string>& folder)
    {
        const auto n = std::size(folder);
        
        std::vector<std::pair<std::vector<std::string>, std::size_t>> folders(n);
        
        for (std::size_t pos = 0; pos < n; pos++)
        {
            folders[pos] = { parse(folder[pos]), pos };
        }
        
        std::sort(std::begin(folders), std::end(folders));
        
        std::vector<std::string> ans;
        
        for (std::size_t pos = 0; pos < n; )
        {
            ans.push_back(folder[folders[pos].second]);
            
            std::size_t next_pos = pos + 1;
            
            while (next_pos < n && is_pref(folders[pos].first, folders[next_pos].first))
            {
                next_pos++;
            }
            
            pos = next_pos;
        }
        
        return ans;
    }
    
private:
    std::vector<std::string> parse(const std::string& path)
    {
        const auto n = std::size(path);
        
        std::string folder;
        std::vector<std::string> folders;
        
        for (std::size_t pos = 0; pos < n; pos++)
        {
            if (path[pos] == '/')
            {
                folders.push_back(folder);
                folder.clear();
            }
            else
            {
                folder.push_back(path[pos]);
            }
        }
        
        folders.push_back(folder);
        
        return folders;
    }
    
    bool is_pref(const std::vector<std::string>& folders1, const std::vector<std::string>& folders2)
    {
        if (std::size(folders1) >= std::size(folders2))
        {
            return false;
        }
        
        const auto n = std::size(folders1);
        
        for (std::size_t pos = 0; pos < n; pos++)
        {
            if (folders1[pos] != folders2[pos])
            {
                return false;
            }
        }
        
        return true;
    }
};