#include<cstdio>
#include<cstring>
const int NMAX = 1e5 + 10;
int n,m,a[NMAX],b[NMAX],v[NMAX];
bool ck(int r){
    int nd=0,cnt=0;
    memset(v,0,sizeof(v));
    for(int i=r;i>=1;i--){
        if(a[i]!=0&&!v[a[i]]){
            nd+=b[a[i]],v[a[i]]=1;cnt++;
        }else if(nd>0)nd--;
    }
    return nd==0&&cnt==m;
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=m;i++)scanf("%d",&b[i]);
    if(!ck(n)){
        printf("-1\n");
        return 0;
    }
    int l=1,r=n,mid;
    while(l<r){
        mid=(l+r)/2;
        if(ck(mid))r=mid;
        else l=mid+1;
    }
    printf("%d\n",r);
    return 0;
}