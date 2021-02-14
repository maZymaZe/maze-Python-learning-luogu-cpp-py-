class Solution {
public:
    int waysToChange(int n) {
        const int MOD=1e9+7;
        n-=n%5;
        int ans=0;
        for(int i=0;i<=n;i+=5){
            ans+=(long long)((i/25)+1)*(((n-i)/10)+1)%MOD;
            ans%=MOD;
        }
        return ans;
    }
};