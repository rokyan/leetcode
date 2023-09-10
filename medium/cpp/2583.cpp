// https://leetcode.com/problems/kth-largest-sum-in-a-binary-tree/description/

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
    long long kthLargestLevelSum(TreeNode* root, int k)
    {
        std::vector<long long> acc;
        dfs(root, acc);

        if (std::size(acc) < k)
        {
            return -1;
        }

        std::nth_element(std::begin(acc), std::begin(acc) + k - 1, std::end(acc), std::greater<>{});

        return *(std::begin(acc) + k - 1);
    }

private:
    void dfs(TreeNode* root, std::vector<long long>& acc, int depth = 0)
    {
        if (root == nullptr)
        {
            return;
        }

        if (std::size(acc) == depth)
        {
            acc.push_back(0);
        }

        acc[depth] += root->val;

        dfs(root->left, acc, depth + 1);
        dfs(root->right, acc, depth + 1);
    }
};