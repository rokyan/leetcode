// https://leetcode.com/problems/synonymous-sentences/description/

class Solution
{
private:
    class Dsu
    {
    public:
        Dsu(int n)
        {
            parent.resize(n);
            std::iota(std::begin(parent), std::end(parent), 0);

            size.resize(n, 1);
        }

        int find(int v)
        {
            if (v == parent[v])
            {
                return v;
            }

            return (parent[v] = find(parent[v]));
        }

        void un(int u, int v)
        {
            u = find(u);
            v = find(v);

            if (u != v)
            {
                if (size[u] > size[v])
                {
                    std::swap(u, v);
                }

                parent[u] = v;
                size[v] += size[u];
            }
        }

    private:
        std::vector<int> parent;
        std::vector<int> size;
    };

public:
    std::vector<std::string> generateSentences(std::vector<std::vector<std::string>>& synonyms, std::string text)
    {
        std::map<std::string, int> enumerated;

        for (const auto& syn_pair : synonyms)
        {
            enumerated.emplace(syn_pair[0], 0);
            enumerated.emplace(syn_pair[1], 0);
        }

        auto id = 0;

        for (auto& entry : enumerated)
        {
            entry.second = id++;
        }

        Dsu dsu{ static_cast<int>(std::size(enumerated)) };

        for (const auto& syn_pair : synonyms)
        {
            dsu.un(enumerated[syn_pair[0]], enumerated[syn_pair[1]]);
        }

        auto parts = split(text);

        auto combinations = std::vector<std::vector<std::string>>{};
        auto acc = std::vector<std::string>{};

        gen(parts, 0, acc, combinations, enumerated, dsu);

        std::vector<std::string> res(std::size(combinations));

        for (auto i = 0; i < std::size(combinations); i++)
        {
            res[i] = join(combinations[i]);
        }

        return res;
    }

private:
    static std::vector<std::string> split(const std::string& text)
    {
        std::vector<std::string> parts;

        auto acc = std::string{};

        for (auto c : text)
        {
            if (std::isspace(c))
            {
                parts.push_back(acc);
                acc.clear();
            }
            else
            {
                acc.push_back(c);
            }
        }

        parts.push_back(std::move(acc));

        return parts;
    }

    static std::string join(const std::vector<std::string>& parts)
    {
        auto res = std::string{};

        for (const auto& part : parts)
        {
            if (!res.empty())
            {
                res.push_back(' ');
            }

            res.insert(std::end(res), std::cbegin(part), std::cend(part));
        }

        return res;
    }

    static void gen(const std::vector<std::string>& parts, std::size_t pos, std::vector<std::string>& acc,
        std::vector<std::vector<std::string>>& combinations, std::map<std::string, int>& enumerated, Dsu& dsu)
    {
        if (pos == std::size(parts))
        {
            combinations.push_back(acc);
        }
        else
        {
            if (const auto it = enumerated.find(parts[pos]); it != std::end(enumerated))
            {
                const auto id = it->second;

                for (const auto& [key, value] : enumerated)
                {
                    if (dsu.find(id) == dsu.find(value))
                    {
                        acc.push_back(key);
                        gen(parts, pos + 1, acc, combinations, enumerated, dsu);
                        static_cast<void>(acc.pop_back());
                    }
                }
            }
            else
            {
                acc.push_back(parts[pos]);
                gen(parts, pos + 1, acc, combinations, enumerated, dsu);
                static_cast<void>(acc.pop_back());
            }
        }
    }
};