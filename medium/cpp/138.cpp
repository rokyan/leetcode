// https://leetcode.com/problems/copy-list-with-random-pointer/description/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution
{
public:
    Node* copyRandomList(Node* head)
    {
        auto n_head = static_cast<Node*>(nullptr);

        std::unordered_map<Node*, Node*> mapping;

        for (auto node = head, last = static_cast<Node*>(nullptr); node != nullptr; node = node->next)
        {
            auto created = new Node(node->val);
            mapping[node] = created;

            if (last != nullptr)
            {
                last->next = created;
            }

            last = created;

            if (n_head == nullptr)
            {
                n_head = created;
            }
        }

        for (auto node = head, n_node = n_head; node != nullptr; node = node->next, n_node = n_node->next)
        {
            n_node->random = mapping[node->random];
        }

        return n_head;
    }
};