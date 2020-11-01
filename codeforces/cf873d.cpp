#include<cstdio>
const int MAXN = 1e5 + 10;
int n, k, a[MAXN];
void dfs(int l,int r){
    if((!k)||l+1>=r)return;
    int mid=(l+r)/2;
    k-=2;
    int t=a[mid-1];
    a[mid-1]=a[mid];
    a[mid]=t;
    dfs(l,mid),dfs(mid,r);
}
int main(){
    scanf("%d%d",&n,&k);
    if(!(k&1)){
        printf("-1");
        return 0;
    }
    for(int i=0;i<n;i++){
        a[i]=i+1;
    }
    k--;
    dfs(0,n);
    if(k!=0){
        printf("-1");
        return 0;
    }
    for(int i=0;i<n;i++)printf("%d ",a[i]);
    return 0;
}