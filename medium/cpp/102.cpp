// https://leetcode.com/problems/binary-tree-level-order-traversal/description/

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
    std::vector<std::vector<int>> levelOrder(TreeNode* root)
    {
        std::vector<std::vector<int>> answer;

        solve(root, answer);

        return answer;
    }
    
    void solve(TreeNode* node, std::vector<std::vector<int>>& answer, int depth = 0)
    {
        if (node == nullptr)
        {
            return;
        }
        
        if (depth == answer.size())
        {
            answer.push_back({});
        }
        
        answer[depth].push_back(node->val);
        
        solve(node->left, answer, depth + 1);
        solve(node->right, answer, depth + 1);
    }

};