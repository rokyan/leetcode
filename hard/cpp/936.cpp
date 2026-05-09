// https://leetcode.com/problems/stamping-the-sequence/description/

class Solution
{
public:
    std::vector<int> movesToStamp(const std::string& stamp, std::string target)
    {
        std::vector<int> res;

        for (int attempts = 0; attempts < 10 * target.size(); attempts++)
        {
            bool matched = false;

            for (int i = 0; i < target.size() && !matched; i++)
            {
                if (canMatch(stamp, target, i))
                {
                    for (int j = 0; j < stamp.size(); j++)
                    {
                        target[i + j] = '*';
                    }

                    matched = true;
                    res.push_back(i);
                }
            }

            if (!matched)
            {
                return {};
            }

            bool found = true;

            for (int i = 0; i < target.size(); i++)
            {
                if (target[i] != '*')
                {
                    found = false;
                    break;
                }
            }

            if (found)
            {
                std::ranges::reverse(res);
                return res;
            }
        }

        return {};
    }

private:
    static bool canMatch(const std::string& stamp, const std::string& target, int start)
    {
        const int n = stamp.size();

        if (start + n > target.size())
        {
            return false;
        }

        bool foundGood = false;

        for (int i = 0; i < n; i++)
        {
            if (target[start + i] == '*')
            {
                continue;
            }

            if (stamp[i] == target[start + i])
            {
                foundGood = true;
                continue;
            }

            return false;
        }

        return foundGood;
    }
};