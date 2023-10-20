// https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/description/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    std::vector<int> distanceK(TreeNode* root, TreeNode* target, int k)
    {
        std::unordered_map<TreeNode*, TreeNode*> parent;
        dfs(root, parent);

        TreeNode* last = nullptr;

        std::vector<int> res;

        for (auto node = target; node != nullptr; node = parent[node])
        {
            dfs2(node, last, k, res);
            k--;
            last = node;
        }

        return res;
    }

private:
    void dfs(TreeNode* root, std::unordered_map<TreeNode*, TreeNode*>& parent, TreeNode* p = nullptr)
    {
        if (root == nullptr)
        {
            return;
        }

        parent[root] = p;

        dfs(root->left, parent, root);
        dfs(root->right, parent, root);
    }

    void dfs2(TreeNode* root, TreeNode* banned, int k, std::vector<int>& res)
    {
        if (root == nullptr || root == banned)
        {
            return;
        }

        if (k == 0)
        {
            res.push_back(root->val);
            return;
        }

        dfs2(root->left, banned, k - 1, res);
        dfs2(root->right, banned, k - 1, res);
    }
};