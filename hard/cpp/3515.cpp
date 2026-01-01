// https://leetcode.com/problems/shortest-path-in-a-weighted-tree/description/

class Solution
{
private:
    using graph_type = std::vector<std::vector<std::pair<int, int>>>;

    class segment_tree final
    {
    public:
        segment_tree(const std::vector<int>& data)
            : size(data.size())
            , tree(4 * size)
            , delta(4 * size)
        {
            build(data, 1, 0, size - 1);
        }

        void add(int l, int r, int value)
        {
            add_impl(l, r, value, 1, 0, size - 1);
        }

        int get(int pos)
        {
            return get_impl(pos, 1, 0, size - 1);
        }

    private:
        void build(const std::vector<int>& data, int v, int tl, int tr)
        {
            if (tl == tr)
            {
                tree[v] = data[tl];
                return;
            }

            const int mid = tl + (tr - tl) / 2;

            build(data, v * 2, tl, mid);
            build(data, v * 2 + 1, mid + 1, tr);

            tree[v] = tree[v * 2] + tree[v * 2 + 1];
        }

        void add_impl(int l, int r, int value, int v, int tl, int tr)
        {
            if (l == tl && r == tr)
            {
                delta[v] += value;
                return;
            }

            const int mid = tl + (tr - tl) / 2;

            if (r <= mid)
            {
                add_impl(l, r, value, v * 2, tl, mid);
            }
            else if (l > mid)
            {
                add_impl(l, r, value, v * 2 + 1, mid + 1, tr);
            }
            else
            {
                add_impl(l, mid, value, v * 2, tl, mid);
                add_impl(mid + 1, r, value, v * 2 + 1, mid + 1, tr);
            }
        }

        int get_impl(int pos, int v, int tl, int tr)
        {
            if (tl == tr)
            {
                return tree[v] + delta[v];
            }

            const int mid = tl + (tr - tl) / 2;

            delta[v * 2] += delta[v];
            delta[v * 2 + 1] += delta[v];
            delta[v] = 0;

            if (pos <= mid)
            {
                return get_impl(pos, v * 2, tl, mid);
            }
            else
            {
                return get_impl(pos, v * 2 + 1, mid + 1, tr);
            }
        }

    private:
        int size;
        std::vector<long long> tree;
        std::vector<long long> delta;
    };

public:
    std::vector<int> treeQueries(int n,
        const std::vector<std::vector<int>>& edges,
        const std::vector<std::vector<int>>& queries)
    {
        const graph_type graph{build_graph(n, edges)};

        std::vector<int> t_in(n);
        std::vector<int> t_out(n);
        std::vector<int> dist(n);
        std::vector<int> w(n);

        int time = 0;

        dfs(0, -1, 0, time, 0, graph, t_in, t_out, dist, w);

        std::vector<int> res;
        res.reserve(queries.size());

        segment_tree tree{dist};

        for (const auto& query : queries)
        {
            const int type = query[0];

            if (type == 1)
            {
                const int u = query[1] - 1;
                const int v = query[2] - 1;
                const int weight = query[3];

                const int node = t_in[u] > t_in[v] ? u : v;

                const int delta = weight - w[t_in[node]];
                w[t_in[node]] = weight;
                tree.add(t_in[node], t_out[node], delta);

                // std::cout << node << " " << t_in[node] << " " << t_out[node] << " " << delta << std::endl;
            }
            else
            {
                const int u = query[1] - 1;
                res.push_back(tree.get(t_in[u]));
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
            const int u = edge[0] - 1;
            const int v = edge[1] - 1;
            const int w = edge[2];

            graph[u].emplace_back(v, w);
            graph[v].emplace_back(u, w);
        }

        return graph;
    }

    void dfs(int v, int p, int d, int& time, int weight, const graph_type& graph,
        std::vector<int>& t_in, std::vector<int>& t_out, std::vector<int>& dist, std::vector<int>& w)
    {
        t_in[v] = time;
        dist[time] = d;
        w[time] = weight;
        time++;

        for (const auto [to, to_weight] : graph[v])
        {
            if (to != p)
            {
                dfs(to, v, d + to_weight, time, to_weight, graph, t_in, t_out, dist, w);
            }
        }

        t_out[v] = time - 1;
    }
};