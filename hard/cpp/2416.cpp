// https://leetcode.com/problems/sum-of-prefix-scores-of-strings/description/

class Solution
{
private:
    class trie
    {
    private:
        struct node
        {
            std::array<node*, 26> next { nullptr };
            int cnt = 0;
        };

    public:
        void add(const std::string& s)
        {
            auto cur = root;

            for (auto pos = 0; pos < std::size(s); pos++)
            {
                const auto c = s[pos] - 'a';

                if (cur->next[c] == nullptr)
                {
                    cur->next[c] = new node;
                }

                cur = cur->next[c];
                cur->cnt++;
            }
        }

        int get(const std::string& s)
        {
            auto sum = 0;            
            auto cur = root;

            for (auto pos = 0; pos < std::size(s); pos++)
            {
                const auto c = s[pos] - 'a';

                cur = cur->next[c];
                sum += cur->cnt;
            }

            return sum;
        }

    private:
        node* root = new node;
    };

public:
    std::vector<int> sumPrefixScores(std::vector<std::string>& words)
    {
        trie t;

        for (const auto& word : words)
        {
            t.add(word);
        }

        std::cout << "#" << std::endl;

        std::vector<int> res;
        res.reserve(std::size(words));

        std::transform(std::begin(words), std::end(words), std::back_inserter(res), [&t](const auto& word) {
            return t.get(word);
        });

        return res;
    }
};