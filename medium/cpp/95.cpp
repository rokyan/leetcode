// https://leetcode.com/problems/unique-binary-search-trees-ii/description/

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
    std::vector<TreeNode*> generateTrees(int n)
    {
        return solve(1, n + 1);
    }

private:
    std::vector<TreeNode*> solve(int left, int right)
    {
        if (left == right)
        {
            return { nullptr };
        }

        if (left + 1 == right)
        {
            return { new TreeNode(left) };
        }

        std::vector<TreeNode*> trees;

        for (auto mid = left; mid < right; mid++)
        {
            auto ltree = solve(left, mid);
            auto rtree = solve(mid + 1, right);
            
            for (auto i = 0; i < std::size(ltree); i++)
            {
                for (auto j = 0; j < std::size(rtree); j++)
                {
                    auto root = new TreeNode(mid);
                    root->left = ltree[i];
                    root->right = rtree[j];
                    trees.push_back(root);
                }
            }
        }

        return trees;
    }
};