#include<cstdio>
int T,x;
int main() {
    scanf("%d",&T);
    while(T--){
        scanf("%d",&x);
        if(x&1)printf("7"),x-=3;
        x/=2;
        while(x--) printf("1");
        printf("\n");
    }
    return 0;
}