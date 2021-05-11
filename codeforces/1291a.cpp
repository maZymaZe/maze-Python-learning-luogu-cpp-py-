#include<cstdio>
int dg[4002],n,T,tot;
int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        tot=0;
        for(int i=1;i<=n; i++){
            scanf("%1d",&dg[i]);
            tot+=dg[i];
        }
        int last=n;
        while(last>0){
            if(dg[last]&1)break;
            tot-=dg[last];
            last--;
        }
        if(last==0){
            printf("-1\n");
            continue;
        }
        if(!(tot&1)){
            for(int i=1;i<=last;i++)printf("%d",dg[i]);
            printf("\n");
            continue;
        }
        int tg=last-1;
        while(tg>0){
            if(dg[tg]&1)break;
            tg--;
        }
        if(tg==0)printf("-1\n");
        else{
            for(int i=1;i<=last; i++){
                if(i!=tg)printf("%d",dg[i]);
            }
            printf("\n");
        }
    }
    return 0;
}