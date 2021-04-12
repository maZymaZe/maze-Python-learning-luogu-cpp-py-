#include<cstdio>
int n,flag=0,now,last,ans=1;
int main(){
    scanf("%d%d",&n,&now);
    while(--n){
        last=now;
        scanf("%d",&now);
        if(now==last)continue;
        if(flag^(now<last))ans++,flag=now<last;
    }
    printf("%d\n",ans);
    return 0;
}