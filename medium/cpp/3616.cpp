// https://leetcode.com/problems/number-of-student-replacements/description/

class Solution
{
public:
    int totalReplacements(const std::vector<int>& ranks)
    {
        auto res = 0;
        auto rank = ranks[0];

        for (auto i = 1; i < std::size(ranks); i++)
        {
            if (ranks[i] < rank)
            {
                rank = ranks[i];
                res++;
            }
        }

        return res;
    }
};