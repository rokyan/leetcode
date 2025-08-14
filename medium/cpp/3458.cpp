// https://leetcode.com/problems/select-k-disjoint-special-substrings/description/

class Solution
{
public:
    bool maxSubstringLength(const std::string& s, int k)
    {
        std::vector<std::pair<int, int>> occ(26, {-1, -1});

        for (auto i = 0; i < std::size(s); i++)
        {
            const auto code = s[i] - 'a';

            if (occ[code].first == -1)
            {
                occ[code].first = i;
            }

            occ[code].second = i;
        }

        std::vector<std::pair<int, int>> segs;

        for (auto code = 0; code < 26; code++)
        {
            if (occ[code].first != -1)
            {
                std::vector<char> used(26);

                std::queue<int> q;
                q.push(code);

                used[code] = true;

                std::pair<int, int> merged = occ[code];

                while (!q.empty())
                {
                    const auto cur = q.front();
                    q.pop();

                    for (auto p = occ[cur].first; p <= occ[cur].second; p++)
                    {
                        const auto next = s[p] - 'a';

                        if (!used[next] && occ[next].first != -1)
                        {
                            merged.first = std::min(merged.first, occ[next].first);
                            merged.second = std::max(merged.second, occ[next].second);
                            used[next] = true;
                            q.push(next);
                        }
                    }
                }

                if (merged.second - merged.first + 1 < std::size(s))
                {
                    segs.push_back(std::move(merged));
                }
            }
        }

        if (segs.empty())
        {
            return k == 0;
        }

        std::ranges::sort(segs, [](const auto& lhs, const auto& rhs) {
            return lhs.second < rhs.second;
        });

        auto maxCnt = 1;

        std::vector<int> dp(std::size(segs), 1);

        for (auto i = 1; i < std::size(segs); i++)
        {
            for (auto j = 0; j < i; j++)
            {
                if (segs[j].second < segs[i].first)
                {
                    dp[i] = std::max(dp[i], 1 + dp[j]);
                    maxCnt = std::max(maxCnt, dp[i]);
                }
            }
        }

        return maxCnt >= k;
    }
};