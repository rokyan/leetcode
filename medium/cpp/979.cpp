// https://leetcode.com/problems/distribute-coins-in-binary-tree/

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
    int distributeCoins(TreeNode* root)
    {
        int answer = 0;
        solve(root, answer);
        return answer;
    }
    
private:
    std::pair<int, int> solve(TreeNode* node, int& answer)
    {
        std::pair<int, int> node_res { 1, node->val };
        
        if (node->left == nullptr && node->right == nullptr)
        {
            return node_res;
        }
        
        if (node->left != nullptr)
        {
            const auto node_left_res = solve(node->left, answer);
            answer += std::abs(node_left_res.first - node_left_res.second);
            node_res.first += node_left_res.first;
            node_res.second += node_left_res.second;
        }
        
        if (node->right != nullptr)
        {
            const auto node_right_res = solve(node->right, answer);
            answer += std::abs(node_right_res.first - node_right_res.second);
            node_res.first += node_right_res.first;
            node_res.second += node_right_res.second;
        }
        
        return node_res;
    }
};