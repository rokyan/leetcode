// https://leetcode.com/problems/design-twitter/

class Twitter
{
private:
    static constexpr auto max_tweets_to_store = 10;

public:
    Twitter()
    {
    }
    
    void postTweet(int userId, int tweetId)
    {
        tweets[userId].push_back({ id--, tweetId });

        if (std::size(tweets[userId]) > max_tweets_to_store)
        {
            tweets[userId].erase(std::cbegin(tweets[userId]));
        }
    }
    
    std::vector<int> getNewsFeed(int userId)
    {
        std::priority_queue<std::pair<int, int>> heap;

        auto add_all = [&heap](const auto& tweets)
        {
            for (const auto& tweet : tweets)
            {
                heap.push(tweet);

                if (std::size(heap) > max_tweets_to_store)
                {
                    heap.pop();
                }
            }
        };

        add_all(tweets[userId]);

        for (auto id : followers[userId])
        {
            add_all(tweets[id]);
        }

        std::vector<int> feed;

        while (!heap.empty())
        {
            feed.push_back(heap.top().second);
            heap.pop();
        }

        std::reverse(std::begin(feed), std::end(feed));

        return feed;
    }
    
    void follow(int followerId, int followeeId)
    {
        followers[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId)
    {
        followers[followerId].erase(followeeId);
    }

private:
    std::unordered_map<int, std::unordered_set<int>> followers;
    std::unordered_map<int, std::list<std::pair<int, int>>> tweets;
    int id = 0;
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */