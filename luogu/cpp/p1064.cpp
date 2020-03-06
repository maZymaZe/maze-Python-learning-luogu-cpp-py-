#include<cstdio>
int max(int a,int b){
    if(a>b)return a;
    else return b;
}
int gv[70][5],gp[70][5],dp[32100],n,m;
int main(){
    int t1,t2,t3;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        scanf("%d%d%d",&t1,&t2,&t3);
        if(t3==0){
            gp[i][1]=t1;
            gv[i][1]=t2*t1;
        }
        else{
            if(gp[t3][2]==0){
                gp[t3][2]=gp[t3][1]+t1;
                gv[t3][2]=gv[t3][1]+t1*t2;
            }
            else{
                gp[t3][3]=gp[t3][1]+t1;
                gv[t3][3]=gv[t3][1]+t1*t2;
                gp[t3][4]=gp[t3][2]-gp[t3][1]+gp[t3][3];
                gv[t3][4]=gv[t3][2]-gv[t3][1]+gv[t3][3];
            }
        }
    }
    for(int i=1;i<=m;i++){
        if(gp[i][1])
        for(int j=n;j>=gp[i][1];j--){
            for(int k=1;k<=4;k++)
            if(gp[i][k]&&gp[i][k]<=j){
                dp[j]=max(dp[j],dp[j-gp[i][k]]+gv[i][k]);
            }
        }    
    }
    printf("%d",dp[n]);
    return 0;
}