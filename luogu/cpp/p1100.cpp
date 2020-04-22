#include<cstdio>
int main(){
    unsigned int a;
    scanf("%u",&a);
    a=(a<<16)+(a>>16);
    printf("%u",a);
    return 0;
}