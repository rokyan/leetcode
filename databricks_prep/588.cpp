class FileSystem
{
private:
    struct Node
    {
    public:
        enum class Type { File, Directory };

    public:
        Node(std::string name, Type type = Type::Directory)
            : name{std::move(name)}
            , type{type}
        {}

        std::string name;
        Type type;
        std::string content;
        std::vector<std::unique_ptr<Node>> children;
    };

public:
    FileSystem()
        : root{std::make_unique<Node>("/")}
    {
        
    }
    
    std::vector<std::string> ls(const std::string& path)
    {
        const auto tokens = splitPath(path);

        auto ptr = root.get();

        for (auto id = 0; id < std::size(tokens); id++)
        {
            for (auto i = 0; i < std::size(ptr->children); i++)
            {
                if (ptr->children[i]->name == tokens[id])
                {
                    ptr = ptr->children[i].get();
                    break;
                }
            }           
        }

        if (ptr->type == Node::Type::File)
        {
            return {ptr->name};
        }

        std::vector<std::string> names(std::size(ptr->children));

        for (auto id = 0; id < std::size(ptr->children); id++)
        {
            names[id] = ptr->children[id]->name;
        }

        std::ranges::sort(names);

        return names;
    }
    
    void mkdir(const std::string& path)
    {
        const auto tokens = splitPath(path);

        auto ptr = root.get();

        for (auto id = 0; id < std::size(tokens); id++)
        {
            auto exists = false;

            for (auto i = 0; i < std::size(ptr->children); i++)
            {
                if (ptr->children[i]->name == tokens[id])
                {
                    ptr = ptr->children[i].get();
                    exists = true;
                    break;
                }
            }

            if (!exists)
            {
                ptr->children.push_back(std::make_unique<Node>(tokens[id]));
                ptr = ptr->children.back().get();
            }
        }
    }
    
    void addContentToFile(const std::string& filePath, const std::string& content)
    {
        const auto tokens = splitPath(filePath);

        auto ptr = root.get();

        for (auto id = 0; id + 1 < std::size(tokens); id++)
        {
            for (auto i = 0; i < std::size(ptr->children); i++)
            {
                if (ptr->children[i]->name == tokens[id])
                {
                    ptr = ptr->children[i].get();
                    break;
                }
            }           
        }

        auto exists = false;

        for (auto i = 0; i < std::size(ptr->children); i++)
        {
            if (ptr->children[i]->name == tokens.back())
            {
                ptr = ptr->children[i].get();
                exists = true;
                break;
            }
        }

        if (!exists)
        {
            ptr->children.push_back(std::make_unique<Node>(tokens.back(), Node::Type::File));
            ptr = ptr->children.back().get();
        }

        ptr->content += content;
    }
    
    std::string readContentFromFile(const std::string& filePath)
    {
        const auto tokens = splitPath(filePath);

        auto ptr = root.get();

        for (auto id = 0; id < std::size(tokens); id++)
        {
            for (auto i = 0; i < std::size(ptr->children); i++)
            {
                if (ptr->children[i]->name == tokens[id])
                {
                    ptr = ptr->children[i].get();
                    break;
                }
            }           
        }

        return ptr->content;
    }

private:
    std::vector<std::string> splitPath(const std::string& path)
    {
        std::vector<std::string> tokens;

        for (auto c : path)
        {
            if (c == '/')
            {
                tokens.push_back(std::string{});
            }
            else
            {
                tokens.back().push_back(c);
            }
        }

        return tokens;
    }

private:
    std::unique_ptr<Node> root;
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * vector<string> param_1 = obj->ls(path);
 * obj->mkdir(path);
 * obj->addContentToFile(filePath,content);
 * string param_4 = obj->readContentFromFile(filePath);
 */