#include<cstdio>
const int INT_MIN=0x80000000;
int main(){
    int n,m;
    int tmp[203]={0},sm[203][203]={0},it;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            scanf("%d",&it);
            sm[i][j]=sm[i-1][j]+it;
        }
    }
    int ma=INT_MIN,tma=INT_MIN,tt=0;
    for(int u=1;u<=n;u++){
        for(int d=u;d<=n;d++){
            for(int i=1;i<=n;i++){
                tmp[i]=sm[d][i]-sm[u-1][i];
            }
            tma=tmp[1];tt=0;
            for(int i=1;i<=n;i++){
                if(tmp[i]>=0){
                    if(tt<0)tt=tmp[i];
                    else tt+=tmp[i];

                    if(tt>tma)tma=tt;
                }
                else{
                    if(tmp[i]>tma){
                        tt=tma=tmp[i];
                    }else{
                        tt+=tmp[i];
                    }
                }
            }
            if(tma>ma){
                ma=tma;
            }
        }
    }
    printf("%d",ma);
    return 0;
}
        