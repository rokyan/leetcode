// https://leetcode.com/problems/design-file-system/description/

class FileSystem
{
private:
    struct Node
    {
        Node(int value = 0)
            : value{ value }
        {}

        int value;
        std::unordered_map<std::string, std::unique_ptr<Node>> children;
    };

public:
    FileSystem()
        : root{ std::make_unique<Node>() }
    {        
    }
    
    bool createPath(const std::string& path, int value)
    {
        const auto items = split(path);
        auto parent = get(items, static_cast<int>(std::size(items)) - 1);

        if (parent == nullptr)
        {
            return false;
        }

        if (const auto it = parent->children.find(items.back()); it != std::end(parent->children))
        {
            return false;
        }

        parent->children.emplace(items.back(), std::make_unique<Node>(value));
        return true;
    }
    
    int get(const std::string& path)
    {
        const auto items = split(path);
        auto node = get(items, std::size(items));
        return node == nullptr ? -1 : node->value;  
    }

private:
    Node* get(const std::vector<std::string>& path, int len)
    {
        auto ptr = root.get();

        for (auto i = 0; i < len; i++)
        {
            if (const auto it = ptr->children.find(path[i]); it != std::end(ptr->children))
            {
                ptr = it->second.get();
            }
            else
            {
                return nullptr;
            }
        }

        return ptr;
    }

private:
    std::vector<std::string> split(const std::string& path)
    {
        std::vector<std::string> items;
        std::string acc;

        for (auto i = 1; i < std::size(path); i++)
        {
            if (path[i] == '/')
            {
                items.push_back(acc);
                acc.clear();
            }
            else
            {
                acc.push_back(path[i]);
            }
        }

        items.push_back(acc);

        return items;
    }

private:
    std::unique_ptr<Node> root;
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * bool param_1 = obj->createPath(path,value);
 * int param_2 = obj->get(path);
 */