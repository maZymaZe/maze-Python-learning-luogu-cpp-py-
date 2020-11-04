#include <cstdio>
int n;
int main(){
    scanf("%d",&n);
    if(n<9)printf("0\n");
    else if(n==9)printf("8\n");else{
        printf("72");
        for(int i=1;i<=n-10;i++)printf("0");
        printf("\n");
    }
    return 0;
}