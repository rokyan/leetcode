// https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/description/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head)
    {
        return build(head, getLen(head));
    }

private:
    int getLen(ListNode* head) const
    {
        auto len = 0;
        
        while (head != nullptr)
        {
            head = head->next;
            len++;
        }
        
        return len;
    }
    
    TreeNode* build(ListNode*& head, int len) const
    {
        if (len == 0)
        {
            return nullptr;
        }
        
        const auto left = build(head, len / 2);
        
        TreeNode* node = new TreeNode(head->val);
        head = head->next;
        
        const auto right = build(head, len - len / 2 - 1);
        
        node->left = left;
        node->right = right;
        
        return node;
    }
};