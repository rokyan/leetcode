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
    TreeNode* str2tree(const std::string& s)
    {
        if (s.empty())
        {
            return nullptr;
        }

        return build(s);
    }

private:
    TreeNode* build(const std::string_view& sw)
    {
        const auto n = std::size(sw);
        auto pos = 0;

        while (pos < n && sw[pos] != '(')
        {
            pos++;
        }

        auto value = 0;
        std::from_chars(std::cbegin(sw), std::next(std::cbegin(sw), pos), value);
        auto node = new TreeNode{value};

        for (auto i = pos, balance = 0; i < n; i++)
        {
            if (sw[i] == '(')
            {
                balance++;
            }

            if (sw[i] == ')')
            {
                balance--;
            }

            if (balance == 0)
            {
                const auto len = i - pos + 1;

                if (node->left == nullptr)
                {
                    node->left = build(sw.substr(pos + 1, len - 2));
                }
                else
                {
                    node->right = build(sw.substr(pos + 1, len - 2));
                }

                pos = i + 1;
            }
        }

        return node;
    }
};