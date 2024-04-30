// https://leetcode.com/problems/implement-magic-dictionary/description/

class MagicDictionary
{
private:
    class Trie
    {
    private:
        struct Node
        {
            Node()
                : leaf{ false }
            {
                next.resize(26);
            }

            bool leaf;
            std::vector<std::unique_ptr<Node>> next;
        };

    public:
        Trie()
            : root{ std::make_unique<Node>() }
        {
        }

        void add(const std::string& s)
        {
            auto ptr = root.get();

            for (auto i = 0; i < std::size(s); i++)
            {
                const auto c = s[i] - 'a';

                if (ptr->next[c] == nullptr)
                {
                    ptr->next[c] = std::make_unique<Node>();
                }

                ptr = ptr->next[c].get();
            }

            ptr->leaf = true;
        }

        bool match(const std::string& s) const
        {
            return match(s, 0, 0, root.get());
        }

    private:
        bool match(const std::string& s, std::size_t pos, unsigned count, Node* ptr) const
        {
            if (pos == std::size(s))
            {
                return count == 1 && ptr->leaf;
            }

            auto res = false;

            for (auto c = 0; c < 26 && !res; c++)
            {
                if (ptr->next[c])
                {
                    if (c == s[pos] - 'a')
                    {
                        res |= match(s, pos + 1, count, ptr->next[c].get());
                    }
                    else if (count == 0)
                    {
                        res |= match(s, pos + 1, count + 1, ptr->next[c].get());
                    }
                }
            }

            return res;
        }

    private:
        std::unique_ptr<Node> root;
    };

public:
    MagicDictionary()
    {
    }
    
    void buildDict(const std::vector<std::string>& dictionary)
    {
        for (const auto& s : dictionary)
        {
            trie.add(s);
        }
    }
    
    bool search(const std::string& searchWord)
    {
        return trie.match(searchWord);
    }

private:
    Trie trie;
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */