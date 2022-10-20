// https://leetcode.com/problems/delete-nodes-and-return-forest/

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
    std::vector<TreeNode*> delNodes(TreeNode* root, std::vector<int>& to_delete)
    {
        std::vector<char> probe(1000 + 1);
        
        for (auto e : to_delete)
        {
            probe[e] = true;
        }
        
        std::vector<TreeNode*> nodes;
               
        solve(root, probe, nodes, true);
        
        return nodes;
    }
    
private:
    TreeNode* solve(TreeNode* root, const std::vector<char>& probe, std::vector<TreeNode*>& nodes, bool is_root)
    {
        if (root == nullptr)
        {
            return nullptr;
        }
        
        if (!probe[root->val] && is_root)
        {
            nodes.push_back(root);
        }
        
        root->left = solve(root->left, probe, nodes, probe[root->val]);
        root->right = solve(root->right, probe, nodes, probe[root->val]);
        
        return probe[root->val] ? nullptr : root;
    }
};