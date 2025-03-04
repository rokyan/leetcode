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
        if (node == nullptr)
        {
            return nullptr;
        }

        std::unordered_map<Node*, Node*> cloned;
        cloned[node] = new Node(node->val);
    
        std::queue<Node*> q;
        q.push(node);

        while (!q.empty())
        {
            auto cur = q.front();
            q.pop();

            for (auto to : cur->neighbors)
            {
                if (cloned.find(to) == std::end(cloned))
                {
                    cloned.emplace(to, new Node(to->val));
                    q.push(to);
                }

                cloned[cur]->neighbors.push_back(cloned[to]);
            }
        }

        return cloned[node];
    }
};