// https://leetcode.com/problems/maximum-nesting-depth-of-two-valid-parentheses-strings/

class Solution
{
public:
    std::vector<int> maxDepthAfterSplit(std::string seq)
    {
        std::vector<int> mark(std::size(seq));
        
        int counter = 0;
        int depth = 0;
        
        for (std::size_t i = 0; i < std::size(seq); i++)
        {
            if (seq[i] == '(')
            {
                mark[i] = ++counter;
                
                if (counter > depth)
                {
                    depth = counter;
                }
            }
            else
            {
                mark[i] = counter--;
            }
        }
        
        for (std::size_t i = 0; i < std::size(seq); i++)
        {
            if (mark[i] <= depth / 2)
            {
                mark[i] = 0;
            }
            else
            {
                mark[i] = 1;
            }
        }
        
        return mark;
    }
};