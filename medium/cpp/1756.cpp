// https://leetcode.com/problems/design-most-recently-used-queue/description/

class MRUQueue
{
public:
    MRUQueue(int n)
    {
        block_size = static_cast<int>(std::sqrt(n)) + (block_size * block_size < n);
        const auto total_blocks = n / block_size + (n % block_size != 0);
        blocks.resize(total_blocks);

        for (auto i = 0; i < n; i++)
        {
            blocks[i / block_size].push_back(i + 1);
        }
    }
    
    int fetch(int k)
    {
        k--;

        auto pos = k / block_size;
        k %= block_size;

        auto it = std::cbegin(blocks[pos]);

        while (k--)
        {
            ++it;
        }

        const auto value = *it;

        blocks[pos].erase(it);

        while (pos + 1 < std::size(blocks))
        {
            blocks[pos].push_back(blocks[pos + 1].front());
            blocks[pos + 1].pop_front();
            pos++;
        }

        blocks.back().push_back(value);

        return value;
    }

private:
    int block_size = 0;
    std::vector<std::list<int>> blocks;
};

/**
 * Your MRUQueue object will be instantiated and called as such:
 * MRUQueue* obj = new MRUQueue(n);
 * int param_1 = obj->fetch(k);
 */