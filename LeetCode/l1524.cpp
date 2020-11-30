sxclass Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int o=0,e=1,ans=0,sum=0,l=arr.size();
        int mod=1e9+7;
        for(int i=0;i<l;i++){
            sum+=arr[i];
            ans=(ans+((sum%2==0)?o:e))%mod;
            if(sum%2==0)e++;
            else o++;
        }
        return ans;
    }
};