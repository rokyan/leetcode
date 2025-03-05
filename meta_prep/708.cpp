/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};
*/

class Solution
{
public:
    Node* insert(Node* head, int insertVal)
    {
        if (head == nullptr)
        {
            auto res = new Node{insertVal};
            res->next = res;
            return res;
        }

        auto prev = head;
        auto cur = head->next;

        do
        {
            if (prev->val <= insertVal && insertVal <= cur->val)
            {
                prev->next = new Node{insertVal, cur};
                break;
            }
            else if (prev->val > cur->val && (insertVal >= prev->val || insertVal <= cur->val))
            {
                prev->next = new Node{insertVal, cur};
                break;
            }

            prev = cur;
            cur = cur->next;
        }
        while (prev != head);

        prev->next = new Node{insertVal, cur};
        return head;
    }
};