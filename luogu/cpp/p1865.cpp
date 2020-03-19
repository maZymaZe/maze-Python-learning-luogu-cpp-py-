#include<cstdio>
int n,m,l,r,s[1000002],f[1000002],tot=0;
int main(){
    scanf("%d%d",&n,&m);
    for(int i=2;i<=m;i++){
        if(f[i]==0){
            f[i]=1;
            for(int j=2*i;j<=m;j+=i){
                f[j]=2;
            }
        }
    }
    for(int i=1;i<=m;i++){
        tot+=(f[i]==1)?1:0;
        s[i]=tot;
    }
    for(int i=1;i<=n;i++){
        scanf("%d%d",&l,&r);
        if(l>=1&&r<=m){
            printf("%d\n",s[r]-s[l-1]);
        }
        else printf("Crossing the line\n");
    }
    return 0;
}