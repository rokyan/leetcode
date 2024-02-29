// https://leetcode.com/problems/the-earliest-moment-when-everyone-become-friends/

class Solution
{
private:
    class dsu
    {
    public:
        dsu(int n)
        {
            init(n);
        }

        int find(int v)
        {
            if (v == parent[v])
            {
                return v;
            }

            return (parent[v] = find(parent[v]));
        }

        bool un(int u, int v)
        {
            u = find(u);
            v = find(v);

            if (u == v)
            {
                return false;
            }

            if (size[u] > size[v])
            {
                std::swap(u, v);
            }

            parent[u] = v;
            size[v] += size[u];

            return true;
        }

    private:
        void init(int n)
        {
            parent.resize(n);
            size.resize(n, 1);

            std::iota(std::begin(parent), std::end(parent), 0);
        }
    private:
        std::vector<int> parent;
        std::vector<int> size;
    };

public:
    int earliestAcq(vector<vector<int>>& logs, int n)
    {
        std::sort(std::begin(logs), std::end(logs));

        dsu meow{ n };
        auto total = n - 1;

        for (auto i = 0; i < std::size(logs); i++)
        {
            if (meow.un(logs[i][1], logs[i][2]))
            {
                if (total-- == 1)
                {
                    return logs[i][0];
                }
            }
        }

        return -1;
    }
};