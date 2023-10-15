// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree-ii/description/

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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        auto cnt = 0;
        auto lca = find_lca(root, cnt, p, q);
        return cnt == 2 ? lca : nullptr;
    }

private:
    TreeNode* find_lca(TreeNode* root, int& cnt, TreeNode* p, TreeNode* q)
    {
        if (root == nullptr)
        {
            return nullptr;
        }

        if (root == p)
        {
            cnt++;
        }
        
        if (root == q)
        {
            cnt++;
        }

        auto l = find_lca(root->left, cnt, p, q);
        auto r = find_lca(root->right, cnt, p, q);

        if (l && r)
        {
            return root;
        }

        if (root == p || root == q)
        {
            return root;
        }

        return l ? l : r;
    }
};