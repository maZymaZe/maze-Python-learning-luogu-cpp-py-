#include <cstdio>
int main(){
    int k,a,b,c;
    scanf("%d",&k);
    for(a=b=1;a+b<=k;){
        c=a+b;
        b=a;
        a=c;
    }
    printf("m=%d\nn=%d\n",b,a);
    return 0;;
}