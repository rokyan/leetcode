class Solution
{
public:
    int numTilePossibilities(const std::string& tiles)
    {
        std::array<int, 26> freq;
        freq.fill(0);

        for (auto c : tiles)
        {
            freq[c - 'A']++;
        }

        return solve(freq);
    }

private:
    int solve(std::array<int, 26>& freq)
    {
        auto ret = 0;

        for (auto i = 0; i < 26; i++)
        {
            if (freq[i] > 0)
            {
                ret++;
                freq[i]--;
                ret += solve(freq);
                freq[i]++;
            }
        }

        return ret;
    }
};