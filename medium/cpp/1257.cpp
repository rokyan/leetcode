// https://leetcode.com/problems/smallest-common-region/description/

class Solution
{
public:
    std::string findSmallestRegion(std::vector<std::vector<std::string>>& regions,
        std::string region1, std::string region2)
    {
        std::unordered_map<std::string, std::vector<std::string>> graph;

        std::unordered_set<std::string> roots;

        for (const auto& entry : regions)
        {
            roots.insert(entry[0]);
        }

        for (const auto& entry : regions)
        {
            for (auto i = 1; i < std::size(entry); i++)
            {
                graph[entry[0]].push_back(entry[i]);

                if (const auto it = roots.find(entry[i]); it != std::end(roots))
                {
                    roots.erase(it);
                }
            }
        }

        for (const auto& root : roots)
        {
            const auto res = dfs(root, "", graph, region1, region2);

            if (res)
            {
                return res.value();
            }
        }

        return "";
    }

private:
    std::optional<std::string> dfs(const std::string& root, const std::string& parent,
        const std::unordered_map<std::string, std::vector<std::string>>& graph,
        const std::string& region1, const std::string& region2)
    {
        if (root == region1 || root == region2)
        {
            return root;
        }

        const auto it = graph.find(root);

        if (it == std::end(graph))
        {
            return {};
        }

        std::vector<std::string> nodes;

        for (const auto& to : it->second)
        {
            if (to != parent)
            {
                const auto res = dfs(to, root, graph, region1, region2);

                if (res)
                {
                    nodes.push_back(res.value());
                }
            }
        }

        if (std::size(nodes) == 2)
        {
            return root;
        }

        if (std::size(nodes) == 1)
        {
            return nodes.front();
        }

        return {};
    }
};