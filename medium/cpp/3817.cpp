// https://leetcode.com/problems/good-indices-in-a-digit-string/description/

class Solution
{
public:
    std::vector<int> goodIndices(const std::string& s)
    {
        const int n = s.size();

        std::vector<int> res;
        res.reserve(n);

        for (int i = 0; i < n; i++)
        {
            int num = s[i] - '0';

            for (int j = i - 1, p = 10; j >= 0 && num < i && p < 1000'000; j--, p *= 10)
            {
                num += p * (s[j] - '0');
            }

            if (num == i)
            {
                res.push_back(i);
            }
        }

        return res;
    }
};