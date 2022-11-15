// https://leetcode.com/problems/balance-a-binary-search-tree/

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
    TreeNode* balanceBST(TreeNode* root)
    {
        std::vector<int> sorted;
        fill_sorted(root, sorted);
        
        return build(sorted, 0, std::size(sorted));
    }
    
private:
    void fill_sorted(TreeNode* node, std::vector<int>& sorted)
    {
        if (node == nullptr)
        {
            return;
        }
        
        fill_sorted(node->left, sorted);
        sorted.push_back(node->val);
        fill_sorted(node->right, sorted);
    }
    
    TreeNode* build(const std::vector<int>& sorted, std::size_t left, std::size_t right)
    {
        if (left >= right)
        {
            return nullptr;
        }
        
        const std::size_t mid = left + (right - left) / 2;
        
        auto node = new TreeNode(sorted[mid]);
        
        node->left = build(sorted, left, mid);
        node->right = build(sorted, mid + 1, right);
        
        return node;
    }
};