// https://leetcode.com/problems/pseudo-palindromic-paths-in-a-binary-tree/

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
    int pseudoPalindromicPaths (TreeNode* root)
    {
        std::vector<int> counts(10);
        
        return dfs(root, counts);
    }
    
private:
    int dfs(TreeNode* node, std::vector<int>& counts)
    {
        int tot = 0;
        
        counts[node->val]++;
        
        if (is_leaf(node))
        {
            int odd = 0;
            
            for (std::size_t i = 0; i < 10 && odd < 2; i++)
            {
                if (counts[i] & 1)
                {
                    odd++;
                }
            }
             
            tot = odd < 2;
        }
        else
        {
            if (node->left != nullptr)
            {
                tot += dfs(node->left, counts);
            }

            if (node->right != nullptr)
            {
                tot += dfs(node->right, counts);
            }
        }
        
        counts[node->val]--;
        
        return tot;
    }
    
    bool is_leaf(TreeNode* node)
    {
        return node->left == nullptr && node->right == nullptr;
    }
};