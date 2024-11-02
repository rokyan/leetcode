// https://leetcode.com/problems/longest-word-with-all-prefixes/description/

class Solution
{
private:
    class trie
    {
    private:
        struct node
        {
            node()
                : is_leaf{ false }
            {
                next.resize(26);
            }

            bool is_leaf;
            std::vector<std::unique_ptr<node>> next;
        };

    public:
        trie()
            : root{ std::make_unique<node>() }
        {}

        void add(const std::string& s)
        {
            auto p = root.get();

            for (auto c : s)
            {
                const auto code = c - 'a';

                if (p->next[code] == nullptr)
                {
                    p->next[code] = std::make_unique<node>();
                }

                p = p->next[code].get();
            }

            p->is_leaf = true;
        }

        bool has_all_pref(const std::string& s)
        {
            auto p = root.get();

            for (auto c : s)
            {
                const auto code = c - 'a';

                if (p->next[code] == nullptr || !p->next[code]->is_leaf)
                {
                    return false;
                }

                p = p->next[code].get();
            }

            return true;
        }

    private:
        std::unique_ptr<node> root;
    };

public:
    string longestWord(const std::vector<std::string>& words)
    {
        trie t;

        for (const auto& word : words)
        {
            t.add(word);
        }

        auto res = std::string{};

        for (const auto& word : words)
        {
            if (t.has_all_pref(word))
            {
                if (std::size(word) > std::size(res) ||
                    std::size(word) == std::size(res) && word < res)
                {
                    res = word;
                }
            }
        }

        return res;
    }
};