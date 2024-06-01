// https://leetcode.com/problems/find-the-level-of-tree-with-minimum-sum/description/

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
    int minimumLevel(TreeNode* root)
    {
        std::vector<long long> sum;
        dfs(root, sum);

        return 1 + std::distance(std::cbegin(sum), std::min_element(std::cbegin(sum), std::cend(sum)));
    }

private:
    void dfs(TreeNode* root, std::vector<long long>& sum, int d = 0)
    {
        if (root == nullptr)
        {
            return;
        }

        if (std::size(sum) == d)
        {
            sum.push_back(0);
        }

        sum[d] += root->val;

        dfs(root->left, sum, d + 1);
        dfs(root->right, sum, d + 1);
    }
};