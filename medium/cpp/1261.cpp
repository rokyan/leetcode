// https://leetcode.com/problems/find-elements-in-a-contaminated-binary-tree/

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
 
class FindElements
{   
public:
    FindElements(TreeNode* root)
        : root(root)
    {
        recover(root);
    }
    
    bool find(int target)
    {       
        return targets.find(target) != std::end(targets);
    }
    
private:
    void recover(TreeNode* node, int val = 0)
    {
        if (node == nullptr)
        {
            return;
        }
        
        node->val = val;
        targets.insert(val);
        
        recover(node->left, val * 2 + 1);
        recover(node->right, val * 2 + 2);
    }
    
private:
    TreeNode* root;
    std::unordered_set<int> targets;
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */