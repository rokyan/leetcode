// https://leetcode.com/problems/move-pieces-to-obtain-a-string/description/

class Solution
{
public:
    bool canChange(std::string start, std::string target)
    {
        auto sp = 0, tp = 0;

        for (; sp < std::size(start) && tp < std::size(target); sp++, tp++)
        {
            while (sp < std::size(start) && start[sp] == '_')
            {
                sp++;
            }

            while (tp < std::size(target) && target[tp] == '_')
            {
                tp++;
            }

            if (sp == std::size(start) && tp == std::size(target))
            {
                return true;
            }

            if (start[sp] != target[tp])
            {
                return false;
            }

            if (start[sp] == 'L')
            {
                if (sp < tp)
                {
                    return false;
                }
            }
            else
            {
                if (sp > tp)
                {
                    return false;
                }
            }
        }

        while (sp < std::size(start) && start[sp] == '_')
        {
            sp++;
        }

        while (tp < std::size(target) && target[tp] == '_')
        {
            tp++;
        }

        return sp == std::size(start) && tp == std::size(target);
    }
};