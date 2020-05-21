#include<cstdio>
#include<cstring>
#define MAX 1000007
int dif[MAX],need[MAX],res[MAX],l[MAX],r[MAX],d[MAX];
int n,m;
bool ok(int x){
    memset(dif, 0, sizeof(dif));
    for(int i=1;i<=x;i++){
        dif[l[i]]+=d[i];
        dif[r[i]+1]-=d[i];
    }
    for(int i=1;i<=n;i++){
        need[i]=need[i-1]+dif[i];
        if(need[i]>res[i])return 0;
    }
    return 1;
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%d",&res[i]);
    for(int i=1;i<=m;i++) scanf("%d%d%d",&d[i],&l[i],&r[i]);
    int front=1,back=m;
    if(ok(m)){printf("0");return 0;}
    while(front<back){
        int mid=(front+back)/2;
        if(ok(mid))front=mid+1;
        else back=mid;
       
    }
    printf("-1\n%d",front);
    return 0;
}