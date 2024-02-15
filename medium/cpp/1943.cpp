// https://leetcode.com/problems/describe-the-painting/description/

class Solution
{
public:
    std::vector<std::vector<long long>> splitPainting(std::vector<std::vector<int>>& segments)
    {
        std::map<long long, long long> m;

        for (const auto& segment : segments)
        {
            m[segment[0]] += segment[2];
            m[segment[1]] -= segment[2];
        }

        auto last = -1;
        auto acc = 0LL;

        std::vector<std::vector<long long>> res;

        for (const auto& entry : m)
        {
            if (acc > 0)
            {
                std::vector<long long> cur{ last, entry.first, acc };
                res.push_back(std::move(cur));
            }

            acc += entry.second;
            last = entry.first;
        }

        return res;
    }
};