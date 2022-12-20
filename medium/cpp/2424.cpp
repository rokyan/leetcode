// https://leetcode.com/problems/longest-uploaded-prefix/description/

class LUPrefix
{
public:
    LUPrefix(int n)
    {
        markers.resize(n);
    }
    
    void upload(int video)
    {
        markers[video - 1]++;

        while (len < std::size(markers) && markers[len])
        {
            len++;
        }
    }
    
    int longest()
    {
        return len;
    }

private:
    int len = 0;
    std::vector<char> markers;
};

/**
 * Your LUPrefix object will be instantiated and called as such:
 * LUPrefix* obj = new LUPrefix(n);
 * obj->upload(video);
 * int param_2 = obj->longest();
 */