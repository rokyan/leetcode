// https://leetcode.com/problems/find-k-pairs-with-smallest-sums/description/

class Solution
{
private:
    struct state
    {
        state(int val, int p1, int p2)
            : val{ val }
            , p1{ p1 }
            , p2{ p2 }
        {}

        int val = 0;
        int p1 = 0;
        int p2 = 0;
    };

public:
    std::vector<std::vector<int>> kSmallestPairs(std::vector<int>& nums1, std::vector<int>& nums2, int k)
    {
        auto comp = [](const state& s1, const state& s2)
        {
            return s1.val > s2.val;
        };

        std::priority_queue<state, std::vector<state>, decltype(comp)> pq;
        pq.push({nums1[0] + nums2[0], 0, 0});

        std::vector<std::vector<int>> res;
        res.reserve(k);

        std::set<std::pair<int, int>> probe;
        probe.insert({0, 0});

        while (k-- && !pq.empty())
        {
            const auto s = pq.top();
            pq.pop();
            res.push_back({ nums1[s.p1], nums2[s.p2] });

            if (s.p1 + 1 < std::size(nums1) && probe.find({s.p1 + 1, s.p2}) == std::end(probe))
            {
                probe.insert({s.p1 + 1, s.p2});
                pq.push({nums1[s.p1 + 1] + nums2[s.p2], s.p1 + 1, s.p2});
            }

            if (s.p2 + 1 < std::size(nums2) && probe.find({s.p1, s.p2 + 1}) == std::end(probe))
            {
                probe.insert({s.p1, s.p2 + 1});
                pq.push({nums1[s.p1] + nums2[s.p2 + 1], s.p1, s.p2 + 1});
            }
        }

        return res;
    }
};