#include<cstdio>
int t,tot,n,T,ans;
int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        ans=0,tot=0;
        for(int i=1;i<=n;i++){
            scanf("%d",&t);
            if(t==0)ans++,t++;
            tot+=t;
        }
        if(tot==0)ans++;
        printf("%d\n",ans);
    }
    return 0;
}