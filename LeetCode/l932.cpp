class Solution {
public:
    unordered_map<int,vector<int>> mp;
    vector<int> rc(int N){
        vector<int> ans(N,0);
        int t=0;
        if(mp.count(N))return mp[N];
        if(N!=1){
            for(auto x:rc((N+1)/2)){
                ans[t++]=2*x-1;
            }
            for(auto x:rc(N/2)){
                ans[t++]=2*x;
            }
        }else ans[0]=1;
        mp[N]=ans;
        return ans;
    }
    vector<int> beautifulArray(int n) {
        return rc(n);
    }
};