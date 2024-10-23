// https://leetcode.com/problems/check-if-dfs-strings-are-palindromes/description/

class Solution
{
private:
    static constexpr auto base = 31;
    static constexpr auto mod = 1000'000'000 + 7;

public:
    std::vector<bool> findAnswer(const std::vector<int>& parent, const std::string& s)
    {
        const auto n = std::size(parent);

        std::vector<std::vector<int>> graph(n);

        for (auto v = 1; v < n; v++)
        {
            graph[parent[v]].push_back(v);
        }

        for (auto& e : graph)
        {
            std::sort(std::begin(e), std::end(e));
        }

        std::vector<int> pow(n);
        pow[0] = 1;

        for (auto i = 1; i < n; i++)
        {
            pow[i] = 1LL * base * pow[i - 1] % mod;
        }

        std::vector<bool> res(n);

        dfs(0, graph, pow, res, s);

        return res;
    }

private:
    std::tuple<int, int, int> dfs(int v, const std::vector<std::vector<int>>& graph,
        const std::vector<int>& pow, std::vector<bool>& res, const std::string& s)
    {
        std::vector<std::tuple<int, int, int>> r;

        for (auto to : graph[v])
        {
            r.push_back(dfs(to, graph, pow, res, s));
        }

        auto hash = 0;
        auto c = 0;

        for (auto e : r)
        {
            hash += 1LL * std::get<1>(e) * pow[c] % mod;
            hash %= mod;

            c += std::get<0>(e);
        }

        hash += 1LL * (s[v] - 'a' + 1) * pow[c] % mod;
        hash %= mod;

        auto rhash = (s[v] - 'a' + 1);
        c = 1;

        std::reverse(std::begin(r), std::end(r));

        for (auto e : r)
        {
            rhash += 1LL * std::get<2>(e) * pow[c] % mod;
            rhash %= mod;

            c += std::get<0>(e);
        }

        res[v] = hash == rhash;

        return { c, hash, rhash };
    }
};