#include<cstdio>
const int NMAX=32,INF= 0x3f3f3f3f;
int abs(int x) {return x>0 ? x : -x;}
int n,v,a[NMAX],b[NMAX],ans=INF,ta=0,tb=0,vis[NMAX]={0};
void dfs(int x){
    if(ans==0)return;
    if(ta+tb>=v){
        if(abs(ta-tb)<ans)ans=abs(ta-tb);
    }
    for(int i=x;i<=n;i++){
        if(!vis[i]){
            vis[i]=1;
            ta+=a[i],tb+=b[i];
            dfs(i+1);
            ta-=a[i],tb-=b[i];
            vis[i]=0;
        }
    }

}
int main(){
    scanf("%d%d",&n,&v);
    for(int i=1;i<=n;i++){
        scanf("%d%d",&a[i],&b[i]);
    }
    dfs(1);
    if(ans==INF) printf("-1");
    else printf("%d",ans);
    return 0;
}