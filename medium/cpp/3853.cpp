// https://leetcode.com/problems/merge-close-characters/description/

class Solution
{
public:
    std::string mergeCharacters(const std::string& s, int k)
    {
        std::string res;
        res.reserve(s.size());
        std::array<int, 26> lastPos;
        lastPos.fill(-1);

        for (char c : s)
        {
            if (lastPos[c - 'a'] == -1 || res.size() - lastPos[c - 'a'] > k)
            {
                lastPos[c - 'a'] = res.size();
                res.push_back(c);
            }
        }

        return res;
    }
};