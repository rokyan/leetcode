// https://leetcode.com/problems/check-completeness-of-a-binary-tree/description/

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
    bool isCompleteTree(TreeNode* root)
    {
        std::queue<TreeNode*> q;
        q.push(root);

        while (!q.empty())
        {
            auto node = q.front();
            q.pop();

            if (node == nullptr)
            {
                break;
            }

            q.push(node->left);
            q.push(node->right);
        }

        while (!q.empty())
        {
            if (q.front() != nullptr)
            {
                return false;
            }

            q.pop();
        }

        return true;
    }
};