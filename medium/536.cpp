// https://leetcode.com/problems/construct-binary-tree-from-string/description/

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
    TreeNode* str2tree(std::string s)
    {
        if (s.empty())
        {
            return nullptr;
        }

        return deserialize(s);
    }

private:
    TreeNode* deserialize(const std::string& s)
    {
        // std::cout << s << std::endl;

        auto pos = static_cast<int>(s.find('('));

        if (pos == std::string::npos)
        {
            return new TreeNode(std::stoi(s));
        }

        auto val = std::stoi(s.substr(0, pos));
        auto node = new TreeNode(val);

        for (auto i = pos, b = 0; i < std::size(s); i++)
        {
            if (s[i] == '(')
            {
                b++;
            }
            else if (s[i] == ')')
            {
                b--;
            }

            if (b == 0)
            {
                node->left = deserialize(s.substr(pos + 1, i - pos - 1));
                pos = i + 1;
                break;
            }
        }

        if (pos == std::size(s))
        {
            return node;
        }

        node->right = deserialize(s.substr(pos + 1, std::size(s) - pos - 2));

        return node;
    }
};