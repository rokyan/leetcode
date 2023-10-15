// https://leetcode.com/problems/binary-search-tree-iterator/description/

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
class BSTIterator
{
public:
    BSTIterator(TreeNode* root)
        : node{ root }
    {        
    }
    
    int next()
    {
        while (node != nullptr)
        {
            st.push_back(node);
            node = node->left;
        }

        const auto popped = st.back();
        st.pop_back();

        node = popped->right;

        return popped->val;
    }
    
    bool hasNext()
    {
        return node != nullptr || !st.empty();
    }

private:
    TreeNode* node;
    std::vector<TreeNode*> st;
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */