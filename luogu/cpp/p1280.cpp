#include<cstdio>
#include<algorithm>
using namespace std;
int dp[10005],n,k,mp[10005],w,qf[10005],tot=0,ans,m[10005];
struct tak{
    int b,e;
}t[10005];
int cmp(const tak&aa,const tak&bb){
    return aa.b<bb.b;
}
int fr(int nw){
    if(nw>n)return 0;
    else if(nw==n)
            if(qf[n])return dp[n]=0;
            else return dp[n]=1;
    if(dp[nw]!=-1)return dp[nw];
    else{
        if(mp[nw]==0&&nw+1<=n){
            dp[nw+1]=fr(nw+1);
            return dp[nw]=1+dp[nw+1];
        }
        else{
            int mx=0,p=qf[nw];
            while (t[p].b==nw)
            {
                int g=fr(t[p].e+1);
                if(mx<g)mx=g;
                p++;
            }
            return dp[nw]=mx;
        }
    }
}
int main(){
    scanf("%d%d",&n,&k);
    for(int i=1;i<=k;i++){
        scanf("%d%d",&t[i].b,&w);
        t[i].e=t[i].b+w-1;
        mp[t[i].b]++;//mp[t[i].e+1]--;
    }
    sort(t+1,t+1+k,cmp);
    for(int i=1;i<=k;i++){
        if(qf[t[i].b]==0)qf[t[i].b]=i;
    }
    for(int i=1;i<=n;i++){
        dp[i]=-1;
       // tot+=mp[i];
      //  m[i]=tot;
    }
    for(int i=n;i>=1;i--)fr(i);
    
    printf("%d",dp[1]);
    return 0;
}

