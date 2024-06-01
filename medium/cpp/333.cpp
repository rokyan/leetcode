// https://leetcode.com/problems/largest-bst-subtree/description/

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
    struct state
    {
        state(int max_value, int min_value, int size, bool is_bst)
            : max_value{ max_value }
            , min_value{ min_value }
            , size{ size }
            , is_bst{ is_bst }
        {}

        int max_value;
        int min_value;
        int size;
        bool is_bst;
    };

public:
    int largestBSTSubtree(TreeNode* root)
    {
        if (root == nullptr)
        {
            return 0;
        }

        auto res = 0;
        static_cast<void>(dfs(root, res));

        return res;
    }

private:
    state dfs(TreeNode* root, int& res)
    {
        state cur{ root->val, root->val, 1, true };

        if (root->left != nullptr)
        {
            const auto ls = dfs(root->left, res);
            cur.max_value = std::max(cur.max_value, ls.max_value);
            cur.min_value = std::min(cur.min_value, ls.min_value);
            cur.size += ls.size;
            cur.is_bst &= ls.max_value < root->val && ls.is_bst;
        }

        if (root->right != nullptr)
        {
            const auto rs = dfs(root->right, res);
            cur.max_value = std::max(cur.max_value, rs.max_value);
            cur.min_value = std::min(cur.min_value, rs.min_value);
            cur.size += rs.size;
            cur.is_bst &= rs.min_value > root->val && rs.is_bst;
        }

        if (cur.is_bst)
        {
            res = std::max(res, cur.size);
        }

        return cur;
    }
};