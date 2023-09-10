// https://leetcode.com/problems/largest-merge-of-two-strings/description/

class Solution
{
public:
    std::string largestMerge(std::string word1, std::string word2)
    {
        std::string_view v1{ word1 };
        std::string_view v2{ word2 };

        std::string res;
        res.reserve(std::size(word1) + std::size(word2));

        auto p1 = 0;
        auto p2 = 0;

        while (p1 < std::size(v1) && p2 < std::size(v2))
        {
            if (v1[p1] > v2[p2])
            {
                res.push_back(v1[p1++]);
            }
            else if (v1[p1] < v2[p2])
            {
                res.push_back(v2[p2++]);
            }
            else
            {
                if (v1.substr(p1) >= v2.substr(p2))
                {
                    res.push_back(v1[p1++]);
                }
                else
                {
                    res.push_back(v2[p2++]);
                }
            }
        }

        while (p1 < std::size(v1))
        {
            res.push_back(v1[p1++]);
        }

        while (p2 < std::size(v2))
        {
            res.push_back(v2[p2++]);
        }

        return res;
    }
};