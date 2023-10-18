// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description/

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
public:
    std::vector<std::vector<int>> zigzagLevelOrder(TreeNode* root)
    {
        std::vector<std::vector<int>> res;
        dfs(root, res);

        for (auto i = 1; i < std::size(res); i += 2)
        {
            std::reverse(std::begin(res[i]), std::end(res[i]));
        }

        return res;
    }

private:
    void dfs(TreeNode* root, std::vector<std::vector<int>>& res, int depth = 0)
    {
        if (root == nullptr)
        {
            return;
        }

        if (std::size(res) == depth)
        {
            res.push_back({});
        }

        res[depth].push_back(root->val);

        dfs(root->left, res, depth + 1);
        dfs(root->right, res, depth + 1);
    }
};