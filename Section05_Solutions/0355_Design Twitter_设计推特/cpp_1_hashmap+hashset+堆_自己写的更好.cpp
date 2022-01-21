class Twitter {
    using PII = pair<int, int>;
public:
    unordered_map<int, vector<PII>> tweets; //vector<PII>:{{timeStamp, tweetId}, {}...}
    unordered_map<int, unordered_set<int>> followingLists;
    int timeStamp;
    
    Twitter() {
        timeStamp = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({timeStamp, tweetId});
        timeStamp ++;
    }
    
    vector<int> getNewsFeed(int userId) {
        //每次返回最新的帖子，所以存成默认的大根堆
        //heap: {userId, timeStamp, user}
        priority_queue<vector<int>> heap;
        followingLists[userId].insert(userId);//self
        for (int user : followingLists[userId]) {
            vector<PII>& posts = tweets[user];
            for (int i = 0; i < posts.size(); i++) {
                heap.push({posts[i].first, posts[i].second, user});
            }
        }
        vector<int> res;
        int recentMax = 10;
        while(recentMax-- && !heap.empty()) {
            auto& t = heap.top();
            res.push_back(t[1]); //t[1]: twitterId
            heap.pop(); //注意这步放后面，否则会出错
        }
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        followingLists[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followingLists[followerId].erase(followeeId);
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