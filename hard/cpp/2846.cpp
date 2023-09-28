// https://leetcode.com/problems/minimum-edge-weight-equilibrium-queries-in-a-tree/description/

class Solution
{
public:
    std::vector<int> minOperationsQueries(int n, std::vector<std::vector<int>>& edges, std::vector<std::vector<int>>& queries)
    {
        std::vector<std::vector<std::pair<int, int>>> graph(n);

        for (const auto& edge : edges)
        {
            graph[edge[0]].emplace_back(edge[1], edge[2]);
            graph[edge[1]].emplace_back(edge[0], edge[2]);
        }

        height.resize(n);
        dfs(0, -1, 0, graph);

        first.resize(n, -1);

        for (auto i = 0; i < std::size(order); i++)
        {
            if (first[order[i]] == -1)
            {
                first[order[i]] = i;
            }
        }

        tree.resize(4 * std::size(order));
        build(1, 0, std::size(order) - 1);

        cnt.resize(n);
        cnt[0].resize(26);
        dfs2(0, -1, graph);

        std::vector<int> res(std::size(queries));

        std::vector<int> tmp(26);

        for (auto q = 0; q < std::size(queries); q++)
        {
            const auto u = queries[q][0];
            const auto v = queries[q][1];
            const auto t = get_lca(u, v);

            auto max_c = 0;
            auto tot = 0;

            for (auto w = 0; w < 26; w++)
            {
                tmp[w] = cnt[u][w] + cnt[v][w] - 2 * cnt[t][w];
                max_c = std::max(max_c, tmp[w]);
                tot += tmp[w];
            }

            res[q] = tot - max_c;
        }

        return res;
    }

private:
    void dfs(int v, int p, int h, const std::vector<std::vector<std::pair<int, int>>>& graph)
    {
        order.push_back(v);
        height[v] = h;

        for (const auto& edge : graph[v])
        {
            if (edge.first != p)
            {
                dfs(edge.first, v, h + 1, graph);
                order.push_back(v);
            }
        }
    }

    void dfs2(int v, int p, const std::vector<std::vector<std::pair<int, int>>>& graph)
    {
        for (const auto& edge : graph[v])
        {
            if (edge.first != p)
            {
                cnt[edge.first] = cnt[v];
                cnt[edge.first][edge.second - 1]++;
                dfs2(edge.first, v, graph);
            }
        }
    }

    void build(int v, int l, int r)
    {
        if (l == r)
        {
            tree[v] = order[l];
        }
        else
        {
            const auto mid = l + (r - l) / 2;

            build(v * 2, l, mid);
            build(v * 2 + 1, mid + 1, r);

            tree[v] = (height[tree[v * 2]] <= height[tree[v * 2 + 1]])
                ? tree[v * 2]
                : tree[v * 2 + 1];
        }
    }

    int get_lca(int u, int v)
    {
        int l = first[u];
        int r = first[v];

        if (l > r)
        {
            std::swap(l, r);
        }

        return get_min(1, l, r, 0, std::size(order) - 1);
    }

    int get_min(int v, int l, int r, int tl, int tr)
    {
        if (l == tl && r == tr)
        {
            return tree[v];
        }

        const auto mid = tl + (tr - tl) / 2;

        if (r <= mid)
        {
            return get_min(v * 2, l, r, tl, mid);
        }

        if (l > mid)
        {
            return get_min(v * 2 + 1, l, r, mid + 1, tr);
        }

        const auto lv = get_min(v * 2, l, mid, tl, mid);
        const auto rv = get_min(v * 2 + 1, mid + 1, r, mid + 1, tr);
        return height[lv] <= height[rv] ? lv : rv;
    }

private:
    std::vector<int> order;
    std::vector<int> height;
    std::vector<int> first;
    std::vector<int> tree;
    std::vector<std::vector<int>> cnt;
};