// https://leetcode.com/problems/k-th-largest-perfect-subtree-size-in-binary-tree/description/

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
    int kthLargestPerfectSubtree(TreeNode* root, int k)
    {
        dfs(root, k);

        if (std::size(sizes) < k)
        {
            return -1;
        }

        return sizes.top();
    }

private:
    std::pair<bool, int> dfs(TreeNode* root, int k)
    {
        if (root == nullptr)
        {
            return { true, 0 };
        }

        const auto left = dfs(root->left, k);
        const auto right = dfs(root->right, k);

        if (left.first && right.first && left.second == right.second)
        {
            const auto s = left.second + right.second + 1;

            sizes.push(s);

            if (std::size(sizes) > k)
            {
                sizes.pop();
            }

            return { true, s };
        }
        else
        {
            return { false, 0 };
        }
    }

private:
    std::priority_queue<int, std::vector<int>, greater<int>> sizes;
};