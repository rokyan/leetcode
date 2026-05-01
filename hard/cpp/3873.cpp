// https://leetcode.com/problems/maximum-points-activated-with-one-addition/description/

class Solution
{
private:
    class Dsu
    {
    public:
        Dsu(size_t n)
            : size(n)
            , parent(n)
        {
            for (size_t i = 0; i < n; i++)
            {
                size[i] = 1;
                parent[i] = i;
                state[i] = 1;
            }
        }

        int find(int v)
        {
            if (v == parent[v])
            {
                return v;
            }

            return (parent[v] = find(parent[v]));
        }

        bool uni(int u, int v)
        {
            u = find(u);
            v = find(v);

            if (u == v)
            {
                return false;
            }

            state.erase(u);
            state.erase(v);

            if (size[u] > size[v])
            {
                parent[v] = u;
                size[u] += size[v];
                state.emplace(u, size[u]);
            }
            else
            {
                parent[u] = v;
                size[v] += size[u];
                state.emplace(v, size[v]);
            }

            return true;
        }

        std::unordered_map<int, int> getState()
        {
            return state;
        }

    private:
        std::vector<int> size;
        std::vector<int> parent;
        std::unordered_map<int, int> state;
    };

public:
    int maxActivated(const std::vector<std::vector<int>>& points)
    {
        std::unordered_map<int, int> byX;
        std::unordered_map<int, int> byY;

        Dsu dsu{points.size()};

        for (int v = 0; v < points.size(); v++)
        {
            const int x = points[v][0];
            const int y = points[v][1];

            if (const auto it = byX.find(x); it != byX.end())
            {
                dsu.uni(v, it->second);
            }

            if (const auto it = byY.find(y); it != byY.end())
            {
                dsu.uni(v, it->second);
            }

            byX.insert_or_assign(x, v);
            byY.insert_or_assign(y, v);
        }

        const auto state = dsu.getState();

        if (state.size() == 1)
        {
            return points.size() + 1;
        }

        std::priority_queue<int, std::vector<int>, std::greater<int>> pq;

        for (const auto [_, s] : state)
        {
            pq.push(s);

            if (pq.size() > 2)
            {
                pq.pop();
            }
        }

        int res = 1;

        while (!pq.empty())
        {
            res += pq.top();
            pq.pop();
        }

        return res;
    }
};