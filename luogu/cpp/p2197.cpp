#include <cstdio>
int main(){
    int a,t,b,c;
    scanf("%d",&t);
    while (t--) {
        a=0;
        scanf("%d",&b);
        for(int i=1;i<=b;i++)scanf("%d",&c),a^=c;
        printf(a?"Yes\n":"No\n");
    }
    return 0;
}