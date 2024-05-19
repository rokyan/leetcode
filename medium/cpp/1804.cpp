// https://leetcode.com/problems/implement-trie-ii-prefix-tree/description/

class Trie
{
private:
    struct Node
    {
        Node()
            : end_here{ 0 }
        {
            next.resize(26);
            cnt.resize(26);
        }

        std::vector<std::unique_ptr<Node>> next;
        std::vector<int> cnt;
        int end_here;
    };

public:
    Trie()
        : root{ std::make_unique<Node>() }
    {        
    }
    
    void insert(const std::string& word)
    {
        auto ptr = root.get();

        for (auto c : word)
        {
            const auto code = c - 'a';

            if (ptr->next[code] == nullptr)
            {
                ptr->next[code] = std::make_unique<Node>();
            }

            ptr->cnt[code]++;
            ptr = ptr->next[code].get();
        }

        ptr->end_here++;
    }
    
    int countWordsEqualTo(const std::string& word)
    {
        auto ptr = root.get();

        for (auto c : word)
        {
            const auto code = c - 'a';

            if (ptr->next[code] == nullptr)
            {
                return 0;
            }

            ptr = ptr->next[code].get();
        }

        return ptr->end_here;
    }
    
    int countWordsStartingWith(const std::string& prefix)
    {
        auto ptr = root.get();
        auto res = 0;

        for (auto c : prefix)
        {
            const auto code = c - 'a';

            if (ptr->next[code] == nullptr)
            {
                return 0;
            }

            res = ptr->cnt[code];
            ptr = ptr->next[code].get();
        }

        return res;
    }
    
    void erase(const std::string& word)
    {
        erase_impl(word, root.get());
    }

private:
    void erase_impl(const std::string& word, Node* ptr, std::size_t pos = 0)
    {
        if (pos == std::size(word))
        {
            ptr->end_here--;
        }
        else
        {
            const auto code = word[pos] - 'a';

            erase_impl(word, ptr->next[code].get(), pos + 1);

            if (ptr->cnt[code]-- == 1)
            {
                ptr->next[code].reset();
            }
        }
    }

private:
    std::unique_ptr<Node> root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * int param_2 = obj->countWordsEqualTo(word);
 * int param_3 = obj->countWordsStartingWith(prefix);
 * obj->erase(word);
 */