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
    std::string getDirections(TreeNode* root, int startValue, int destValue)
    {
        const auto lca = find(root, startValue, destValue);
        traverse(root, nullptr, startValue, destValue);

        std::string up;

        while (start != lca)
        {
            up.push_back('U');
            start = parents[start];
        }

        std::string down;

        while (dest != lca)
        {
            const auto parent = parents[dest];
            down.push_back(parent->left == dest ? 'L' : 'R');
            dest = parent;
        }

        std::ranges::reverse(down);

        return up + down;
    }

private:
    TreeNode* find(TreeNode* root, int startValue, int destValue)
    {
        if (root == nullptr)
        {
            return nullptr;
        }

        if (root->val == startValue || root->val == destValue)
        {
            return root;
        }

        const auto left = find(root->left, startValue, destValue);
        const auto right = find(root->right, startValue, destValue);

        if (left && right)
        {
            return root;
        }

        return left ? left : right;
    }

    void traverse(TreeNode* root, TreeNode* parent, int startValue, int destValue)
    {
        if (root == nullptr)
        {
            return;
        }

        parents[root] = parent;

        if (root->val == startValue)
        {
            start = root;
        }

        if (root->val == destValue)
        {
            dest = root;
        }

        traverse(root->left, root, startValue, destValue);
        traverse(root->right, root, startValue, destValue);
    }

private:
    std::unordered_map<TreeNode*, TreeNode*> parents;
    TreeNode* start;
    TreeNode* dest;
};