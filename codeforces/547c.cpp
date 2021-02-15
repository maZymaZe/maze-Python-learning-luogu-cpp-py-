#include<cstdio>
#include<vector>
#include<cmath>
using namespace std;
typedef long long ll;
const int NMAX=2e5+10,AMAX=5e5 + 10;
int n,q,a[NMAX],t,prime[AMAX],ink[NMAX][11],tot[AMAX];
bool vis[NMAX],isprime[AMAX];
ll ans=0;
void init(int n){
    isprime[0]=isprime[1]=1;prime[0]=0;
    for(int i=2;i<=n;i++){
        if(!isprime[i])prime[++prime[0]]=i;
        for(int j=1;j<=prime[0]&&i*prime[j]<=n;j++){
            isprime[i*prime[j]]=1;
            if(i%prime[j]==0)break;
        }
    }
}
void query(int x,int op){
    for(int i=0;i<(1<<ink[x][0]);i++){
        int now=1,cnt=0;
        for(int j=1;j<=ink[x][0];j++){
            if(i& (1 << (j - 1)))now*=ink[x][j],cnt++;
        }
        if(cnt&1)ans-=op*tot[now];
        else ans+=op*tot[now];
    }
}
void update(int x, int op){
    for(int i=0;i<(1<<ink[x][0]);i++){
        int now=1;
        for(int j=1;j<=ink[x][0];j++){
            if(i&(1<<(j - 1)))now*=ink[x][j];
        }
        tot[now]+=op;
    }
}
int main(){
    scanf("%d%d",&n,&q);
    init(500000);
    for(int i=1;i<=n;i++){
        scanf("%d",&t);
        int w=sqrt(t);
        for(int j=1;j<=prime[0]&&prime[j]<=w; j++){
            if(t%prime[j]==0){
                ink[i][++ink[i][0]]=prime[j];
                while(t%prime[j]==0)t/=prime[j];
            }
        }
        if(t>1)ink[i][++ink[i][0]]=t;
    }
    while(q--){
        scanf("%d",&t);
        if(!vis[t])query(t,1),update(t,1);
        else update(t,-1),query(t,-1);
        vis[t]^=1;
        printf("%lld\n",ans);
    }
    return 0;
}