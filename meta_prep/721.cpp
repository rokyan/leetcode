class Solution
{
public:
    std::vector<std::vector<std::string>> accountsMerge(std::vector<std::vector<std::string>>& accounts)
    {
        const auto n = std::size(accounts);

        std::vector<std::vector<int>> graph(n);

        for (auto i = 0; i + 1 < n; i++)
        {
            std::unordered_set<std::string> probe(std::begin(accounts[i]) + 1, std::end(accounts[i]));

            for (auto j = i + 1; j < n; j++)
            {
                if (std::any_of(std::begin(accounts[j]) + 1, std::end(accounts[j]), [&probe](const auto& e) {
                    return probe.find(e) != probe.end();
                }))
                {
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }

        std::vector<char> vis(n);

        std::vector<std::vector<std::string>> res;

        for (auto i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                std::set<std::string> un;
                dfs(i, graph, vis, accounts, un);
                res.push_back({accounts[i].front()});
                res.back().insert(std::end(res.back()), std::begin(un), std::end(un));
            }
        }

        return res;
    }

private:
    void dfs(int v, const std::vector<std::vector<int>>& graph, std::vector<char>& vis,
        const std::vector<std::vector<std::string>>& accounts, std::set<std::string>& un)
    {
        un.insert(std::begin(accounts[v]) + 1, std::end(accounts[v]));

        for (auto to : graph[v])
        {
            if (!vis[to])
            {
                vis[to] = true;
                dfs(to, graph, vis, accounts, un);
            }
        }
    }
};