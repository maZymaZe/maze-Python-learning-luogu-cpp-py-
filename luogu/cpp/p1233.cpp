#include<algorithm>
#include<cstdio>
using namespace std;
struct wood{
    int l,w;
}m[5002];
int ml,mw,n,u[5002]={0},ans=0;
int cmp(const wood&a,const wood&b){
    if(a.l>b.l)return 1;
    else if(a.l==b.l&&a.w>b.w)return 1;
    return 0;
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d%d",&m[i].l,&m[i].w);
    }
    sort(m+1,m+1+n,cmp);
    for(int i=1;i<=n;i++){
        if(u[i]==0){
            mw=m[i].w;
            ml=m[i].l;
            ans++;
            for(int j=i+1;j<=n;j++){
                if(u[j]==0&&m[j].l<=ml&&m[j].w<=mw){
                    u[j]=1;
                    ml=m[j].l;
                    mw=m[j].w;
                }
            }
        }
    }
    printf("%d",ans);
    return 0;
}