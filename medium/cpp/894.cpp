// https://leetcode.com/problems/all-possible-full-binary-trees/

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

class Solution {
public:
    vector<TreeNode*> allPossibleFBT(int n)
    {      
        std::vector<TreeNode*> dp[n + 1];
        
        dp[1] = std::vector<TreeNode*>();
        dp[1].push_back(new TreeNode());
        
        for (int nodes_count = 2; nodes_count <= n; nodes_count++)
        {
            for (int left_subtree_nodes_count = 1; left_subtree_nodes_count < nodes_count - 1; left_subtree_nodes_count++)
            {
                int right_subtree_nodes_count = nodes_count - 1 - left_subtree_nodes_count;
                
                for (auto left_tree_root : dp[left_subtree_nodes_count])
                {
                    for (auto right_tree_root : dp[right_subtree_nodes_count])
                    {
                        auto root = new TreeNode();
                        
                        root->left = left_tree_root;
                        root->right = right_tree_root;
                        
                        dp[nodes_count].push_back(root);
                    }
                }
            }
        }
        
        return dp[n];
    }
};