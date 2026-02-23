// https://leetcode.com/problems/binary-tree-cameras/description/

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
    struct state
    {
        int hasCamera{0};
        int noCameraCovered{0};
        int noCameraNotCovered{0};
    };

    static constexpr int inf = 1000'000'000;

public:
    int minCameraCover(TreeNode* root)
    {
        const auto res = dfs(root);
        return std::min(res.hasCamera, res.noCameraCovered);
    }

private:
    state dfs(TreeNode* root)
    {
        if (root == nullptr)
        {
            return {inf, 0, inf};
        }

        if (root->left == nullptr && root->right == nullptr)
        {
            return state{1, inf, 0};
        }

        const auto leftRes = dfs(root->left);
        const auto rightRes = dfs(root->right);

        state res;

        res.hasCamera = 1
            + std::min({leftRes.hasCamera, leftRes.noCameraCovered, leftRes.noCameraNotCovered})
            + std::min({rightRes.hasCamera, rightRes.noCameraCovered, rightRes.noCameraNotCovered});

        res.noCameraCovered = std::min(
            leftRes.hasCamera + std::min({rightRes.hasCamera, rightRes.noCameraCovered}),
            rightRes.hasCamera + std::min({leftRes.hasCamera, leftRes.noCameraCovered})
        );

        res.noCameraNotCovered = leftRes.noCameraCovered + rightRes.noCameraCovered;

        return res;
    }
};