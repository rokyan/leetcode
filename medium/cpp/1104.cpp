// https://leetcode.com/problems/path-in-zigzag-labelled-binary-tree/

class Solution
{
public:
    std::vector<int> pathInZigZagTree(int label)
    {
        int level = 0;
        
        while ((1 << level) - 1 < label)
        {
            level++;
        }
        
        std::vector<int> path;
        path.reserve(level);
        
        level--;
        
        while (level)
        {
            path.push_back(label);
            
            int pos = label - (1 << level);
            
            if (level & 1)
            {
                pos = (1 << level) - pos - 1;
            }
            
            pos /= 2;
            
            level--;
            
            if (level % 2 == 0)
            {
                label = pos + (1 << level);
            }
            else
            {
                label = (1 << level) + (1 << level) - pos - 1;
            }
        }
        
        path.push_back(label);
        
        std::reverse(std::begin(path), std::end(path));
        
        return path;
    }
};