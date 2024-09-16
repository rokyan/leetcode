// https://leetcode.com/problems/find-the-number-of-distinct-colors-among-the-balls/description/

class Solution
{
public:
    std::vector<int> queryResults(int limit, const std::vector<std::vector<int>>& queries)
    {
        std::unordered_map<int, int> cnt;
        std::unordered_map<int, int> color;
        auto tot = 0;

        std::vector<int> res;
        res.reserve(std::size(queries));

        for (const auto& query : queries)
        {
            const auto x = query[0];
            const auto y = query[1];

            if (const auto it = color.find(x); it != std::end(color))
            {
                if (cnt[it->second]-- == 1)
                {
                    tot--;
                }

                it->second = y;
            }
            else
            {
                color.emplace(x, y);
            }

            if (cnt[y]++ == 0)
            {
                tot++;
            }

            res.push_back(tot);
        }

        return res;
    }
};