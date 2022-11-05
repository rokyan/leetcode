// https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution
{
public:
    Node* connect(Node* root)
    {
        if (root == nullptr)
        {
            return root;
        }
        
        Node* node = root;
        Node* prev = nullptr;
        Node* first = nullptr;
        
        while (node != nullptr)
        {           
            if (node->left != nullptr)
            {
                if (prev != nullptr)
                {
                    prev->next = node->left;
                }
                
                prev = node->left;
                
                if (first == nullptr)
                {
                    first = node->left;
                }
            }
            
            if (node->right != nullptr)
            {
                if (prev != nullptr)
                {
                    prev->next = node->right;
                }
                
                prev = node->right;
                
                if (first == nullptr)
                {
                    first = node->right;
                }
            }
            
            node = node->next;
            
            if (node == nullptr)
            {
                node = first;
                first = nullptr;
                prev = nullptr;
            }
        }
        
        return root;    
    }
};