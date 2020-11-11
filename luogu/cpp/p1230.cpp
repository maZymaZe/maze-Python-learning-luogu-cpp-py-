#include<cstdio>
#include<algorithm>
using namespace std;
const int NMAX=505;
struct pr{
    int t,w;
    bool operator<(const pr&x){
        if(w>x.w)return 1;
        return 0;
    }
}p[NMAX];
int tot,n,used[NMAX];
int main(){
    scanf("%d%d",&tot,&n);
    for(int i=1;i<= n; i++)scanf("%d",&p[i].t);
    for(int i=1;i<= n; i++)scanf("%d",&p[i].w);
    sort(p+1,p+n+1);
    for(int i=1;i<= n; i++){
        int g=p[i].t;
        while(g>0&&used[g])g--;
        if(g)used[g]=1;
        else tot-=p[i].w;
    }
    printf("%d",tot);
    return 0;
}