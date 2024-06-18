// https://leetcode.com/problems/correct-a-binary-tree/description/

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
    TreeNode* correctBinaryTree(TreeNode* root)
    {
        std::vector<TreeNode*> level{ root };
        auto fixed = false;

        while (!level.empty() && !fixed)
        {
            std::vector<TreeNode*> next_level;
            std::unordered_set<TreeNode*> probe;

            for (auto node : level)
            {
                if (node->right != nullptr)
                {
                    if (const auto it = probe.find(node->right->right); it != std::end(probe))
                    {
                        node->right = nullptr;
                        fixed = true;
                    }

                    next_level.push_back(node->right);
                    probe.insert(node->right);
                }

                if (fixed)
                {
                    break;
                }

                if (node->left != nullptr)
                {
                    if (const auto it = probe.find(node->left->right); it != std::end(probe))
                    {
                        node->left = nullptr;
                        fixed = true;
                    }

                    next_level.push_back(node->left);
                    probe.insert(node->left);
                }

                if (fixed)
                {
                    break;
                }
            }

            if (fixed)
            {
                break;
            }

            level = std::move(next_level);
        }

        return root;
    }
};