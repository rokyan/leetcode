// https://leetcode.com/problems/two-sum-bsts/description/

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
    bool twoSumBSTs(TreeNode* root1, TreeNode* root2, int target)
    {
        return find(root1, root2, target);
    }

private:
    bool find(TreeNode* root1, TreeNode* root2, int target)
    {
        if (root1 == nullptr)
        {
            return false;
        }

        if (find2(root2, target - root1->val))
        {
            return true;
        }

        return find(root1->left, root2, target) || find(root1->right, root2, target);
    }

    bool find2(TreeNode* root2, int target)
    {
        if (root2 == nullptr)
        {
            return false;
        }

        if (root2->val == target)
        {
            return true;
        }

        if (root2->val < target)
        {
            return find2(root2->right, target);
        }

        return find2(root2->left, target);
    }
};