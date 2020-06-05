#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
struct point{
    int x,y;
    double nx;
    bool operator <(const point&t){ return nx<t.nx;}
}p[2000006];
int n,d;
double nw;
int main(){
    scanf("%d%d",&n,&d);
    for(int i=1;i<=n;i++){
        scanf("%d%d",&p[i].x,&p[i].y);
        if(p[i].y>d){
            printf("-1");
            return 0;
        }
        p[i].nx=p[i].x+sqrt(d*d-p[i].y*p[i].y);
    }
    sort(p+1,p+1+n);
    int ans=1;
    nw=p[1].nx;
    d=d*d;
    for(int i=2;i<=n;i++){
        if((nw-p[i].x)*(nw-p[i].x)+p[i].y*p[i].y>d){
            ans++;
            nw=p[i].nx;
        }
    }
    printf("%d",ans);
    return 0;
}