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
    using graphType = std::vector<std::vector<int>>;

public:
    int findClosestLeaf(TreeNode* root, int k)
    {
        auto graph = build(root);
        dfs(graph, k);
        return res;
    }

private:
    graphType build(TreeNode* root)
    {
        graphType graph;
        build(graph, root);
        return graph;
    }

    void build(graphType& graph, TreeNode* root, TreeNode* parent = nullptr)
    {
        if (root == nullptr)
        {
            return;
        }

        const int val = root->val;

        while (std::size(graph) <= val)
        {
            graph.push_back({});
        }

        if (parent != nullptr)
        {
            graph[val].push_back(parent->val);
        }

        bool leaf = true;

        if (root->left != nullptr)
        {
            graph[val].push_back(root->left->val);
            build(graph, root->left, root);
            leaf = false;
        }

        if (root->right != nullptr)
        {
            graph[val].push_back(root->right->val);
            build(graph, root->right, root);
            leaf = false;
        }

        if (leaf)
        {
            leaves.insert(root->val);
        }
    }

    void dfs(const graphType& graph, int v, int parent = -1, int distance = 0)
    {
        for (int to : graph[v])
        {
            if (to != parent)
            {
                dfs(graph, to, v, distance + 1);
            }
        }

        if (leaves.count(v) > 0)
        {
            if (distanceToLeaf == -1 || distance < distanceToLeaf)
            {
                distanceToLeaf = distance;
                res = v;
            }
        }
    }

private:
    std::unordered_set<int> leaves;
    int res = 1;
    int distanceToLeaf = -1;
};