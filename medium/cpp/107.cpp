// https://leetcode.com/problems/binary-tree-level-order-traversal-ii/

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
    std::vector<std::vector<int>> levelOrderBottom(TreeNode* root)
    {
        if (root == nullptr)
        {
            return {};
        }
        
        std::queue<std::pair<TreeNode*, int>> nodes_with_level;
        nodes_with_level.push({ root, 0 });

        std::vector<std::vector<int>> ans;
        std::vector<int> cur;

        auto current_level = 0;

        while (!nodes_with_level.empty())
        {
            const auto node_with_level = nodes_with_level.front();
            nodes_with_level.pop();

            auto node = node_with_level.first;
            auto level = node_with_level.second;

            if (node->left != nullptr)
            {
                nodes_with_level.push({ node->left, level + 1 });
            }

            if (node->right != nullptr)
            {
                nodes_with_level.push({ node->right, level + 1 });
            }

            if (level == current_level)
            {
                cur.push_back(node->val);
            }
            else
            {
                ans.push_back(cur);
                cur = { node->val };
                current_level++;
            }
        }
        
        ans.push_back(cur);
        
        std::reverse(std::begin(ans), std::end(ans));
        
        return ans;
    }
};