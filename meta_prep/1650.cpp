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
    Node* lowestCommonAncestor(Node* p, Node* q)
    {
        std::vector<Node*> path_to_p;

        while (p != nullptr)
        {
            path_to_p.push_back(p);
            p = p->parent;
        }

        std::vector<Node*> path_to_q;

        while (q != nullptr)
        {
            path_to_q.push_back(q);
            q = q->parent;
        }

        std::ranges::reverse(path_to_p);
        std::ranges::reverse(path_to_q);

        auto idx = 0;

        while (idx < std::min(std::size(path_to_p), std::size(path_to_q)) &&
            path_to_p[idx] == path_to_q[idx])
        {
            idx++;
        }

        return path_to_p[idx - 1];
    }
};