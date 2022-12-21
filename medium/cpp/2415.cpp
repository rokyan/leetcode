// https://leetcode.com/problems/reverse-odd-levels-of-binary-tree/description/

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
    TreeNode* reverseOddLevels(TreeNode* root)
    {
        std::queue<std::pair<TreeNode*, int>> nodes;
        nodes.push({ root, 0 });

        std::vector<TreeNode*> level_nodes;
        auto level = 0;

        while (!nodes.empty())
        {
            auto node = nodes.front();
            nodes.pop();

            if (node.first->left != nullptr)
            {
                nodes.push({ node.first->left, node.second + 1 });
            }

            if (node.first->right != nullptr)
            {
                nodes.push({ node.first->right, node.second + 1 });
            }

            if (node.second > level)
            {
                if (level % 2 == 1)
                {
                    reverse(level_nodes);
                }

                level_nodes.clear();

                level++;
            }

            level_nodes.push_back(node.first);
        }

        if (level % 2 == 1)
        {
            reverse(level_nodes);
        }

        return root;
    }

private:
    void reverse(const std::vector<TreeNode*>& level_nodes)
    {
        const auto total_nodes = std::size(level_nodes);

        for (auto i = 0; i * 2 < total_nodes; i++)
        {
            std::swap(level_nodes[i]->val, level_nodes[total_nodes - i - 1]->val);
        }
    }
};