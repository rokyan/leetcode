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
    std::vector<int> boundaryOfBinaryTree(TreeNode* root)
    {
        std::vector<int> res{root->val};

        if (root->left == nullptr && root->right == nullptr)
        {
            return res;
        }

        const auto leftBoundary = getLeftBoundary(root);
        res.insert(std::end(res), std::begin(leftBoundary), std::end(leftBoundary));
        const auto leaves = getLeaves(root);
        res.insert(std::end(res), std::begin(leaves), std::end(leaves));
        const auto rightBoundary = getRightBoundary(root);
        res.insert(std::end(res), std::begin(rightBoundary), std::end(rightBoundary));

        return res;
    }

private:
    std::vector<int> getLeftBoundary(TreeNode* root)
    {
        if (root->left != nullptr)
        {
            root = root->left;
        }
        else
        {
            return {};
        }

        std::vector<int> boundary;

        while (root != nullptr)
        {
            if (root->left == nullptr && root->right == nullptr)
            {
                break;
            }

            boundary.push_back(root->val);

            if (root->left != nullptr)
            {
                root = root->left;
            }
            else
            {
                root = root->right;
            }
        }

        return boundary;
    }

    std::vector<int> getRightBoundary(TreeNode* root)
    {
        if (root->right != nullptr)
        {
            root = root->right;
        }
        else
        {
            return {};
        }

        std::vector<int> boundary;

        while (root != nullptr)
        {
            if (root->left == nullptr && root->right == nullptr)
            {
                break;
            }

            boundary.push_back(root->val);

            if (root->right != nullptr)
            {
                root = root->right;
            }
            else
            {
                root = root->left;
            }
        }

        std::ranges::reverse(boundary);

        return boundary;
    }

    std::vector<int> getLeaves(TreeNode* root)
    {
        std::vector<int> res;

        dfs(root, res);

        return res;
    }

    void dfs(TreeNode* root, std::vector<int>& res)
    {
        if (root == nullptr)
        {
            return;
        }

        if (root->left == nullptr && root->right == nullptr)
        {
            res.push_back(root->val);
        }

        dfs(root->left, res);
        dfs(root->right, res);
    }
};