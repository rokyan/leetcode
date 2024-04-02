// https://leetcode.com/problems/separate-black-and-white-balls/description/

class Solution
{
public:
    long long minimumSteps(std::string s)
    {
        auto res = 0LL;

        for (auto i = 0, cnt = 0; i < std::size(s); i++)
        {
            if (s[i] == '0')
            {
                res += cnt;
            }
            else
            {
                cnt++;
            }
        }

        return res;
    }
};