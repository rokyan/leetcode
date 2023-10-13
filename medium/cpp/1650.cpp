// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree-iii/description/

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
        std::vector<Node*> path_p;

        for (auto node = p; node != nullptr; node = node->parent)
        {
            path_p.push_back(node);
        }

        std::vector<Node*> path_q;

        for (auto node = q; node != nullptr; node = node->parent)
        {
            path_q.push_back(node);
        }

        std::reverse(std::begin(path_p), std::end(path_p));
        std::reverse(std::begin(path_q), std::end(path_q));

        auto i = 0;

        for ( ; i < std::min(std::size(path_p), std::size(path_q)); i++)
        {
            if (path_p[i] != path_q[i])
            {
                break;
            }
        }

        return path_p[i - 1];
    }
};