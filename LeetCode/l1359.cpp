class Solution {
public:
    int countOrders(int n) {
        const int mod=1e9+7;
        long long ans=1;
        for(int i=2;i<=n;i++){
            ans=(ans*(2*i)*(2*i-1)/2)%mod;
        }
        return ans;
    }
};