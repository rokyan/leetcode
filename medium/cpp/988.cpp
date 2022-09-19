// https://leetcode.com/problems/smallest-string-starting-from-leaf/

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
    string smallestFromLeaf(TreeNode* root)
    {
        std::vector<int> acc;
        std::vector<int> ans;
        
        solve(root, acc, ans);
        
        std::string smallest;
        smallest.reserve(std::size(ans));
        
        std::transform(std::rbegin(ans), std::rend(ans), std::back_inserter(smallest), [](auto val) {
            return 'a' + val;
        });
        
        return smallest;
    }
    
private:
    void solve(TreeNode* root, std::vector<int>& acc, std::vector<int>& ans)
    {
        if (root == nullptr)
        {
            return;
        }
        
        acc.push_back(root->val);
        
        if (root->left == nullptr && root->right == nullptr)
        {
            if (ans.empty() || std::lexicographical_compare(std::rbegin(acc), std::rend(acc),
                std::rbegin(ans), std::rend(ans)))
            {
                ans = acc;
            }
        }
        
        solve(root->left, acc, ans);
        solve(root->right, acc, ans);
        
        acc.pop_back();
    }
};