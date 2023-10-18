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

        std::map<int, std::vector<int>> order;
        std::queue<std::pair<TreeNode*, int>> q;
        q.push({ root, 0 });

        while (!q.empty())
        {
            const auto state = q.front();
            q.pop();

            order[state.second].push_back(state.first->val);

            if (state.first->left != nullptr)
            {
                q.push({ state.first->left, state.second - 1 });
            }

            if (state.first->right != nullptr)
            {
                q.push({ state.first->right, state.second + 1 });
            }
        }

        std::vector<std::vector<int>> res;
        res.reserve(std::size(order));

        for (auto&& e : order)
        {
            res.push_back(e.second);
        }

        return res;
    }
};