/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/

class Solution
{
public:
    Node* treeToDoublyList(Node* root)
    {
        if (root == nullptr)
        {
            return nullptr;
        }

        auto [first, last] = dfs(root);
        last->right = first;
        first->left = last;
        return first;
    }

private:
    std::pair<Node*, Node*> dfs(Node* root)
    {
        auto first = root;
        auto last = root;

        if (root->left != nullptr)
        {
            auto [lfirst, llast] = dfs(root->left);
            llast->right = first;
            first->left = llast;
            first = lfirst;
        }

        if (root->right != nullptr)
        {
            auto [rfirst, rlast] = dfs(root->right);
            last->right = rfirst;
            rfirst->left = last;
            last = rlast;
        }

        return {first, last};
    }
};