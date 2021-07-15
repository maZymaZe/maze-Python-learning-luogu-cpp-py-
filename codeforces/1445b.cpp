#include<cstdio>
int max(int a,int b){ return a > b ? a : b;}
int main(){
    int T,a,b,c,d;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d%d%d",&a,&b,&c,&d);
        printf("%d\n",max(a+b,c+d));
    }
    return 0;
}