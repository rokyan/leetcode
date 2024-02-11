// https://leetcode.com/problems/find-pattern-in-infinite-stream-i/

/**
 * Definition for an infinite stream.
 * class InfiniteStream {
 * public:
 *     InfiniteStream(vector<int> bits);
 *     int next();
 * };
 */
class Solution
{
public:
    int findPattern(InfiniteStream* stream, vector<int>& pattern)
    {
        std::deque<int> cur;

        for (auto pos = 0; ; pos++)
        {
            cur.push_back(stream->next());

            if (std::size(cur) > std::size(pattern))
            {
                cur.pop_front();
            }

            if (std::equal(std::cbegin(cur), std::cend(cur), std::cbegin(pattern), std::cend(pattern)))
            {
                return pos - std::size(pattern) + 1;
            }
        }

        return -1;
    }
};