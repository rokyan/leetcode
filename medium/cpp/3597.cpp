// https://leetcode.com/problems/partition-string/description/

class Solution
{
public:
    const std::vector<std::string> partitionString(const std::string& s)
    {
        std::string acc;
        std::unordered_set<std::string> un;
        std::vector<std::string> res;

        for (auto i = 0; i < std::size(s); i++)
        {
            acc.push_back(s[i]);

            if (un.find(acc) == std::cend(un))
            {
                un.insert(acc);
                res.push_back(acc);
                acc.clear();
            }
        }

        return res;
    }
};