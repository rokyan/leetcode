// https://leetcode.com/problems/clone-graph/

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution
{
public:
    Node* cloneGraph(Node* node)
    {
        return clone(node);
    }
    
private:
    Node* clone(Node* node)
    {
        if (node == nullptr)
        {
            return nullptr;
        }
        
        Node* cloned = new Node(node->val);
        visited.insert({ node->val, cloned });
        
        for (auto to : node->neighbors)
        {
            auto it = visited.find(to->val);
            
            if (it != std::end(visited))
            {
                cloned->neighbors.push_back(it->second);
            }
            else
            {
                auto to_cloned = clone(to);
                cloned->neighbors.push_back(to_cloned);
            }
        }
        
        return cloned;
    }
    
private:
    std::unordered_map<int, Node*> visited;
};