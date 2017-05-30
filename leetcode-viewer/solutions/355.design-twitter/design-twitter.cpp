class Twitter {
public:
    /** Initialize your data structure here. */
    Twitter() {
        timestamp=0;
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        tm[userId].push_back(tweet(timestamp, tweetId));
        timestamp++;
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        
        priority_queue<tweet, vector<tweet>, Compare> q;
        int n=10;
        vector<int> res;
        
        for(auto x : fm[userId]) {
            for(auto y : tm[x]) {
                q.push(y);
            }
        }
        for(auto x : tm[userId]) {
            q.push(x);
        }
        
        
        
        while(n>0 && !q.empty()) {
            tweet cur=q.top();
            q.pop();
            res.push_back(cur.id);
            n--;
        }
        
        return res;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        if (followerId != followeeId)
            fm[followerId].insert(followeeId);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        fm[followerId].erase(followeeId);
    }
private:
    struct tweet {
        int t;
        int id;
        tweet(int x, int y): t(x), id(y) {}
    };
    class Compare
    {
        public:
        bool operator() (tweet a, tweet b) {
            return a.t < b.t;
        }
    };
    unordered_map<int, unordered_set<int>> fm; //follower set<followee>
    unordered_map<int, vector<tweet>> tm; //userid {timestamp, tweetid}
    int timestamp;
    

};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter obj = new Twitter();
 * obj.postTweet(userId,tweetId);
 * vector<int> param_2 = obj.getNewsFeed(userId);
 * obj.follow(followerId,followeeId);
 * obj.unfollow(followerId,followeeId);
 */