// https://leetcode.com/problems/count-and-say/description/

class Solution
{
public:
    string countAndSay(int n)
    {
        std::string seq { "1" };
        
        for (auto i = 2; i <= n; ++i)
        {
            std::string next;
            auto counter = 1;
            
            for (auto pos = 1; pos < std::size(seq); ++pos)
            {
                if (seq[pos] != seq[pos - 1])
                {
                    next += std::to_string(counter);
                    next.push_back(seq[pos - 1]);
                    counter = 1;
                }
                else
                {
                    counter++;
                }
            }
            
            next += std::to_string(counter);
            next.push_back(seq.back());
            
            seq.swap(next);
        }
        
        return seq;
    }
};