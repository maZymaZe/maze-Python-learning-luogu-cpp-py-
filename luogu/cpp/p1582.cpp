#include<cstdio>
int main(){
    int bt[40]={0},bp=0,n,k;
    int ans=0,cnt=0;
    scanf("%d%d",&n,&k);
    while (n!=0)
    {
       bp++;
       bt[bp]=n%2;
       n/=2;
    }
    for(int i=1;i<=bp;i++){
        if(bt[i]==1)cnt++;
    }
    if(cnt<=k)printf("0\n");
    else{
        for(int i=1;i<=bp;i++){
            if(bt[i]==1){
                ans+=(1<<(i-1));
                bt[i+1]++;
            }
            else if(bt[i]==2){
                bt[i+1]++;
                cnt--;
                if(cnt<=k){
                    printf("%d",ans);
                    break;
                }
            }
        }
    }
    return 0;
}