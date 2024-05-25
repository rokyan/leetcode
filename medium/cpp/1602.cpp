// https://leetcode.com/problems/find-nearest-right-node-in-binary-tree/description/

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
    TreeNode* findNearestRightNode(TreeNode* root, TreeNode* u)
    {
        std::unordered_map<TreeNode*, int> d;
        d.emplace(root, 0);

        std::queue<TreeNode*> q;
        q.push(root);

        auto cur_d = 0;
        auto u_d = -1;

        while (!q.empty())
        {
            auto v = q.front();
            q.pop();

            if (d[v] > cur_d)
            {
                cur_d = d[v];
            }

            if (cur_d == u_d)
            {
                return v;
            }

            if (v == u)
            {
                u_d = cur_d;
            }

            if (v->left != nullptr)
            {
                d[v->left] = cur_d + 1;
                q.push(v->left);
            }

            if (v->right != nullptr)
            {
                d[v->right] = cur_d + 1;
                q.push(v->right);
            }
        }

        return nullptr;
    }
};