// https://leetcode.com/problems/online-election/description/

class TopVotedCandidate
{
public:
    TopVotedCandidate(const std::vector<int>& persons, const std::vector<int>& times)
    {
        const int n = persons.size();

        for (int i = 0; i < n; i++)
        {
            const int personId = persons[i];
            const int time = times[i];
            timesPerPerson[personId].push_back(time);
        }
    }
    
    int q(int t)
    {
        int largestCount = 0;
        int latestCount = -1;
        int id = -1;

        for (const auto& [curId, times] : timesPerPerson)
        {
            if (times.size() < largestCount)
            {
                continue;
            }

            const auto it = std::upper_bound(times.cbegin(), times.cend(), t);

            if (it == times.cbegin())
            {
                continue;
            }

            const int count = std::distance(times.cbegin(), it);

            if (count > largestCount
                || count == largestCount && latestCount < *std::prev(it))
            {
                largestCount = count;
                latestCount = *std::prev(it);
                id = curId;
            }
        }

        return id;
    }

private:
    std::unordered_map<int, std::vector<int>> timesPerPerson;
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */