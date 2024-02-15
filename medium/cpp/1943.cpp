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
        auto s = 0LL;
        auto acc = 0LL;

        std::vector<std::vector<long long>> res;

        for (const auto& entry : m)
        {
            acc += entry.second;

            if (s > 0)
            {
                std::vector<long long> cur;
                cur.push_back(last);
                cur.push_back(entry.first);
                cur.push_back(s);
                res.push_back(std::move(cur));
            }

            s = acc;
            last = entry.first;
        }

        return res;
    }
};