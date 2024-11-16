// https://leetcode.com/problems/convert-doubly-linked-list-to-array-ii/description/

/**
 * Definition for doubly-linked list.
 * class Node {
 *     int val;
 *     Node* prev;
 *     Node* next;
 *     Node() : val(0), next(nullptr), prev(nullptr) {}
 *     Node(int x) : val(x), next(nullptr), prev(nullptr) {}
 *     Node(int x, Node *prev, Node *next) : val(x), next(next), prev(prev) {}
 * };
 */
class Solution
{
public:
	std::vector<int> toArray(Node *node)
    {
        auto head = node;

        while (head->prev != nullptr)
        {
            head = head->prev;
        }

        std::vector<int> res;

        while (head)
        {
            res.push_back(head->val);
            head = head->next;
        }

        return res;
    }
};