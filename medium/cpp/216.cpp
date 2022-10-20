class Solution
{
public:
    std::vector<std::vector<int>> combinationSum3(int k, int n)
    {
        std::vector<std::vector<int>> seqs;
        std::vector<int> seq;
        
        for (int mask = 0; mask < (1 << 9); mask++)
        {
            auto cnt = 0;
            auto sum = 0;
            
            seq.clear();
            
            for (int bit = 0; bit < 9; bit++)
            {
                if (mask & (1 << bit))
                {
                    cnt++;
                    sum += bit + 1;
                    seq.push_back(bit + 1);
                }
            }
            
            if (cnt == k && sum == n)
            {
                seqs.push_back(seq);
            }
        }
        
        return seqs;
    }
};