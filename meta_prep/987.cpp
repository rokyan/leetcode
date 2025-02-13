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

#include <ranges>

class Solution
{
public:
    std::vector<std::vector<int>> verticalTraversal(TreeNode* root)
    {
        std::map<int, std::vector<std::pair<int, int>>> nodes;

        std::queue<std::tuple<TreeNode*, int, int>> q;
        q.push({root, 0, 0});

        while (!q.empty())
        {
            const auto [node, row, col] = q.front();
            q.pop();

            nodes[col].emplace_back(row, node->val);

            if (node->left != nullptr)
            {
                q.push({node->left, row + 1, col - 1});
            }

            if (node->right != nullptr)
            {
                q.push({node->right, row + 1, col + 1});
            }
        }

        std::vector<std::vector<int>> trav;
        trav.reserve(std::size(nodes));

        for (auto& [_, rows] : nodes)
        {
            std::ranges::sort(rows);
            const auto res_view = rows |
                std::views::transform([](const auto& e) { return e.second; });
            trav.emplace_back(std::begin(res_view), std::end(res_view));
        }

        return trav;
    }
};