#include <cmath>
#include <cstdio>
#include <cstdlib>
struct node {
    double x, y;
} p[110];
int T, n;
double ansx, ansy, ax, ay, t, ans;
void clear() {
    ax = ay = 0, ans = 1e8;
}
double cal(double x, double y) {
    double res = 0;
    for (int i = 0; i < n; i++) {
        double dx = x - p[i].x, dy = y - p[i].y;
        res += sqrt(dx * dx + dy * dy);
    }
    return res;
}
const double delta=0.996;
void simulate_anneal(){
    double x=ansx, y=ansy;
    t=3000;
    while(t>1e-15){
        double X=x+((rand()<<1)-RAND_MAX)*t;
        double Y=y+((rand()<<1)-RAND_MAX)*t;
        double now=cal(X,Y);
        double Delta=now-ans;
        if(Delta<0){
            ansx=X,ansy=Y;
            ans=now;
            x=X,y=Y;
        }
        else if(exp(-Delta/t)*RAND_MAX>rand())x=X,y=Y;
        t*=delta;
    }
}
void work(){
    ansx=ax/n,ansy=ay/n;
    for(int i=0;i<5;i++)simulate_anneal();
}
int main(){
    srand(76878787);
    scanf("%d",&T);
    for(int i=1;i<=T;i++){
        scanf("%d",&n);
        clear();
        for(int j=0;j<n;j++){
            scanf("%lf%lf",&p[j].x,&p[j].y);
            ax+=p[j].x,ay+=p[j].y;
        }
        work();
        printf("%.0lf\n",round(ans));
        if(i!=T){printf("\n");}
    }
    return 0;
}