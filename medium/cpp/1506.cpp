// https://leetcode.com/problems/find-root-of-n-ary-tree/description/

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
    Node* findRoot(std::vector<Node*> tree)
    {
        std::unordered_map<Node*, int> visited;

        for (auto v : tree)
        {
            dfs(v, visited);
        }

        for (const auto& e : visited)
        {
            if (e.second == std::size(tree))
            {
                return e.first;
            }
        }

        return nullptr;
    }

private:
    int dfs(Node* node, std::unordered_map<Node*, int>& visited)
    {
        if (node == nullptr)
        {
            return 0;
        }

        if (const auto it = visited.find(node); it != std::end(visited))
        {
            return it->second;
        }

        visited[node] = 1;

        for (auto to : node->children)
        {
            visited[node] += dfs(to, visited);
        }

        return visited[node];
    }
};