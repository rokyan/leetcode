// https://leetcode.com/problems/kth-ancestor-of-a-tree-node/description/

class TreeAncestor
{
public:
    TreeAncestor(int n, std::vector<int>& parent)
    {
        init(n, parent);
    }
    
    int getKthAncestor(int node, int k)
    {
        auto h = k;
        auto p = node;

        for (auto i = height; i >= 0; i--)
        {
            if ((1 << i) <= h)
            {
                h -= 1 << i;
                p = parents[p][i];
            }
        }

        return depth[node] - depth[p] == k ? p : -1;
    }

private:
    void init(int n, const std::vector<int>& parent)
    {
        while ((1 << height) < n)
        {
            height++;
        }

        parents.resize(n);

        for (auto v = 0; v < n; v++)
        {
            parents[v].resize(height + 1);
            parents[v][0] = parent[v];
        }

        parents[0][0] = 0;

        for (auto h = 1; h <= height; h++)
        {
            for (auto v = 0; v < n; v++)
            {
                parents[v][h] = parents[parents[v][h - 1]][h - 1];
            }
        }

        std::vector<std::vector<int>> graph(n);

        for (auto v = 1; v < n; v++)
        {
            graph[parent[v]].push_back(v);
        }

        depth.resize(n);

        dfs(0, -1, 0, graph);
    }

private:
    void dfs(int v, int p, int d, const std::vector<std::vector<int>>& graph)
    {
        depth[v] = d;

        for (auto to : graph[v])
        {
            if (to != p)
            {
                dfs(to, v, d + 1, graph);
            }
        }
    }

private:
    int height = 0;
    std::vector<std::vector<int>> parents;
    std::vector<std::vector<int>> graph;
    std::vector<int> depth;
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */