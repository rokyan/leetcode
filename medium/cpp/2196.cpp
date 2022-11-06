// https://leetcode.com/problems/create-binary-tree-from-descriptions/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution
{
public:
    TreeNode* createBinaryTree(std::vector<std::vector<int>>& descriptions)
    {      
        std::unordered_map<int, std::vector<std::pair<int, bool>>> graph;
        std::unordered_set<int> children;
        
        for (const auto& description : descriptions)
        {
            const auto parent = description[0];
            const auto child = description[1];
            const auto is_left = description[2];
            
            children.insert(child);
            
            std::pair<int, int> edge { child, is_left };

            auto it = graph.find(parent);
            
            if (it != std::end(graph))
            {
                it->second.push_back(edge);
            }
            else
            {
                graph[parent] = { edge };
            }
        }
        
        TreeNode* root = new TreeNode();
        
        for (auto entry : graph)
        {
            if (children.find(entry.first) == children.end())
            {
                root->val = entry.first;
                break;
            }
        }
        
        std::queue<TreeNode*> nodes;
        nodes.push(root);
        
        while (!nodes.empty())
        {
            auto node = nodes.front();
            nodes.pop();
            
            auto it = graph.find(node->val);
            
            if (it != std::end(graph))
            {
                for (auto to : it->second)
                {
                    auto child = new TreeNode(to.first);
                    
                    if (to.second)
                    {
                        node->left = child;
                    }
                    else
                    {
                        node->right = child;
                    }
                    
                    nodes.push(child);
                }
            }
        }
                
        return root;
    }
};