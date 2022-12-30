// https://leetcode.com/problems/find-largest-value-in-each-tree-row/description/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution
{
public:
    std::vector<int> largestValues(TreeNode* root)
    {
        std::vector<int> largest;
        solve(root, largest);

        return largest;
    }

private:
    void solve(TreeNode* root, std::vector<int>& largest, int depth = 0)
    {
        if (root == nullptr)
        {
            return;
        }
        
        if (std::size(largest) == depth)
        {
            largest.push_back(root->val);
        }
        else
        {
            largest[depth] = std::max(largest[depth], root->val);
        }
        
        solve(root->left, largest, depth + 1);
        solve(root->right, largest, depth + 1);
    }
};