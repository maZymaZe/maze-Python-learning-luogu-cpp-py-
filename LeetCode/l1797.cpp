class AuthenticationManager {
public:
    unordered_map<string,int> mp;
    int ttl;
    AuthenticationManager(int timeToLive) {
        ttl=timeToLive;
    }
    
    void generate(string tokenId, int currentTime) {
        mp[tokenId] = currentTime;
    }
    
    void renew(string tokenId, int currentTime) {
        if(mp.count(tokenId)){
            int pw=mp[tokenId];
            if(pw+ttl>currentTime){
                mp[tokenId]=currentTime;
            }
        }
    }
    
    int countUnexpiredTokens(int currentTime) {
        int cnt=0;
        for(auto it=mp.begin(); it!=mp.end();){
            int pw=it->second;
            if(pw+ttl>currentTime)cnt++,++it;
            else {
                it=mp.erase(it);
            }
        }
        return cnt;
    }
};

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * AuthenticationManager* obj = new AuthenticationManager(timeToLive);
 * obj->generate(tokenId,currentTime);
 * obj->renew(tokenId,currentTime);
 * int param_3 = obj->countUnexpiredTokens(currentTime);
 */