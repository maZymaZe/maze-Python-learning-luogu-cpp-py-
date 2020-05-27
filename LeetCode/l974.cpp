class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {
        int ans=0,sum=0;
        int mp[10100]={0};
        memset(mp,0,sizeof(mp));
        mp[0]=1;
        for(int i:A){
            sum=(((sum+i)%K)+K)%K;
            ans+=mp[sum];
            mp[sum]++;
        }
        return ans;
    }
};