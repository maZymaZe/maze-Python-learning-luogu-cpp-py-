#include<cstdio>
#include<queue>
using namespace std;
const int NMAX=1e5+7,MMAX=2e5+7;
int n,m,v[MMAX],nx[MMAX],h[NMAX],d[MMAX],ans[NMAX]={0};
struct pr{
    int a,b;
};
queue<pr> q;
int main(){
    int t1,t2;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        scanf("%d%d",&t1, &t2);
        nx[i] = h[t1];
        h[t1] = i;
        v[i] = t2;
        d[t2]++;
    }
    for(int i=1;i<=n;i++){
        if(!d[i])q.push({i,1}),ans[i]=1;
    }
    while(!q.empty()){
        pr now=q.front();
        q.pop();
        for(int i=h[now.a];i;i=nx[i]){
            d[v[i]]--;
            if(ans[v[i]]<now.b+1)ans[v[i]]=now.b+1;
            if(!d[v[i]])q.push({v[i],ans[v[i]]});
        }
    }
    int res=0;
    for(int i=1;i<=n;i++)
    printf("%d\n",ans[i]);
    return 0;
}