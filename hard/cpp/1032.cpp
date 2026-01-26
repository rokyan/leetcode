// https://leetcode.com/problems/stream-of-characters/description/

class StreamChecker
{
private:
    class trie final
    {
    private:
        struct node
        {
            node()
                : next(26)
            {}

            bool leaf{false};
            std::vector<std::unique_ptr<node>> next;
        };

    public:
        trie()
            : root{std::make_unique<node>()}
        {}

        void add(std::string word)
        {
            node* cur = root.get();

            for (auto c : word)
            {
                const int code = c - 'a';

                if (cur->next[code] == nullptr)
                {
                    cur->next[code] = std::make_unique<node>();
                }

                cur = cur->next[code].get();
            }

            cur->leaf = true;
        }

        bool find(const std::deque<char>& dq)
        {
            node* cur = root.get();

            for (int i = dq.size() - 1; i >= 0; i--)
            {
                const int code = dq[i] - 'a';

                if (cur->next[code] == nullptr)
                {
                    return false;
                }

                cur = cur->next[code].get();

                if (cur->leaf)
                {
                    return true;
                }
            }

            return false;
        }

    private:
        std::unique_ptr<node> root;
    };

    static constexpr unsigned max_word_len = 200;

public:
    StreamChecker(const std::vector<std::string>& words)
    {
        for (std::string word : words)
        {
            std::ranges::reverse(word);
            t.add(std::move(word));
        }
    }
    
    bool query(char letter)
    {
        dq.push_back(letter);

        if (dq.size() > max_word_len)
        {
            dq.pop_front();
        }

        return t.find(dq);
    }

private:
    trie t;
    std::deque<char> dq;
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */