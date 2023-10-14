// https://leetcode.com/problems/diameter-of-n-ary-tree/description/

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
    int diameter(Node* root)
    {
        auto res = 0;
        static_cast<void>(go(root, res));
        return res;
    }

private:
    int go(Node* root, int& res)
    {
        if (root == nullptr)
        {
            return 0;
        }

        auto max = 0;
        auto smax = 0;

        for (auto&& e : root->children)
        {
            const auto d = go(e, res) + 1;

            if (d >= max)
            {
                smax = max;
                max = d;
            }
            else if (d >= smax)
            {
                smax = d;
            }
        }

        res = std::max(res, max);

        if (smax != -1)
        {
            res = std::max(res, max + smax);
        }

        return max;
    }
};