// https://leetcode.com/problems/map-sum-pairs/description/

class MapSum
{
private:
    class Trie
    {
    private:
        struct Node
        {
        public:
            int val { 0 };
            std::vector<std::unique_ptr<Node>> next { 26 };
        };

    public:
        Trie()
        {
            root = std::make_unique<Node>();
        }

        void insert(const std::string& key, int val)
        {
            auto add = val;

            const auto it = vals.find(key);

            if (it != std::end(vals))
            {
                add -= it->second;
                it->second = val;
            }
            else
            {
                vals.emplace(key, val);
            }

            auto node = root.get();

            for (auto c : key)
            {
                const auto offset = c - 'a';

                if (node->next[offset] == nullptr)
                {
                    node->next[offset] = std::make_unique<Node>();
                }

                node = node->next[offset].get();
                node->val += add;
            }
        }

        int sum(const std::string& prefix)
        {
            auto node = root.get();

            for (auto c : prefix)
            {
                const auto offset = c - 'a';

                if (node->next[offset] == nullptr)
                {
                    return 0;
                }

                node = node->next[offset].get();
            }

            return node->val;
        }

    private:
        std::unique_ptr<Node> root;
        std::unordered_map<std::string, int> vals;
    };
    
public:
    MapSum()
    {        
    }
    
    void insert(string key, int val)
    {
        trie.insert(key, val);
    }
    
    int sum(string prefix)
    {
        return trie.sum(prefix);
    }

private:
    Trie trie;
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */