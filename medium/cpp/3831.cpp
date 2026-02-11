// https://leetcode.com/problems/median-of-a-binary-search-tree-level/description/

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
    int levelMedian(TreeNode* root, int level)
    {
        std::vector<int> elements;
        dfs(root, 0, level, elements);

        if (elements.empty())
        {
            return -1;
        }

        const int pos = elements.size() / 2;

        std::nth_element(elements.begin(), std::next(elements.begin(), pos), std::end(elements));

        return elements[pos];
    }

private:
    void dfs(TreeNode* root, int depth, int level, std::vector<int>& elements)
    {
        if (root == nullptr)
        {
            return;
        }

        if (depth == level)
        {
            elements.push_back(root->val);
            return;
        }

        dfs(root->left, depth + 1, level, elements);
        dfs(root->right, depth + 1, level, elements);
    }
};