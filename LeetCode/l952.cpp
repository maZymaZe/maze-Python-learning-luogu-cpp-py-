class Solution {
public:
    int ff(int* f,int x){
        if(f[x]==x)return x;
        return f[x]=ff(f,f[x]);
    } 
    int largestComponentSize(vector<int>& A) {
        int cnt[100001]={0},f[100001]={0};
        int n=100000;
        for(int i=1;i<=n;i++)f[i]=i;
        for(int i:A){
            for(int j=2;j<=sqrt(i);j++)
            if(i%j==0){
                f[ff(f,j)]=f[ff(f,i/j)]=f[ff(f,i)];
            }
        }
        int ans=0;
        for(int i:A){
            ans=max(ans,++cnt[ff(f,i)]);
        }
        return ans;
    }
};