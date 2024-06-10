// https://leetcode.com/problems/serialize-and-deserialize-binary-tree/description/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec
{
public:
    // Encodes a tree to a single string.
    std::string serialize(TreeNode* root)
    {
        return serialize_impl(root);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(const std::string& data)
    {
        return deserialize_impl(data);
    }

private:
    std::string serialize_impl(TreeNode* root)
    {
        if (root == nullptr)
        {
            return "";
        }

        return std::to_string(root->val) +
            "[" + serialize_impl(root->left) + "]" +
            "[" + serialize_impl(root->right) + "]";
    }

    TreeNode* deserialize_impl(const std::string& s)
    {
        if (s == "")
        {
            return nullptr;
        }

        auto node = new TreeNode();

        auto val = 0;
        auto pos = 0;
        auto sign = 1;

        while (s[pos] != '[')
        {
            if (s[pos] == '-')
            {
                sign *= -1;
            }
            else
            {
                val = 10 * val + s[pos] - '0';
            }

            pos++;
        }

        node->val = sign * val;

        auto balance = 1;
        auto start = pos++;

        while (balance > 0)
        {
            if (s[pos] == '[')
            {
                balance++;
            }
            else if (s[pos] == ']')
            {
                balance--;
            }

            pos++;
        }

        node->left = deserialize_impl(s.substr(start + 1, pos - start - 2));

        start = pos;

        node->right = deserialize_impl(s.substr(start + 1, std::size(s) - start - 2));

        return node;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));