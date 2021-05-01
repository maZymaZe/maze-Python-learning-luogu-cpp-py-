class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        int n=wall.size();
        unordered_map<long long,int> mp;
        for(auto v:wall){
            long long t=0,l=v.size();
            for(int i=0;i<l-1;i++){
                t+=v[i];
                if(mp.count(t))mp[t]++;
                else mp[t]=1;
            }
        }
        int ans=n;
        for(auto w:mp){
            ans=min(ans,n-w->second);
        }
        return ans;
    }
};