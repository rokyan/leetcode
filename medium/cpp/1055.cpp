// https://leetcode.com/problems/shortest-way-to-form-string/description/

class Solution
{
public:
    int shortestWay(std::string source, std::string target)
    {
        auto res = 0;

        for (auto p = 0; ; )
        {
            res++;

            auto prev = p;

            for (auto i = 0; i < std::size(source) && p < std::size(target); i++)
            {
                if (source[i] == target[p])
                {
                    p++;
                }
            }

            if (p == std::size(target))
            {
                break; 
            }

            if (p == prev)
            {
                res = -1;
                break;
            }
        }

        return res;
    }
};