// https://leetcode.com/problems/count-zero-request-servers/description/

class Solution
{
public:
    std::vector<int> countServers(int n, std::vector<std::vector<int>>& logs, int x, std::vector<int>& queries)
    {
        std::sort(std::begin(logs), std::end(logs), [](const auto& lhs, const auto& rhs) {
            return lhs[1] < rhs[1];
        });

        const auto q = std::size(queries);

        std::vector<std::pair<int, int>> qwi(q);

        for (auto i = 0; i < q; i++)
        {
            qwi[i] = { queries[i], i };
        }

        std::sort(std::begin(qwi), std::end(qwi));

        std::vector<int> res(q);

        std::unordered_map<int, int> cnt;

        auto r = 0;
        auto l = 0;

        auto tot = 0;

        for (auto i = 0; i < q; i++)
        {
            const auto end = qwi[i].first;
            const auto start = end - x;

            while (r < std::size(logs) && logs[r][1] <= end)
            {
                if (cnt[logs[r][0]]++ == 0)
                {
                    tot++;
                }

                r++;
            }

            while (l < r && logs[l][1] < start)
            {
                if (cnt[logs[l][0]]-- == 1)
                {
                    tot--;
                }

                l++;
            }

            res[qwi[i].second] = n - tot;
        }

        return res;
    }
};