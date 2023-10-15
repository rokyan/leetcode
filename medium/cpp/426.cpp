// https://leetcode.com/problems/convert-binary-search-tree-to-sorted-doubly-linked-list/description/

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
        
        auto res = build(root);

        res.second->right = res.first;
        res.first->left = res.second;

        return res.first;
    }

private:
    std::pair<Node*, Node*> build(Node* root)
    {
        if (root == nullptr)
        {
            return { nullptr, nullptr };
        }

        auto l_res = build(root->left);
        auto r_res = build(root->right);

        auto start = root;
        auto end = root;

        // std::cout << root->val << std::endl;

        if (l_res.second != nullptr)
        {
            l_res.second->right = root;
            root->left = l_res.second;
            start = l_res.first;
        }

        if (r_res.first != nullptr)
        {
            r_res.first->left = root;
            root->right = r_res.first;
            end = r_res.second;
        }

        return { start, end };
    }
};