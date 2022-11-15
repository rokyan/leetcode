// https://leetcode.com/problems/letter-tile-possibilities/

class Solution
{
public:
    int numTilePossibilities(std::string tiles)
    {       
        std::sort(std::begin(tiles), std::end(tiles));
        
        std::unordered_set<std::string> unique_combinations;
        
        do
        {
            for (int mask = 1; mask < (1 << (std::size(tiles))); mask++)
            {
                std::string combination;
                combination.reserve(std::size(tiles));

                for (int bit = 0; bit < std::size(tiles); bit++)
                {
                    if ((1 << bit) & mask)
                    {
                        combination += tiles[bit];
                    }
                }

                unique_combinations.insert(combination);
            }
        }
        while (std::next_permutation(std::begin(tiles), std::end(tiles)));
               
        return static_cast<int>(std::size(unique_combinations));
    }
};