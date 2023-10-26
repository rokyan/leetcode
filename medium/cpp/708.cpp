// https://leetcode.com/problems/insert-into-a-sorted-circular-linked-list/description/

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
            auto inserted = new Node(insertVal);
            inserted->next = inserted;
            return inserted;
        }

        auto node = head;

        while (node->next->val >= node->val && node->next != head)
        {
            node = node->next;
        }

        auto inserted = new Node(insertVal);

        if (insertVal <= node->next->val || insertVal >= node->val)
        {
            inserted->next = node->next;
            node->next = inserted;
        }
        else
        {
            node = node->next;
            auto prev = node;
            node = node->next;

            while (insertVal > node->val)
            {
                prev = node;
                node = node->next;
            }

            prev->next = inserted;
            inserted->next = node;
        }

        return head;
    }
};