// https://leetcode.com/problems/maximum-number-of-equal-length-runs/description/

class Solution
{
public:
    int maxSameLengthRuns(const std::string& s)
    {
        const int n = size(s);

        std::unordered_map<int, int> cnt;
        int len = 1;
        int res = 0;

        for (int i = 1; i < n; i++)
        {
            if (s[i] == s[i - 1])
            {
                len++;
            }
            else
            {
                res = std::max(res, ++cnt[len]);
                len = 1;
            }
        }

        res = std::max(res, ++cnt[len]);
        return res;
    }
};