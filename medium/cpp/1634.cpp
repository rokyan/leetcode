// https://leetcode.com/problems/add-two-polynomials-represented-as-linked-lists/description/

/**
 * Definition for polynomial singly-linked list.
 * struct PolyNode {
 *     int coefficient, power;
 *     PolyNode *next;
 *     PolyNode(): coefficient(0), power(0), next(nullptr) {};
 *     PolyNode(int x, int y): coefficient(x), power(y), next(nullptr) {};
 *     PolyNode(int x, int y, PolyNode* next): coefficient(x), power(y), next(next) {};
 * };
 */

class Solution
{
public:
    PolyNode* addPoly(PolyNode* poly1, PolyNode* poly2)
    {
        auto head = new PolyNode{};
        auto cur = head;

        while (poly1 != nullptr && poly2 != nullptr)
        {
            PolyNode* node = nullptr;

            if (poly1->power == poly2->power)
            {
                if (poly1->coefficient + poly2->coefficient)
                {
                    node = new PolyNode{ poly1->coefficient + poly2->coefficient, poly1->power };
                }
                poly1 = poly1->next;
                poly2 = poly2->next;
            }
            else if (poly1->power > poly2->power)
            {
                node = new PolyNode{ poly1->coefficient, poly1->power };
                poly1 = poly1->next;
            }
            else
            {
                node = new PolyNode{ poly2->coefficient, poly2->power };
                poly2 = poly2->next;
            }

            if (node != nullptr)
            {
                cur->next = node;
                cur = node;
            }
        }

        while (poly1 != nullptr)
        {
            auto node = new PolyNode{ poly1->coefficient, poly1->power };
            poly1 = poly1->next;
            cur->next = node;
            cur = node;
        }

        while (poly2 != nullptr)
        {
            auto node = new PolyNode{ poly2->coefficient, poly2->power };
            poly2 = poly2->next;
            cur->next = node;
            cur = node;
        }

        return head->next;
    }
};