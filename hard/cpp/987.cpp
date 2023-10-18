// https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/description/

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
    std::vector<std::vector<int>> verticalTraversal(TreeNode* root)
    {
        std::map<int, std::vector<std::pair<int, int>>> all;
        dfs(root, all);

        std::vector<std::vector<int>> res;

        for (auto&& entry : all)
        {
            std::sort(std::begin(entry.second), std::end(entry.second));

            std::vector<int> column;
            column.reserve(std::size(entry.second));

            for (auto&& e : entry.second)
            {
                column.push_back(e.second);
            }

            res.push_back(std::move(column));
        }

        return res;
    }

private:
    void dfs(TreeNode* root, std::map<int, std::vector<std::pair<int, int>>>& all, int row = 0, int col = 0)
    {
        if (root == nullptr)
        {
            return;
        }

        all[col].push_back({ row, root->val });

        dfs(root->left, all, row + 1, col - 1);
        dfs(root->right, all, row + 1, col + 1);
    }
};