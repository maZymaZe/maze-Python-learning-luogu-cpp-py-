#include<cstdio>
int main(){
    int ans[40]={0},n,t=0;
    scanf("%d",&n);
    while(n!=1){
        ans[++t]=(n+1)/2;
        n-=ans[t];
    }
    ans[++t]=1;
    printf("%d\n",t);
    while(t)printf("%d ",ans[t]),t--;
    return 0;
}