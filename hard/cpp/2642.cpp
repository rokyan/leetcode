// https://leetcode.com/problems/design-graph-with-shortest-path-calculator/description/

class Graph
{
private:
    static constexpr int inf = 2000'000'000;

public:
    Graph(int n, vector<vector<int>>& edges)
        :n{n}
    {
        dst.resize(n, std::vector<int>(n, inf));

        for (int i = 0; i < n; i++)
        {
            dst[i][i] = 0;
        }

        for (const auto& edge : edges)
        {
            const int from = edge[0];
            const int to = edge[1];
            const int cost = edge[2];

            dst[from][to] = cost;
        }

        recalc();
    }
    
    void addEdge(vector<int> edge)
    {
        dst[edge[0]][edge[1]] = edge[2];
        changed = true;
    }
    
    int shortestPath(int node1, int node2)
    {
        if (changed)
        {
            recalc();
            changed = false;
        }

        return dst[node1][node2] == inf ? -1 : dst[node1][node2];
    }

private:
    void recalc()
    {
        for (int k = 0; k < n; k++)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (dst[i][k] != inf && dst[k][j] != inf)
                    {
                        dst[i][j] = std::min(dst[i][j], dst[i][k] + dst[k][j]);
                    }
                }
            }
        }
    }

private:
    std::vector<std::vector<int>> dst;
    int n;
    bool changed{false};
};

/**
 * Your dst object will be instantiated and called as such:
 * dst* obj = new dst(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */