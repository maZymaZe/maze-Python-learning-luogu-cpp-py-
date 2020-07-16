#include<cstdio>
const int N=1e5+10;
int n,m,t,x,y,a[N];
int main(){
    scanf("%d%d", &n,&m);
    for(int i=1;i<=m;i++){
        scanf("%d",&t);
        if(t==1){
            scanf("%d%d",&x,&y);
            for(int j=x;j<N;j+=(-j&j))a[j]++;
            for(int j=y+1;j<N;j+=(-j&j))a[j]--;
        }
        else{
            scanf("%d",&x);
            t=0;
            for(int j=x;j;j-=(-j&j))t+=a[j];
            printf("%d\n",t&1);
        }
    }
    return 0;
}