class Twitter {
public:
    unordered_map<int, unordered_set<int>> following;
    unordered_map<int, vector<pair<int, int>>> userTweets;
    int time;

    Twitter() {
        time = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        time++;
        pair<int, int> tweet = {time, tweetId};
        userTweets[userId].push_back(tweet);
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> result;
        
        // Max Heap. Format: {time, tweetId, ownerId, index}
        // C++ priority_queue sorts by the first element (time) by default, descending.
        priority_queue<vector<int>> pq;
        
        // 1. Gather the "Heads" (most recent tweet) from everyone relevant
        
        // A. Add the user themselves
        if (userTweets.count(userId) && !userTweets[userId].empty()) {
            int lastIndex = userTweets[userId].size() - 1;
            auto& t = userTweets[userId][lastIndex];
            pq.push({t.first, t.second, userId, lastIndex});
        }
        
        // B. Add everyone they follow
        if (following.count(userId)) {
            for (int followeeId : following[userId]) {
                if (followeeId == userId) continue;
                
                if (userTweets.count(followeeId) && !userTweets[followeeId].empty()) {
                    int lastIndex = userTweets[followeeId].size() - 1;
                    auto& t = userTweets[followeeId][lastIndex];
                    pq.push({t.first, t.second, followeeId, lastIndex});
                }
            }
        }
        
        // 2. Extract top 10
        while (!pq.empty() && result.size() < 10) {
            // Get the newest tweet currently in the heap
            vector<int> top = pq.top();
            pq.pop();
            
            int time = top[0];
            int tweetId = top[1];
            int ownerId = top[2];
            int index = top[3];
            
            result.push_back(tweetId);
            
            // 3. Replenish the heap
            // If this user has more (older) tweets, add the next one to the heap
            if (index > 0) {
                int nextIndex = index - 1;
                auto& nextTweet = userTweets[ownerId][nextIndex];
                pq.push({nextTweet.first, nextTweet.second, ownerId, nextIndex});
            }
        }
        
        return result;
    }
    
    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */