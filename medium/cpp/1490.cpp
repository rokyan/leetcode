// https://leetcode.com/problems/clone-n-ary-tree/description/

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution
{
public:
    Node* cloneTree(Node* root)
    {
        if (root == nullptr)
        {
            return nullptr;
        }

        auto cloned = new Node(root->val);

        for (auto to : root->children)
        {
            cloned->children.push_back(cloneTree(to));
        }

        return cloned;
    }
};