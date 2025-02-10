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
    std::vector<std::vector<int>> verticalOrder(TreeNode* root)
    {
        if (root == nullptr)
        {
            return {};
        }

        std::queue<std::pair<TreeNode*, int>> q;
        q.push({root, 0});

        std::unordered_map<int, std::vector<int>> columns;

        static constexpr auto inf = 1000'000'000;
        auto min_col = inf;
        auto max_col = -inf;

        while (!q.empty())
        {
            const auto [node, col] = q.front();
            q.pop();
            columns[col].push_back(node->val);

            min_col = std::min(min_col, col);
            max_col = std::max(max_col, col);

            if (node->left != nullptr)
            {
                q.push({node->left, col - 1});
            }

            if (node->right != nullptr)
            {
                q.push({node->right, col + 1});
            }
        }

        std::vector<std::vector<int>> res;
        res.reserve(max_col - min_col + 1);

        for (auto col = min_col; col <= max_col; col++)
        {
            res.push_back(std::move(columns[col]));
        }

        return res;
    }
};