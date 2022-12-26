// https://leetcode.com/problems/design-add-and-search-words-data-structure/description/

class WordDictionary
{
private:
    class Trie
    {
        private:
            struct Node
            {
                std::vector<std::unique_ptr<Node>> next { 26 };
                bool leaf { false };
            };

        public:
            Trie()
            {
                root = std::make_unique<Node>();
            }

            Trie(const Trie&) = delete;
            Trie& operator=(const Trie&) = delete;

            Trie(Trie&&) = default;
            Trie& operator=(Trie&&) = default;

            void add(const std::string& word)
            {
                auto ptr = root.get();

                for (auto pos = 0; pos < std::size(word); pos++)
                {
                    const auto idx = word[pos] - 'a';

                    if (ptr->next[idx] == nullptr)
                    {
                        ptr->next[idx] = std::make_unique<Node>();
                    }

                    ptr = ptr->next[idx].get();
                }

                ptr->leaf = true;
            }

            bool search(const std::string& word) const
            {
                return search_impl(word, root.get());
            }

        private:
            bool search_impl(const std::string& word, Node* ptr, std::size_t pos = 0) const
            {
                if (ptr == nullptr)
                {
                    false;
                }

                if (pos == std::size(word))
                {
                    return ptr->leaf;
                }

                auto found = false;

                if (word[pos] == '.')
                {
                    for (auto idx = 0; idx < 26 && !found; idx++)
                    {
                        if (ptr->next[idx] != nullptr)
                        {
                            found |= search_impl(word, ptr->next[idx].get(), pos + 1);
                        }
                    }
                }
                else
                {
                    if (ptr->next[word[pos] - 'a'] != nullptr)
                    {
                        found = search_impl(word, ptr->next[word[pos] - 'a'].get(), pos + 1);
                    }
                }

                return found;
            }

        private:
            std::unique_ptr<Node> root;
    };

public:
    WordDictionary()
    {
    }
    
    void addWord(std::string word)
    {
        trie.add(word);
    }
    
    bool search(std::string word)
    {
        return trie.search(word);
    }

private:
    Trie trie;
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */