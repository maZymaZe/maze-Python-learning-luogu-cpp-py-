#include<cstdio>
int n,t,f=-1,m=-1;
int main() {
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&t);
        if(f==-1&&t==0)f=i,m=i;
        if(m!=-1&&t==0)m=i;
    }
    printf((f&1)&&((n-m+1)&1)?"NO":"YES");
    return 0;
}