// https://leetcode.com/problems/maximum-width-of-binary-tree/

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
private:
    using ull = unsigned long long;
    
    struct state
    {
        state(TreeNode* node, int depth, ull pos)
            : node(node)
            , depth(depth)
            , pos(pos)
        {}
        
        TreeNode* node;
        int depth;
        ull pos;
    };
    
public:
    int widthOfBinaryTree(TreeNode* root)
    {
        std::queue<state> q;
        q.push(state(root, 0, 0));
        
        ull ans = 0;
        ull level = 0;
        ull left_pos = 0;
        ull right_pos = 0;
        
        while (!q.empty())
        {
            auto cur = q.front();
            q.pop();
            
            if (cur.depth > level)
            {
                ans = std::max(ans, right_pos - left_pos + 1);
                left_pos = right_pos = cur.pos;
                level++;
            }
            else
            {
                right_pos = cur.pos;
            }
            
            if (cur.node->left)
            {
                q.push(state(cur.node->left, cur.depth + 1, (cur.pos - left_pos) * 2));
            }
            
            if (cur.node->right)
            {
                q.push(state(cur.node->right, cur.depth + 1, (cur.pos - left_pos) * 2 + 1));
            }
        }
        
        return std::max(ans, right_pos - left_pos + 1);
    }
};  