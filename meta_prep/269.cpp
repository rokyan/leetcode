class Solution
{
public:
    std::string alienOrder(std::vector<std::string>& words)
    {
        std::vector<int> ex(26);

        for (const auto& word : words)
        {
            for (auto c : word)
            {
                ex[c - 'a'] = true;
            }
        }

        std::vector<std::vector<int>> graph(26, std::vector<int>());
    
        for (auto i = 1; i < std::size(words); i++)
        {
            const auto& prev = words[i - 1];
            const auto& cur = words[i];

            const auto len = std::min(std::size(prev), std::size(cur));
            auto dif = 0;

            while (dif < len && prev[dif] == cur[dif])
            {
                dif++;
            }

            if (dif == len)
            {
                if (std::size(cur) < std::size(prev))
                {
                    return "";
                }
            }
            else
            {
                graph[prev[dif] - 'a'].push_back(cur[dif] - 'a');
            }
        }

        std::vector<int> vis(26);

        for (auto v = 0; v < 26; v++)
        {
            if (!vis[v] && dfs(v, graph, vis, ex))
            {
                return "";
            }
        }

        std::fill(std::begin(vis), std::end(vis), 0);

        std::vector<char> res;

        for (auto v = 0; v < 26; v++)
        {
            if (!vis[v])
            {
                dfs2(v, graph, vis, res, ex);
            }
        }

        std::reverse(std::begin(res), std::end(res));

        return std::string(std::begin(res), std::end(res));
    }

private:
    bool dfs(int v,
        const std::vector<std::vector<int>>& graph,
        std::vector<int>& vis,
        const std::vector<int>& ex)
    {
        if (!ex[v])
        {
            return false;
        }

        vis[v] = 1;

        for (auto to : graph[v])
        {
            if (vis[to] == 1)
            {
                return true;
            }

            if (vis[to] == 0)
            {
                if (dfs(to, graph, vis, ex))
                {
                    return true;
                }
            }
        }

        vis[v] = 2;
        return false;
    }

    void dfs2(int v,
        const std::vector<std::vector<int>>& graph,
        std::vector<int>& vis,
        std::vector<char>& res,
        const std::vector<int>& ex)
    {
        if (!ex[v])
        {
            return;
        }

        vis[v] = 1;

        for (auto to : graph[v])
        {
            if (!vis[to])
            {
                dfs2(to, graph, vis, res, ex);
            }
        }

        res.push_back('a' + v);
    }
};