// https://leetcode.com/problems/step-by-step-directions-from-a-binary-tree-node-to-another/description/

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
    string getDirections(TreeNode* root, int startValue, int destValue)
    {
        const auto lca_node = lca(root, startValue, destValue);

        // std::cout << lca_node->val << std::endl;

        std::string ls;
        find(lca_node, startValue, ls);

        std::string ds;
        find(lca_node, destValue, ds);

        for (auto& c : ls)
        {
            c = 'U';
        }

        return ls + ds;
    }

private:
    TreeNode* lca(TreeNode* root, int sv, int dv)
    {
        if (root == nullptr)
        {
            return nullptr;
        }

        if (root->val == sv || root->val == dv)
        {
            return root;
        }

        const auto ls_res = lca(root->left, sv, dv);
        const auto rs_res = lca(root->right, sv, dv);

        if (ls_res != nullptr && rs_res != nullptr)
        {
            return root;
        }

        return ls_res ? ls_res : rs_res;
    }

    bool find(TreeNode* root, int value, std::string& acc)
    {
        if (root == nullptr)
        {
            return false;
        }

        if (root->val == value)
        {
            return true;
        }

        acc.push_back('L');
        auto found = find(root->left, value, acc);

        if (found)
        {
            return true;
        }

        acc.pop_back();
        acc.push_back('R');

        found = find(root->right, value, acc);

        if (found)
        {
            return true;
        }

        acc.pop_back();
        return false;
    }
};