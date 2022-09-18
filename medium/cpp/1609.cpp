// https://leetcode.com/problems/even-odd-tree/

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
    bool isEvenOddTree(TreeNode* root)
    {
        std::vector<int> last_value;
        
        return dfs(root, 0, last_value);
    }
    
private:
    bool dfs(TreeNode* root, std::size_t depth, std::vector<int>& last_value)
    {
        if (root == nullptr)
        {
            return true;
        }
        
        if (depth % 2 == 0 && root->val % 2 == 0)
        {
            return false;
        }
        
        if (depth % 2 == 1 && root->val % 2 == 1)
        {
            return false;
        }
        
        if (depth == std::size(last_value))
        {
            last_value.push_back(root->val);
        }
        else
        {
            if (depth % 2 == 0 && last_value[depth] >= root->val)
            {
                return false;
            }
            
            if (depth % 2 == 1 && last_value[depth] <= root->val)
            {
                return false;
            }
            
            last_value[depth] = root->val;
        }
        
        return dfs(root->left, depth + 1, last_value) && dfs(root->right, depth + 1, last_value);
    }
};