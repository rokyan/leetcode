// https://leetcode.com/problems/linked-list-in-binary-tree/description/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    bool isSubPath(ListNode* head, TreeNode* root)
    {
        return dfs2(head, root);
    }

private:
    bool dfs2(ListNode* head, TreeNode* root)
    {
        if (root == nullptr)
        {
            return false;
        }

        auto res = dfs(head, root);

        if (!res)
        {
            res = dfs2(head, root->left) || dfs2(head, root->right);
        }

        return res;
    }
    bool dfs(ListNode* head, TreeNode* root)
    {
        if (head == nullptr)
        {
            return true;
        }

        if (root == nullptr)
        {
            return false;
        }

        if (head->val != root->val)
        {
            return false;
        }

        return dfs(head->next, root->left) || dfs(head->next, root->right);
    }
};