// https://leetcode.com/problems/recover-binary-search-tree/

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
    void recoverTree(TreeNode* root)
    {
        std::vector<TreeNode*> nodes;
        traverse(root, nodes);
        
        std::pair<int, int> pos_to_swap { -1, -1 };
        
        for (std::size_t i = 1; i < std::size(nodes); i++)
        {
            if (nodes[i - 1]->val > nodes[i]->val)
            {
                if (pos_to_swap.first == -1)
                {
                    pos_to_swap = { i - 1, i };
                }
                else
                {
                    pos_to_swap.second = i;
                }
            }
        }
        
        std::swap(nodes[pos_to_swap.first]->val, nodes[pos_to_swap.second]->val);
    }
    
private:
    void traverse(TreeNode* node, vector<TreeNode*>& nodes)
    {
        if (node == nullptr)
        {
            return;
        }
        
        traverse(node->left, nodes);
        nodes.push_back(node);
        traverse(node->right, nodes);
    }
};