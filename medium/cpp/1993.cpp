// https://leetcode.com/problems/operations-on-tree/description/

class LockingTree
{
public:
    LockingTree(vector<int>& parent)
        : parent(parent)
        , locks(std::size(parent), -1)
    {
        build_tree(parent);
    }
    
    bool lock(int num, int user)
    {
        if (locks[num] != -1)
        {
            return false;
        }

        locks[num] = user;
        return true;
    }
    
    bool unlock(int num, int user)
    {
        if (locks[num] == user)
        {
            locks[num] = -1;
            return true;
        }

        return false;
    }
    
    bool upgrade(int num, int user)
    {
        auto p = num;

        while (p != -1)
        {
            if (locks[p] != -1)
            {
                return false;
            } 

            p = parent[p];
        }

        if (!check(num))
        {
            return false;
        }

        unlock(num);

        locks[num] = user;

        return true;
    }

private:
    void build_tree(const std::vector<int>& parent)
    {
        tree.resize(std::size(parent));

        for (auto v = 0; v < std::size(parent); v++)
        {
            if (parent[v] != -1)
            {
                tree[parent[v]].push_back(v);
            }
        }
    }

    bool check(int v)
    {
        if (locks[v] != -1)
        {
            return true;
        }

        auto res = false;

        for (auto to : tree[v])
        {
            res |= check(to);
        }

        return res;
    }

    void unlock(int v)
    {
        locks[v] = -1;

        for (auto to : tree[v])
        {
            unlock(to);
        }
    }

private:
    std::vector<int> parent;
    std::vector<std::vector<int>> tree;
    std::vector<int> locks;
};

/**
 * Your LockingTree object will be instantiated and called as such:
 * LockingTree* obj = new LockingTree(parent);
 * bool param_1 = obj->lock(num,user);
 * bool param_2 = obj->unlock(num,user);
 * bool param_3 = obj->upgrade(num,user);
 */