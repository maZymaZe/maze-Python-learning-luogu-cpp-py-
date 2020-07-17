class Solution {
public:
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        long long ans=0,t1=0,t3=0,ma=0,mi=0,mae=0;
        int l=arr.size();
        const int MOD=1e9+7;
        if(l==0)return 0;
        vector<long long> sum(l+1);
        sum[0]=0;
        for(int i=1;i<=l;i++){
            sum[i]=sum[i-1]+arr[i-1];
            mi=min(mi,sum[i]);
            ma=max(ma,sum[i]);
        }
        for(int i=1;i<=l;i++){
           mae=max((long long)arr[i-1],mae+arr[i-1]);
           t1=max(t1,mae);
        }
        ans=max(ans,t1);
        if(k==1)return ans;
   
        t3=max(sum[l]-mi+ma,(long long)0);
        ans=max(ans,t3);
        if(sum[l]>0)ans=max(ans,t3+(k-2)*sum[l]);
        return ans%MOD;
    }
};