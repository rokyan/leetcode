// https://leetcode.com/problems/count-paths-that-can-form-a-palindrome-in-a-tree/description/

class Solution
{
public:
    long long countPalindromePaths(std::vector<int>& parent, std::string s)
    {
        const auto n = std::size(parent);

        std::vector<std::vector<int>> graph(n);

        for (auto v = 1; v < n; v++)
        {
            graph[parent[v]].push_back(v);
        }

        std::unordered_map<int, int> cnt;
       
        dfs(0, -1, 0, graph, s, cnt);

        auto res = 0LL;

        for (const auto& entry : cnt)
        {
            auto mask = entry.first;
            auto c = entry.second;

            res += 1LL * c * (c - 1);

            for (auto bit = 0; bit < 26; bit++)
            {
                const auto next_mask = mask ^ (1 << bit);

                if (const auto it = cnt.find(next_mask); it != std::end(cnt))
                {
                    res += 1LL * c * it->second;
                }
            }
        }

        return res / 2;
    }

private:
    void dfs(int v, int p, int mask, const std::vector<std::vector<int>>& graph, const std::string& s,
        std::unordered_map<int, int>& cnt)
    {
        cnt[mask]++;

        for (auto to : graph[v])
        {
            if (to != p)
            {
                const auto next_mask = mask ^ (1 << (s[to] - 'a'));
                dfs(to, v, next_mask, graph, s, cnt);
            }
        }
    }
};