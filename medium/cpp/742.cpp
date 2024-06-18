// https://leetcode.com/problems/closest-leaf-in-a-binary-tree/description/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
private:
    using graph_type = std::unordered_map<int, std::vector<int>>;

public:
    int findClosestLeaf(TreeNode* root, int k)
    {
        auto [graph, leaves] = transform(root);

        std::queue<int> q;
        q.push(k);

        std::unordered_set<int> visited;
        visited.insert(k);

        while (!q.empty())
        {
            auto v = q.front();
            q.pop();

            if (const auto it = leaves.find(v); it != std::end(leaves))
            {
                return v;
            }

            for (auto to : graph[v])
            {
                if (const auto it = visited.find(to); it == std::end(visited))
                {
                    visited.insert(to);
                    q.push(to);
                }
            }
        }

        return -1;
    }

private:
    std::tuple<graph_type, std::unordered_set<int>> transform(TreeNode* root)
    {
        graph_type graph;
        std::unordered_set<int> leaves;
        dfs(root, graph, leaves);
        return { graph, leaves };
    }

    void dfs(TreeNode* root, graph_type& graph, std::unordered_set<int>& leaves, TreeNode* prev = nullptr)
    {
        if (root == nullptr)
        {
            return;
        }

        if (prev != nullptr)
        {
            graph[prev->val].push_back(root->val);
            graph[root->val].push_back(prev->val);
        }

        if (root->left == nullptr && root->right == nullptr)
        {
            leaves.insert(root->val);
        }

        dfs(root->left, graph, leaves, root);
        dfs(root->right, graph, leaves, root);
    }
};