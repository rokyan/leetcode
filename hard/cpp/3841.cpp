// https://leetcode.com/problems/palindromic-path-queries-in-a-tree/description/

class Solution
{
private:
    using graphType = std::vector<std::vector<int>>;

    class SegmentTree final
    {
    public:
        SegmentTree(int n)
            : tree(4 * n)
            , n{n}
        {}

        int get(int l, int r)
        {
            return get(l, r, 1, 0, n - 1);
        }

        void update(int p, int val)
        {
            update(p, val, 1, 0, n - 1);
        }

    private:
        int get(int l, int r, int v, int tl, int tr)
        {
            if (l == tl && r == tr)
            {
                return tree[v];
            }

            const int tm = (tl + tr) / 2;

            if (r <= tm)
            {
                return get(l, r, v * 2, tl, tm);
            }

            if (l > tm)
            {
                return get(l, r, v * 2 + 1, tm + 1, tr);
            }

            return get(l, tm, v * 2, tl, tm) ^ get(tm + 1, r, v * 2 + 1, tm + 1, tr);
        }

        void update(int p, int value, int v, int tl, int tr)
        {
            if (tl == tr)
            {
                tree[v] = value;
                return;
            }

            const int tm = (tl + tr) / 2;

            if (p <= tm)
            {
                update(p, value, v * 2, tl, tm);
            }
            else
            {
                update(p, value, v * 2 + 1, tm + 1, tr);
            }

            tree[v] = tree[v * 2] ^ tree[v * 2 + 1];
        } 

    private:
        std::vector<int> tree;
        int n;
    };

public:
    std::vector<bool> palindromePath(int n, const std::vector<std::vector<int>>& edges,
        const std::string& s, const std::vector<std::string>& queries)
    {
        graphType graph{buildGraph(n, edges)};
        buildHld(n, graph);
        SegmentTree tree{buildSegmentTree(n, s)};

        std::vector<bool> res;
        res.reserve(queries.size());

        for (const std::string& query : queries)
        {
            if (query[0] == 'q')
            {
                auto [v, u] = parseQuery(query);
                int mask = 0;

                while (start[v] != start[u])
                {
                    if (depth[start[v]] < depth[start[u]])
                    {
                        std::swap(v, u);
                    }

                    mask ^= tree.get(pos[start[v]], pos[v]);
                    v = parent[start[v]];
                }

                if (depth[v] < depth[u])
                {
                    std::swap(v, u);
                }

                mask ^= tree.get(pos[u], pos[v]);

                res.push_back((mask & (mask - 1)) == 0);
            }
            else
            {
                const auto [v, off] = parseUpdate(query);
                tree.update(pos[v], 1 << off);
            }
        }

        return res;
    }

private:
    graphType buildGraph(int n, const std::vector<std::vector<int>>& edges)
    {
        graphType graph(n);

        for (const auto& edge : edges)
        {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        return graph;
    }

    void buildHld(int n, const graphType& graph)
    {
        parent.resize(n, -1);
        size.resize(n);
        depth.resize(n);
        heavy.resize(n, -1);

        dfs(0, graph);

        start.resize(n);
        pos.resize(n);
        int idx = 0;
        decompose(0, 0, idx, graph);
    }

    SegmentTree buildSegmentTree(int n, const std::string& s)
    {
        SegmentTree tree{n};

        for (int v = 0; v < n; v++)
        {
            tree.update(pos[v], 1 << (s[v] - 'a'));
        }

        return tree;
    }

    void dfs(int v, const graphType& graph, int p = -1, int d = 0)
    {
        parent[v] = p;
        depth[v] = d;
        size[v] = 1;
        int maxSize = -1;

        for (int to : graph[v])
        {
            if (to != p)
            {
                dfs(to, graph, v, d + 1);
                size[v] += size[to];

                if (size[to] > maxSize)
                {
                    maxSize = size[to];
                    heavy[v] = to;
                }
            }
        }
    }

    void decompose(int v, int startNode, int& idx, const graphType& graph)
    {
        start[v] = startNode;
        pos[v] = idx++;

        if (heavy[v] != -1)
        {
            decompose(heavy[v], startNode, idx, graph);
        }

        for (int to : graph[v])
        {
            if (to != heavy[v] && to != parent[v])
            {
                decompose(to, to, idx, graph);
            }
        }
    }

    std::pair<int, int> parseQuery(const std::string& query)
    {
        int pos = 0;

        while (query[pos] != ' ')
        {
            pos++;
        }

        pos++;
        int v = 0;

        while (query[pos] != ' ')
        {
            v = 10 * v + query[pos++] - '0';
        }

        pos++;
        int u = 0;

        while (pos < query.size())
        {
            u = 10 * u + query[pos++] - '0';
        }

        return {v, u};
    }

    std::pair<int, int> parseUpdate(const std::string& query)
    {
        int pos = 0;

        while (query[pos] != ' ')
        {
            pos++;
        }

        pos++;
        int v = 0;

        while (query[pos] != ' ')
        {
            v = 10 * v + query[pos++] - '0';
        }

        pos++;

        const int off = query[pos++] - 'a';

        return {v, off};
    }

private:
    std::vector<int> parent;
    std::vector<int> size;
    std::vector<int> depth;
    std::vector<int> heavy;
    std::vector<int> start;
    std::vector<int> pos;
};