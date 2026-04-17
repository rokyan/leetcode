// https://leetcode.com/problems/zigzag-level-sum-of-binary-tree/description/

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
    std::vector<long long> zigzagLevelSum(TreeNode* root)
    {
        std::vector<TreeNode*> level;
        level.push_back(root);

        int dir = 1;

        std::vector<long long> res;

        while (!level.empty())
        {
            std::vector<TreeNode*> nextLevel;
            nextLevel.reserve(level.size());

            long long sum = 0;
            bool skip = false;

            if (dir == 1)
            {
                for (int i = 0; i < level.size(); i++)
                {
                    TreeNode* node = level[i];

                    if (node->left)
                    {
                        nextLevel.push_back(node->left);
                    }
                    else
                    {
                        skip = true;
                    }

                    if (node->right)
                    {
                        nextLevel.push_back(node->right);
                    }

                    if (!skip)
                    {
                        sum += node->val;
                    }
                }
            }
            else
            {
                for (int i = level.size() - 1; i >= 0; i--)
                {
                    TreeNode* node = level[i];

                    if (node->right)
                    {
                        nextLevel.push_back(node->right);
                    }
                    else
                    {
                        skip = true;
                    }

                    if (node->left)
                    {
                        nextLevel.push_back(node->left);
                    }

                    if (!skip)
                    {
                        sum += node->val;
                    }
                }

                std::ranges::reverse(nextLevel);
            }
            dir ^= 1;
            res.push_back(sum);
            level = std::move(nextLevel);
        }

        return res;
    }
};