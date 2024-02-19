// https://leetcode.com/problems/design-a-file-sharing-system/description/

class FileSharing
{
private:
    class id_generator
    {
    public:
        id_generator()
            : next_free_id{ 1 }
        {}

        int get()
        {
            if (!free_ids.empty())
            {
                const auto id = *std::cbegin(free_ids);
                free_ids.erase(std::cbegin(free_ids));
                return id;
            }

            return next_free_id++;
        }

        void free(int id)
        {
            if (id == next_free_id - 1)
            {
                next_free_id--;
            }
            else
            {
                free_ids.insert(id);
            }
        }

    private:
        std::set<int> free_ids;
        int next_free_id;
    };

public:
    FileSharing(int m)
    {
        
    }
    
    int join(std::vector<int> ownedChunks)
    {
        const auto id = gen.get();

        chunks.emplace(id, ownedChunks);

        for (auto cid : ownedChunks)
        {
            owners[cid].insert(id);
        }

        return id;
    }
    
    void leave(int userID)
    {
        const auto& ownedChunks = chunks[userID];

        for (auto c : ownedChunks)
        {
            owners[c].erase(userID);
        }

        chunks.erase(userID);

        gen.free(userID);
    }
    
    std::vector<int> request(int userID, int chunkID)
    {
        auto chunks_for_user = std::vector<int>(std::cbegin(owners[chunkID]), std::cend(owners[chunkID]));

        if (!chunks_for_user.empty())
        {
            chunks[userID].push_back(chunkID);
            owners[chunkID].insert(userID);
        }

        return chunks_for_user;
    }

private:
    id_generator gen;
    std::unordered_map<int, std::vector<int>> chunks;
    std::unordered_map<int, std::set<int>> owners;
};

/**
 * Your FileSharing object will be instantiated and called as such:
 * FileSharing* obj = new FileSharing(m);
 * int param_1 = obj->join(ownedChunks);
 * obj->leave(userID);
 * vector<int> param_3 = obj->request(userID,chunkID);
 */