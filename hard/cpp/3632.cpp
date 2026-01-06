// https://leetcode.com/problems/subarrays-with-xor-at-least-k/description/

class Solution
{
private:
    class trie
    {
    private:
        constexpr static int BITS_LEN = 30;
    
        struct node
        {
            node()
                : children(2)
            {}

            std::vector<node*> children;
            int count = 0;
        };

    public:
        trie()
            : root{new node}
        {}

        void insert(int x)
        {
            auto cur = root;

            for (int i = BITS_LEN; i >= 0; i--)
            {
                const int bit = (x & (1 << i)) != 0;

                if (cur->children[bit] == nullptr)
                {
                    cur->children[bit] = new node;
                }

                cur = cur->children[bit];
                cur->count++;
            }
        }

        int count(int x, int k)
        {
            auto cur = root;
            int res = 0;

            for (int i = BITS_LEN; i >= 0 && cur != nullptr; i--)
            {
                const int x_bit = (x & (1 << i)) != 0;
                const int k_bit = (k & (1 << i)) != 0;

                if (k_bit == 0)
                {
                    if (cur->children[x_bit ^ 1] != nullptr)
                    {
                        res += cur->children[x_bit ^ 1]->count;
                    }

                    if (cur->children[x_bit] != nullptr)
                    {
                        cur = cur->children[x_bit];
                    }
                    else
                    {
                        cur = nullptr;
                    }
                }
                else
                {
                    if (cur->children[x_bit ^ 1] != nullptr)
                    {
                        cur = cur->children[x_bit ^ 1];
                    }
                    else
                    {
                        cur = nullptr;
                    }
                }
            }

            if (cur != nullptr)
            {
                res += cur->count;
            }

            return res;
        }

    private:
        node* root;
    };

public:
    long long countXorSubarrays(const std::vector<int>& nums, int k)
    {
        long long res = 0;
        int pref_xor = 0;
        trie t;

        t.insert(pref_xor);

        for (int i = 0; i < std::size(nums); i++)
        {
            pref_xor ^= nums[i];
            res += t.count(pref_xor, k);
            t.insert(pref_xor);
        }

        return res;
    }
};