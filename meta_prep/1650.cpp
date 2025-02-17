/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution
{
public:
    Node* lowestCommonAncestor(Node* p, Node * q)
    {
        return find_lca(find_root(p), p, q);
    }

private:
    Node* find_root(Node* node)
    {
        while (node->parent != nullptr)
        {
            node = node->parent;
        }

        return node;
    }

    Node* find_lca(Node* root, Node* p, Node* q)
    {
        if (root == nullptr || root == p || root == q)
        {
            return root;
        }

        auto left = find_lca(root->left, p, q);
        auto right = find_lca(root->right, p, q);

        if (left != nullptr && right != nullptr)
        {
            return root;
        }

        return left != nullptr ? left : right;
    }
};