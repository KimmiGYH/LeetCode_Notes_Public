using PII = pair<int, int>;

class Twitter {
public:
    unordered_map<int, vector<PII>> tweets; //vector<PII>:{timeStamp, tweetId}
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
        //heap: {userId, timeStamp, pointer, person}
        priority_queue<vector<int>> heap;
        followingLists[userId].insert(userId);//self
        //所有关注的人
        for (int person : followingLists[userId]) {
            vector<PII>& posts = tweets[person];
            if (posts.size()) {
                int i = posts.size() - 1;
                heap.push({posts[i].first, posts[i].second, i, person});
            }
        }
        
        vector<int> res;
        int recentMax = 10;
        while(recentMax-- && heap.size()) {// !heap.empty()
            auto t = heap.top();
            heap.pop();
            res.push_back(t[1]); //t[1]: twitterId
            int j = t[2];
            if (j) {
                j--;
                int person = t[3];
                vector<PII>& posts = tweets[person];
                heap.push({posts[j].first, posts[j].second, j, person});
            }
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