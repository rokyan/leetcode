// https://leetcode.com/problems/find-the-sequence-of-strings-appeared-on-the-screen/description/

class Solution
{
public:
    std::vector<std::string> stringSequence(const std::string& target)
    {
        std::string cur;
        std::vector<std::string> res;

        for (auto c : target)
        {
            cur.push_back('a');
            res.push_back(cur);

            while (cur.back() < c)
            {
                cur.back()++;
                res.push_back(cur);
            }
        }

        return res;
    }
};