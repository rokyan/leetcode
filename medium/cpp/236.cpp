// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/description/

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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        std::vector<std::pair<TreeNode*, int>> order;
        
        build(root, order);
        
        auto p_it = std::find_if(std::begin(order), std::end(order),
            [p](auto e) { return e.first == p; });
        auto q_it = std::find_if(std::begin(order), std::end(order),
            [q](auto e) { return e.first == q; });
        
        if (p_it > q_it) {
            std::swap(p_it, q_it);
        }
        
        const auto min_it = std::min_element(p_it, q_it,
            [](auto e1, auto e2) { return e1.second < e2.second; });
        
        return min_it->first;
    }
    
private:
    void build(TreeNode* node, std::vector<std::pair<TreeNode*, int>>& order, int depth = 0)
    {      
        order.emplace_back(node, depth);
        
        if (node->left != nullptr)
        {
            build(node->left, order, depth + 1);
        }
        
        order.push_back(std::make_pair(node, depth));
        
        if (node->right != nullptr)
        {
            build(node->right, order, depth + 1);
        }
        
        order.emplace_back(node, depth);
    }
};