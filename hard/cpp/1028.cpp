// https://leetcode.com/problems/recover-a-tree-from-preorder-traversal/description/

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
    TreeNode* recoverFromPreorder(const std::string& traversal)
    {
        return build(traversal, 0, std::size(traversal));
    }

private:
    TreeNode* build(const std::string& traversal, int l, int r, int d = 0)
    {
        auto val = 0;

        l += d;
        while (l < r && std::isdigit(traversal[l]))
        {
            val = 10 * val + traversal[l++] - '0';
        }

        auto node = new TreeNode{val};

        if (l == r)
        {
            return node;
        }

        auto cnt = 0;
        auto split = -1;
        auto skip = true;
        auto start = l;
 
        while (l < r)
        {
            if (traversal[l] == '-')
            {
                cnt++;
            }
            else
            {
                if (cnt == d + 1)
                {
                    if (skip)
                    {
                        skip = false;
                    }
                    else
                    {
                        split = l - cnt;
                        break;
                    }
                }

                cnt = 0;
            }

            l++;
        }

        if (split == -1)
        {
            node->left = build(traversal, start, r, d + 1);
        }
        else
        {
            node->left = build(traversal, start, split, d + 1);
            node->right = build(traversal, split, r, d + 1);
        }

        return node;
    }
};