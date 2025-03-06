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
    {
        go_left(root);     
    }
    
    int next()
    {
        auto top = st.back();
        st.pop_back();

        go_left(top->right);

        return top->val;
    }
    
    bool hasNext()
    {
        return !st.empty();
    }

private:
    void go_left(TreeNode* root)
    {
        while (root != nullptr)
        {
            st.push_back(root);
            root = root->left;
        }    
    }

private:
    std::vector<TreeNode*> st;
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */