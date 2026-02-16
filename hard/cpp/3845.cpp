// https://leetcode.com/problems/maximum-subarray-xor-with-bounded-range/description/

class Solution
{
private:
    class Trie final
    {
    private:
        static constexpr int maxBits = 16;

        struct Node
        {
            Node()
                : next(2)
            {}

            std::vector<std::unique_ptr<Node>> next;
            int passCount{0};
        };

    public:
        Trie()
            : root{new Node}
        {}

        void add(int x)
        {
            Node* ptr = root.get();

            for (int bit = maxBits - 1; bit >= 0; bit--)
            {
                const int idx = (x & (1 << bit)) != 0;

                if (ptr->next[idx] == nullptr)
                {
                    ptr->next[idx] = std::make_unique<Node>();
                }

                ptr = ptr->next[idx].get();
                ptr->passCount++;
            }
        }

        void remove(int x)
        {
            Node* ptr = root.get();

            for (int bit = maxBits - 1; bit >= 0; bit--)
            {
                const int idx = (x & (1 << bit)) != 0;

                if (ptr->next[idx]->passCount-- == 1)
                {
                    ptr->next[idx] = nullptr;
                    return;
                }

                ptr = ptr->next[idx].get();
            }
        }

        int getMax(int x)
        {
            int res = 0;
            Node* ptr = root.get();

            for (int bit = maxBits - 1; bit >= 0; bit--)
            {
                const int value = (x & (1 << bit)) != 0;

                if (ptr->next[value ^ 1] != nullptr)
                {
                    if (value ^ 1)
                    {
                        res |= 1 << bit;
                    }

                    ptr = ptr->next[value ^ 1].get();
                }
                else
                {
                    if (value)
                    {
                        res |= 1 << bit;
                    }

                    ptr = ptr->next[value].get();
                }
            }

            return res;
        }

    private:
        std::unique_ptr<Node> root;
    };

public:
    int maxXor(const std::vector<int>& nums, int k)
    {
        const int n = nums.size();

        std::multiset<int> subarr;

        std::vector<int> pref(n + 1);

        Trie trie;
        trie.add(0);

        int res = 0;

        for (int l = 0, r = 0, last = 0; r < n; r++)
        {
            subarr.insert(nums[r]);

            pref[r + 1] = nums[r] ^ pref[r];
            trie.add(pref[r + 1]);

            while (l <= r && *subarr.rbegin() - *subarr.begin() > k)
            {
                subarr.erase(subarr.find(nums[l++]));
            }

            if (l == r + 1)
            {
                continue;
            }

            while (last < l)
            {
                trie.remove(pref[last++]);
            }

            res = std::max(res, pref[r + 1] ^ trie.getMax(pref[r + 1]));
        }

        return res;
    }
};