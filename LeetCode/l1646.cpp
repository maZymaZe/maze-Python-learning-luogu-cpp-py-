class Solution {
public:
    int getMaximumGenerated(int n) {
        int a[102]={0};
        a[0]=0;a[1]=1;
        for(int i=2;i<=n;i++){
            if(i%2==0)a[i]=a[i/2];
            else a[i]=a[i/2]+a[i/2+1];
        }
        int ans=0;
        for(int i=1;i<=n;i++)ans=max(ans,a[i]);
        return ans;
    }
};