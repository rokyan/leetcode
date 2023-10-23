// https://leetcode.com/problems/product-of-two-run-length-encoded-arrays/description/

class Solution
{
public:
    std::vector<std::vector<int>> findRLEArray(std::vector<std::vector<int>>& encoded1, std::vector<std::vector<int>>& encoded2)
    {
        std::vector<std::vector<int>> mult;

        for (auto i = 0, j = 0, len_i = encoded1[0][1], len_j = encoded2[0][1];
            i < std::size(encoded1) && j < std::size(encoded2); )
        {
            const auto len = std::min(len_i, len_j);

            if (!mult.empty() && mult.back()[0] == encoded1[i][0] * encoded2[j][0])
            {
                mult.back()[1] += len;
            }
            else
            {
                mult.push_back({ encoded1[i][0] * encoded2[j][0], len });
            }

            len_i -= len;

            if (len_i == 0)
            {
                i++;
                
                if (i < std::size(encoded1))
                {
                    len_i = encoded1[i][1];
                }
            }

            len_j -= len;

            if (len_j == 0)
            {
                j++;

                if (j < std::size(encoded2))
                {
                    len_j = encoded2[j][1];
                }
            }
        }

        return mult;
    }
};