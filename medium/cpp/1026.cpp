// https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/

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
    int maxAncestorDiff(TreeNode* root)
    {
        int answer = 0;
        solve(root, answer);
        return answer;
    }
    
private:
    std::pair<int, int> solve(TreeNode* node, int& answer)
    {
        std::pair<int, int> ret = { node->val, node->val };
        
        if (node->left != nullptr)
        {
            const auto sol = solve(node->left, answer);
            ret = { std::min(ret.first, sol.first), std::max(ret.second, sol.second )};
        }
        
        if (node->right != nullptr)
        {
            const auto sol = solve(node->right, answer);
            ret = { std::min(ret.first, sol.first), std::max(ret.second, sol.second )};
        }
        
        answer = std::max(answer, std::max(std::abs(node->val - ret.first), std::abs(node->val - ret.second)));
        
        return ret;
    }
};