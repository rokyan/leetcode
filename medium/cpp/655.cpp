// https://leetcode.com/problems/print-binary-tree/description/

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
    std::vector<std::vector<std::string>> printTree(TreeNode* root)
    {
        const auto height = get_height(root) - 1;
        const auto width = (1 << (height + 1)) - 1;

        std::vector<std::vector<std::string>> res(height + 1, std::vector<std::string>(width));

        print(root, 0, (width - 1) / 2, height, res);

        return res;
    }

private:
    static int get_height(TreeNode* root)
    {
        if (root == nullptr)
        {
            return 0;
        }

        return 1 + std::max(get_height(root->left), get_height(root->right));
    }

    static void print(TreeNode* root, int r, int c, int h, std::vector<std::vector<std::string>>& res)
    {
        if (root == nullptr)
        {
            return;
        }

        res[r][c] = std::to_string(root->val);

        if (root->left) print(root->left, r + 1, c - (1 << (h - r - 1)), h, res);
        if (root->right) print(root->right, r + 1, c + (1 << (h - r - 1)), h, res);
    }
};