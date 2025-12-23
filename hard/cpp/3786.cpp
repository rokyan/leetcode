// https://leetcode.com/problems/total-sum-of-interaction-cost-in-tree-groups/description/

class Solution
{
private:
    using graph_type = std::vector<std::vector<int>>;

private:
    struct state
    {
        long long nodes_cnt{0LL};
        long long all_paths_len{0LL};
    };

public:
    long long interactionCosts(int n, const std::vector<std::vector<int>>& edges,
        const std::vector<int>& group)
    {
        const graph_type graph{build_graph(n, edges)};

        long long res = 0LL;

        std::array<bool, 20> has_group;
        has_group.fill(0);

        for (int g : group)
        {
            has_group[g - 1] = true;
        }

        for (int cur_group = 1; cur_group <= 20; cur_group++)
        {
            if (has_group[cur_group - 1])
            {
                static_cast<void>(dfs(0, -1, cur_group, res, group, graph));
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

    state dfs(int v, int parent, int cur_group, long long& res,
        const std::vector<int>& group, const graph_type& graph)
    {
        int total_nodes_cnt{0};

        std::vector<state> states;
        states.reserve(std::size(graph[v]));

        for (int to : graph[v])
        {
            if (to != parent)
            {
                state child_state = dfs(to, v, cur_group, res, group, graph);
                total_nodes_cnt += child_state.nodes_cnt;
                states.push_back(std::move(child_state));
            }
        }

        for (const state& child_state : states)
        {
            if (child_state.nodes_cnt > 0)
            {
                const int rem_nodes_cnt = total_nodes_cnt - child_state.nodes_cnt;

                if (rem_nodes_cnt)
                {
                    res += rem_nodes_cnt * (child_state.all_paths_len + child_state.nodes_cnt);
                }

                if (group[v] == cur_group)
                {
                    res += child_state.all_paths_len + child_state.nodes_cnt;
                }
            }
        }

        state node_state;

        for (const state& child_state : states)
        {
            if (child_state.nodes_cnt > 0)
            {
                node_state.nodes_cnt += child_state.nodes_cnt;
                node_state.all_paths_len += child_state.all_paths_len + child_state.nodes_cnt;
            }
        }

        if (group[v] == cur_group)
        {
            node_state.nodes_cnt++;
        }

        return node_state;
    }
};