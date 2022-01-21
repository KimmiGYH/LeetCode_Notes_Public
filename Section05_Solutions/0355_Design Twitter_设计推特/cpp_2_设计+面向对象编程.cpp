int timeStamp = 0;

class Tweet {
public:
    int id;
    int time;
    Tweet *next;
    
    Tweet(int id) {
        this->id = id;
        this->time = timeStamp ++;
        next = nullptr;
    }
};

class User {
public:
    int id;
    Tweet *tweet;
    unordered_set<int> followingLists;
    
    User(int id) {
        this->id = id;
        tweet = nullptr;
    }
    
    void follow(int followeeId) {
        if (followeeId == id) return;
        followingLists.insert(followeeId);
    }
    
    void unfollow(int followeeId) {
        if (!followingLists.count(followeeId) || followeeId == id) return;
        followingLists.erase(followeeId);
    }
    
    void post(int tweetId) {
        Tweet *newTweet = new Tweet(tweetId);
        newTweet->next = tweet; //新发表的推特插在前面
        tweet = newTweet;
    }    
};

class Twitter {
private:
    unordered_map<int, User*> userMap;
    
    bool contain(int id) {
        return userMap.find(id) != userMap.end();
    }
    
public:
    Twitter() {
        userMap.clear();
    }
    
    void postTweet(int userId, int tweetId) {
        if (!contain(userId)) {
            userMap[userId] = new User(userId);
        }
        
        userMap[userId]->post(tweetId);
    }
    
    vector<int> getNewsFeed(int userId) {
        if (!contain(userId)) return {};
        
        struct Cmp {
            bool operator() (const Tweet *a, const Tweet *b) {
                return a->time < b->time;
            }
        };
        
        priority_queue<Tweet*, vector<Tweet*>, Cmp> heap;
        
        if (userMap[userId]->tweet) {
            heap.push(userMap[userId]->tweet);
        }
        
        for (int followeeId : userMap[userId]->followingLists) {
            if (!contain(followeeId)) {
                continue;
            }
            Tweet *head = userMap[followeeId]->tweet;
            if (head == nullptr) continue;
            heap.push(head);
        }
        
        vector<int> res;
        while(!heap.empty()) {
            Tweet *t = heap.top();
            heap.pop();
            res.push_back(t->id);
            if (res.size() == 10) return res;
            if (t->next) {
                heap.push(t->next);
            }
        }
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        if (!contain(followerId)) {
            userMap[followerId] = new User(followerId);
        }
        userMap[followerId]->follow(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if (!contain(followerId)) return;
        userMap[followerId]->unfollow(followeeId);
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