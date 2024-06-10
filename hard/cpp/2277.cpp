// https://leetcode.com/problems/closest-node-to-path-in-tree/description/

class Solution
{
private:
    using graph_type = std::vector<std::vector<int>>;

public:
    std::vector<int> closestNode(int n, std::vector<std::vector<int>>& edges, std::vector<std::vector<int>>& query)
    {
        const auto graph = build_graph(n, edges);
        build_bin_lift_table(n, graph);

        std::vector<int> dst(n);

        dfs2(0, -1, 0, graph, dst);

        const auto queries_count = std::size(query);
        std::vector<int> res(queries_count);

        for (auto q_idx = 0; q_idx < queries_count; q_idx++)
        {
            const auto u = query[q_idx][0];
            const auto v = query[q_idx][1];
            const auto node = query[q_idx][2];

            const auto lca = get_lca(u, v);
            res[q_idx] = lca;
            auto d = dst[node] + dst[lca] - 2 * dst[get_lca(node, lca)];

            for (auto cur_node = u; cur_node != lca; cur_node = parent[cur_node])
            {
                const auto cur_d = dst[node] + dst[cur_node] - 2 * dst[get_lca(node, cur_node)];

                if (cur_d < d)
                {
                    d = cur_d;
                    res[q_idx] = cur_node;
                }
            }

            for (auto cur_node = v; cur_node != lca; cur_node = parent[cur_node])
            {
                const auto cur_d = dst[node] + dst[cur_node] - 2 * dst[get_lca(node, cur_node)];

                if (cur_d < d)
                {
                    d = cur_d;
                    res[q_idx] = cur_node;
                }
            }
        }

        return res;
    }

private:
    graph_type build_graph(int n, const std::vector<std::vector<int>>& edges)
    {
        graph_type graph(n);

        for (const auto& edge : edges)
        {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        return graph;
    }

    void build_bin_lift_table(int n, const graph_type& graph)
    {
        parent.resize(n);
        auto time = 0;
        time_in.resize(n);
        time_out.resize(n);

        dfs(0, -1, time, graph, parent);

        while ((1 << height) < n)
        {
            height++;
        }

        bin_lift_table.resize(n);

        for (auto v = 0; v < n; v++)
        {
            bin_lift_table[v].resize(height + 1);
            bin_lift_table[v][0] = parent[v];
        }

        for (auto h = 1; h <= height; h++)
        {
            for (auto v = 0; v < n; v++)
            {
                bin_lift_table[v][h] = bin_lift_table[v][h - 1] == -1
                    ? -1
                    : bin_lift_table[bin_lift_table[v][h - 1]][h - 1];
            }
        }
    }

    void dfs(int v, int p, int& time, const graph_type& graph, std::vector<int>& parent)
    {
        parent[v] = p;
        time_in[v] = time++;

        for (auto to : graph[v])
        {
            if (to != p)
            {
                dfs(to, v, time, graph, parent);
            }
        }

        time_out[v] = time++;
    }

    int get_lca(int u, int v)
    {
        if (is_parent(u, v))
        {
            return u;
        }

        if (is_parent(v, u))
        {
            return v;
        }

        for (auto h = height; h >= 0; h--)
        {
            if (bin_lift_table[u][h] != -1 && !is_parent(bin_lift_table[u][h], v))
            {
                u = bin_lift_table[u][h];
            }
        }

        return parent[u];
    }

    bool is_parent(int u, int v)
    {
        return time_in[u] <= time_in[v] && time_out[u] >= time_out[v];
    }

    void dfs2(int v, int p, int d, const graph_type& graph, std::vector<int>& dst)
    {
        dst[v] = d;

        for (auto to : graph[v])
        {
            if (to != p)
            {
                dfs2(to, v, d + 1, graph, dst);
            }
        }
    }

private:
    std::vector<int> parent;
    int height = 0;
    std::vector<std::vector<int>> bin_lift_table;
    std::vector<int> time_in;
    std::vector<int> time_out;
};