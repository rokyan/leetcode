// https://leetcode.com/problems/compare-version-numbers/

class Solution
{
public:
    int compareVersion(std::string version1, std::string version2)
    {
        auto parts1 = split(version1);
        auto parts2 = split(version2);
        
        while (std::size(parts1) < std::size(parts2))
        {
            parts1.push_back(0);
        }
        
        while (std::size(parts2) < std::size(parts1))
        {
            parts2.push_back(0);
        }

        if (parts1 < parts2)
        {
            return -1;
        }
        
        if (parts1 > parts2)
        {
            return 1;
        }
        
        return 0;
    }
    
private:
    std::vector<int> split(const std::string& version)
    {
        std::vector<int> parts;
        int current = 0;
        
        for (std::size_t pos = 0; pos < std::size(version); pos++)
        {
            if (version[pos] == '.')
            {
                parts.push_back(current);
                current = 0;
            }
            else
            {
                current *= 10;
                current += version[pos] - '0';
            }
        }
        
        parts.push_back(current);
        
        return parts;
    }
};