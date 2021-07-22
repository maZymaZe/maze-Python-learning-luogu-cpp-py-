#include<algorithm>
#include<cstdio>
using namespace std;
int T,a,c,b,r;
int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d%d%d%d",&a,&b,&c,&r);
        if(a>b)swap(a,b);
        printf("%d\n",(b-a)-max(0,min(b,c+r)-max(a,c-r)));
    }
    return 0;
}