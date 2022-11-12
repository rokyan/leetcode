// https://leetcode.com/problems/all-elements-in-two-binary-search-trees/

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
    std::vector<int> getAllElements(TreeNode* root1, TreeNode* root2)
    {
        std::vector<int> sorted1, sorted2;
        
        fill_sorted(root1, sorted1);
        fill_sorted(root2, sorted2);
        
        std::vector<int> result;
        
        std::merge(std::begin(sorted1), std::end(sorted1), std::begin(sorted2), std::end(sorted2), std::back_inserter(result));
        
        return result;
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
};