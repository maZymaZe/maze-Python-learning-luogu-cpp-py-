class Solution {
public:
    bool vis[5000004]={0};
    int countPrimes(int n) {
        int ans=0;
        for(int i=2;i<n;i++){
            if(vis[i]==0){
                for(int j=2*i;j<n;j+=i){
                    vis[j]=1;
                }
            }
        }
        for(int i=2;i<n;i++)ans+=(vis[i]==0);
        return ans;
    }
};