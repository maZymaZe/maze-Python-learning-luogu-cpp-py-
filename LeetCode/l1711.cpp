class Solution {
public:
    int countPairs(vector<int>& deliciousness) {
        unordered_map<int,int> mp;
        
        int l=deliciousness.size();
        
        for(int i = 0; i < l; i++){
            mp[deliciousness[i]]++;
        }
        sort(deliciousness.begin(),deliciousness.end());
        auto ite=unique(deliciousness.begin(),deliciousness.end());
        int p=1;
        long long ans=0,mod=1e9+7;
        for(int i=1;i<=22;i++){
            for(auto it=deliciousness.begin();it!=ite;++it){
                if(*it<=p/2){
                    if(*it==p/2&&p!=1){
                        (ans+=(long long)(mp[*it])*(mp[*it]-1)/2)%=mod;
                    }else{
                        (ans+=(long long)(mp[*it])*(mp[p-*it]))%=mod;
                    }
                }
            }
            p<<=1;
        }
        return ans;
    }
};