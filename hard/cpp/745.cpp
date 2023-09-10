// https://leetcode.com/problems/prefix-and-suffix-search/description/

class trie
{
private:
    struct node
    {
        node(int pos = -1)
            : pos{ pos }
        {
            next.resize(27);
        }

        std::vector<std::unique_ptr<node>> next;
        int pos;
    };

public:
    trie()
        : root{ std::make_unique<node>() }
    {}

    void add(const std::string& word, int pos)
    {
        auto p = root.get();
        auto seen = false;

        for (auto i = 0; i < std::size(word); i++)
        {
            if (word[i] == '#')
            {
                seen = true;

                if (p->next.back() == nullptr)
                {
                    p->next.back() = std::make_unique<node>();
                }

                p = p->next.back().get();
            }
            else
            {
                if (p->next[word[i] -'a'] == nullptr)
                {
                    p->next[word[i] - 'a'] = seen ? std::make_unique<node>(pos) : std::make_unique<node>();
                }

                p = p->next[word[i] - 'a'].get();

                p->pos = std::max(p->pos, pos);
            }
        }
    }

    int find(const std::string& word)
    {
        auto p = root.get();

        for (auto i = 0; i < std::size(word); i++)
        {
            if (word[i] == '#')
            {
                if (p->next.back() == nullptr)
                {
                    return -1;
                }

                p = p->next.back().get();
            }
            else
            {
                if (p->next[word[i] - 'a'] == nullptr)
                {
                    return -1;
                }

                p = p->next[word[i] - 'a'].get();
            }
        }

        return p->pos;
    }

private:
    std::unique_ptr<node> root;
};

class WordFilter
{
public:
    WordFilter(std::vector<std::string>& words)
    {
        for (auto pos = 0; pos < std::size(words); pos++)
        {
            const auto& word = words[pos];

            std::string suff;

            for (auto i = static_cast<int>(std::size(word)) - 1; i >= 0; i--)
            {
                suff = word[i] + suff;
                tr.add(suff + "#" + word, pos);
            }
        }
    }
    
    int f(std::string pref, std::string suff)
    {
        return tr.find(suff + "#" + pref);
    }

private:
    trie tr;
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(pref,suff);
 */