class Solution
{
public:
    long long matrixSumQueries(int n, std::vector<std::vector<int>>& queries)
    {
        std::vector<std::pair<int, int>> rows(n);
        std::unordered_map<int, std::pair<int, int>> cols;

        auto ts = 1;

        for (const auto& query : queries)
        {
            const auto type = query[0];
            const auto id = query[1];
            const auto val = query[2];

            if (type == 0)
            {
                rows[id] = { ts, val };
            }
            else
            {
                cols[id] = { ts, val};
            }

            ts++;
        }

        std::vector<std::pair<int, int>> val_with_ts;

        for (const auto& entry : cols)
        {
            val_with_ts.push_back(entry.second);
        }

        std::sort(std::begin(val_with_ts), std::end(val_with_ts));

        const auto sz = std::size(val_with_ts);

        std::vector<long long> par(sz);

        for (auto i = 0; i < sz; i++)
        {
            par[i] = val_with_ts[i].second;

            if (i > 0)
            {
                par[i] += par[i - 1];
            }
        }

        auto res = 0LL;

        for (auto i = 0; i < n; i++)
        {
            const auto ts = rows[i].first;
            const auto val = rows[i].second;

            res += 1LL * val * n;

            const auto it = std::upper_bound(std::begin(val_with_ts), std::end(val_with_ts), std::make_pair(ts, 0));
            const auto idx = std::distance(std::begin(val_with_ts), it);

            if (idx < sz)
            {
                res -= 1LL * val * (sz - idx);
                res += par[sz - 1] - ((idx > 0) ? par[idx - 1] : 0);
            }
        }

        return res;
    }
};