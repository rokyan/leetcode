// https://leetcode.com/problems/check-if-two-expression-trees-are-equivalent/description/

/**
 * Definition for a binary tree node.
 * struct Node {
 *     char val;
 *     Node *left;
 *     Node *right;
 *     Node() : val(' '), left(nullptr), right(nullptr) {}
 *     Node(char x) : val(x), left(nullptr), right(nullptr) {}
 *     Node(char x, Node *left, Node *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    bool checkEquivalence(Node* root1, Node* root2)
    {
        std::map<int, int> freq1, freq2;
        dfs(root1, freq1);
        dfs(root2, freq2);
        return freq1 == freq2;
    }

private:
    void dfs(Node* root, std::map<int, int>& freq)
    {
        if (root == nullptr)
        {
            return;
        }

        freq[root->val]++;

        dfs(root->left, freq);
        dfs(root->right, freq);
    }
};