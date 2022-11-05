// 208. Implement Trie (Prefix Tree)

class Trie
{
private:
    static constexpr std::size_t SIZE = 26;
    
    struct Node
    {
        Node()
        {
            children.resize(SIZE);
            is_word_end = false;
        }
        
        std::vector<std::unique_ptr<Node>> children;
        bool is_word_end;
    };
    
public:
    Trie()
    {
        root = std::make_unique<Node>();
    }
    
    void insert(std::string word)
    {
        auto node = root.get();
        
        for (std::size_t pos = 0; pos < std::size(word); pos++)
        {
            const auto child_idx = word[pos] - 'a';
            
            if (node->children[child_idx] == nullptr)
            {
                node->children[child_idx] = std::make_unique<Node>();
            }
            
            node = node->children[child_idx].get();
        }
        
        node->is_word_end = true;
    }
    
    bool search(std::string word)
    {
       auto node = root.get();
        
        for (std::size_t pos = 0; pos < std::size(word); pos++)
        {
            const auto child_idx = word[pos] - 'a';
            
            if (node->children[child_idx] == nullptr)
            {
                return false;
            }
            
            node = node->children[child_idx].get();
        }
        
        return node->is_word_end;
    }
    
    bool startsWith(string prefix)
    {
       auto node = root.get();
        
        for (std::size_t pos = 0; pos < std::size(prefix); pos++)
        {
            const auto child_idx = prefix[pos] - 'a';
            
            if (node->children[child_idx] == nullptr)
            {
                return false;
            }
            
            node = node->children[child_idx].get();
        }
        
        return true;  
    }
    
private:
    std::unique_ptr<Node> root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */