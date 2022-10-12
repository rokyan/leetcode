// https://leetcode.com/problems/replace-words/

class Solution
{
private:
    static constexpr int ALPH_SIZE = 26;
    
    class trie
    {
    private:
        struct node
        {
            node()
            {
                is_leaf = false;
                next.resize(ALPH_SIZE);
            }
            
            bool is_leaf;
            std::vector<std::unique_ptr<node>> next; 
        };
    
    public:
        trie()
        {
            root = std::make_unique<node>();    
        }
        
        void add(const std::string& word)
        {
            node* ptr = root.get();
            
            for (std::size_t pos = 0; pos < std::size(word); pos++)
            {
                auto c = word[pos] - 'a';
                
                if (ptr->next[c] == nullptr)
                {
                    ptr->next[c] = std::make_unique<node>();
                }
                
                ptr = ptr->next[c].get();
                
                if (ptr->is_leaf)
                {
                    return;
                }
            }
            
            ptr->is_leaf = true;
        }
        
        std::string probe(const std::string& word)
        {
            std::string s;
            node* ptr = root.get();
            
            for (std::size_t pos = 0; pos < std::size(word); pos++)
            {    
                auto c = word[pos] - 'a';
                ptr = ptr->next[c].get();
                
                if (ptr == nullptr)
                {
                    break;
                }
                
                s += word[pos];
                
                if (ptr->is_leaf)
                {
                    return s;
                }
            }
            
            return word;
        }
        
    private:
        std::unique_ptr<node> root;
    };
    
public:
    std::string replaceWords(std::vector<std::string>& dictionary, std::string sentence)
    {
        trie tr;
        
        for (const auto& word : dictionary)
        {
            tr.add(word);
        }
        
        std::string res;
        res.reserve(std::size(sentence));
        
        std::string word;
        
        for (std::size_t pos = 0; pos < std::size(sentence); pos++)
        {
            if (sentence[pos] == ' ')
            {
                res += tr.probe(word);
                res += " ";
                
                word.clear();
            }
            else
            {
                word += sentence[pos];
            }
        }
        
        res += tr.probe(word);
        
        return res;
    }
};