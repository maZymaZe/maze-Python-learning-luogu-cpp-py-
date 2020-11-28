class Solution {
public:
    long long m,c[100002],n,t[100002],tot,ans=0;
    long long lowbit(long long x) { return x&-x;}
    void insert(long long x){
        while(x<m){
            c[x]++;
            x+= lowbit(x);
        }
    }
    long long query(long long x){
        long long ret=0;
        while(x){
            ret+=c[x];
            x-=lowbit(x);
        }
        return ret;
    }
    int reversePairs(vector<int>& nums) {
        n=nums.size();m=n*2+1;
        for(int i=0;i<n;i++){
            t[i+1]=nums[i];
            t[i+1+n]=(long long)2*nums[i];
        }
        sort(t+1,t+1+2*n);
        tot=unique(t+1,t+1+2*n)-t;
        for(int i=n-1;i>=0;i--){
            ans+=query(lower_bound(t+1,t+1+tot,nums[i])-t-1);
            insert(lower_bound(t+1,t+1+tot,(long long)nums[i]*2)-t);
        }
        return ans;
    }
};