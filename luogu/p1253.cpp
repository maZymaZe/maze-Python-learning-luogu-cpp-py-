#include<cstdio>
#include<algorithm>
using namespace std;
struct pr{
    int a,b,id;
}p[10003];
int n;
bool cmp(const pr&a,const pr&b){
    return a.a*1.0*a.b>b.a*1.0*b.b;
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d%d",&p[i].a,&p[i].b);
        p[i].id=i;
    }
    sort(p+1,p+n+1,cmp);
    for(int i=1;i<=n;i++){
        printf("%d ",p[i].id);
    }
    return 0;
}