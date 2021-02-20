class Twitter {
public:
    vector<int> tid,uid;
    unordered_map<int,unordered_set<int>> uf;
    /** Initialize your data structure here. */
    Twitter() {

    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        uid.push_back(userId);
        tid.push_back(tweetId);
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        int l=uid.size(),cnt=0;
        vector<int> ret;
        for(int i=l-1;i>=0;i--){
            if(uid[i]==userId){
                cnt++;
                ret.push_back(tid[i]);
            }
            else if(uf.count(userId)&&uf[userId].count(uid[i])){
                cnt++;
                ret.push_back(tid[i]);
            }
            if(cnt==10)break;
        }
        return ret;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        if(uf.count(followerId)){
            uf[followerId].insert(followeeId);
        }else{
            uf.insert({followerId,unordered_set<int>()});
            uf[followerId].insert(followeeId);
        }
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        if(uf.count(followerId))uf[followerId].erase(followeeId);
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