#include<cstdio>
int t[200006],n,k,p,b,c[55],nw=0;
long long ans=0;

int main(){
    scanf("%d%d%d", &n, &k, &p);
    for(int i=1;i<=n;i++){
        scanf("%d%d",&t[i],&b);
        if(b<=p){
            for(int j=i;j>nw;j--)c[t[j]]++;
            nw=i,ans+=c[t[i]]-1;
        }
        else ans+=c[t[i]];
    }
    printf("%lld",ans);
    return 0;
}