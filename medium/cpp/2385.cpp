// https://leetcode.com/problems/amount-of-time-for-binary-tree-to-be-infected/description/

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
    int amountOfTime(TreeNode* root, int start)
    {
        std::unordered_map<TreeNode*, std::vector<TreeNode*>> graph;

        std::queue<TreeNode*> q;
        q.push(root);

        TreeNode* startNode = nullptr;

        while (!q.empty())
        {
            const auto node = q.front();
            q.pop();

            if (node->val == start)
            {
                startNode = node;
            }

            if (node->left != nullptr)
            {
                graph[node].push_back(node->left);
                graph[node->left].push_back(node);
                q.push(node->left);
            }

            if (node->right != nullptr)
            {
                graph[node].push_back(node->right);
                graph[node->right].push_back(node);
                q.push(node->right);
            }
        }

        auto res = 0;

        std::unordered_map<TreeNode*, int> dist;
        dist[startNode] = 0;

        q.push(startNode);

        while (!q.empty())
        {
            const auto node = q.front();
            q.pop();

            for (const auto to : graph[node])
            {
                if (dist.count(to) == 0)
                {
                    dist[to] = dist[node] + 1;
                    res = std::max(res, dist[to]);
                    q.push(to);
                }
            }
        }

        return res;
    }
};