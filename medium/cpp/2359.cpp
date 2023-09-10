// https://leetcode.com/problems/find-closest-node-to-given-two-nodes/description/

class Solution
{
public:
    int closestMeetingNode(std::vector<int>& edges, int node1, int node2)
    {
        const auto n = std::size(edges);

        std::vector<int> dist1(n, -1);
        dfs(node1, edges, 0, dist1);

        std::vector<int> dist2(n, -1);
        dfs(node2, edges, 0, dist2);

        auto opt_dist = -1;
        auto res = -1;

        for (auto i = 0; i < n; i++)
        {
            if (dist1[i] != -1 && dist2[i] != -1)
            {
                const auto max_dist = std::max(dist1[i], dist2[i]);

                if (opt_dist == -1 || opt_dist > max_dist)
                {
                    opt_dist = max_dist;
                    res = i;
                }
            }
        }

        return res;
    }

private:
    void dfs(int v, std::vector<int>& edges, int d, std::vector<int>& dist)
    {
        dist[v] = d;

        if (edges[v] != -1 && dist[edges[v]] == -1)
        {
            dfs(edges[v], edges, d + 1, dist);
        }
    }
};