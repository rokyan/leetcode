// https://leetcode.com/problems/find-original-array-from-doubled-array/description/

class Solution
{
public:
    std::vector<int> findOriginalArray(std::vector<int>& changed)
    {
        const int n = std::size(changed);

        std::ranges::sort(changed);

        std::vector<char> used(n);

        std::vector<int> res;
        res.reserve(n / 2);

        auto start = 0;

        while (start < n && changed[start] == 0)
        {
            start++;
        }

        if (start % 2)
        {
            return {};
        }
        else
        {
            for (auto i = 0; i < start / 2; i++)
            {
                res.push_back(0);
            }
        }

        for (auto i = n - 1, p = n - 1; i >= start; i--)
        {
            if (!used[i])
            {
                while (p >= 0)
                {
                    if (!used[p] && changed[p] * 2 == changed[i])
                    {
                        break;
                    }
                    p--;
                }

                if (p < 0)
                {
                    return {};
                }

                used[p] = true;
                res.push_back(changed[p]);
            }
        }

        return res;
    }
};