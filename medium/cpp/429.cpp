// https://leetcode.com/problems/n-ary-tree-level-order-traversal/

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution
{
public:
    std::vector<std::vector<int>> levelOrder(Node* root)
    {
        if (root == nullptr) return {};
        
        int level = 0;
        
        std::vector<std::vector<int>> vals_per_level;
        std::vector<int> vals_per_cur_level;
        
        std::queue<std::pair<Node*, int>> q;
        q.push({ root, 0 });
        
        while (!q.empty())
        {
            auto node = q.front().first;
            auto cur_level = q.front().second;
            q.pop();
            
            for (auto to : node->children)
            {
                q.push({ to, cur_level + 1 });
            }
            
            if (cur_level == level)
            {
                vals_per_cur_level.push_back(node->val);
            }
            else
            {
                vals_per_level.push_back(vals_per_cur_level);
                vals_per_cur_level = { node->val };
                level++;
            }
        }
        
        vals_per_level.push_back(vals_per_cur_level);
        
        return vals_per_level;
    }
};