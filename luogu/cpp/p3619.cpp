#include<cstdio>
#include<algorithm>
using namespace std;
const int NMAX = 1e5+ 10;
struct pr{
    int a, b;
}gp[NMAX],gn[NMAX];
bool cmpp(const pr& pr1, const pr& pr2){
    return pr1.a<pr2.a;
}
bool cmpn(const pr& pr1, const pr& pr2){
    return pr1.a+pr1.b>pr2.a+pr2.b;
}
long long t;
int n,T,pgp,pgn,t1,t2;
bool flag;
int main(){
    scanf("%d",&T);
    while(T--){
        pgp=pgn=0;
        flag=true;
        scanf("%d%lld",&n,&t);
        for(int i=1;i<=n;i++){
            scanf("%d%d",&t1,&t2);
            if(t2>=0){
                gp[++pgp]={t1,t2};
            }else{
                gn[++pgn]={t1,t2};
            }
        }
        if(t<=0){
            printf("-1s\n");
            continue;
        }
        sort(gp+1,gp+1+pgp,cmpp);
        sort(gn+1,gn+1+pgn,cmpn);
        for(int i=1;i<=pgp;i++){
            if(t>gp[i].a){
                t+=gp[i].b;
            }else{
                flag=false;
                break;
            }
        }
        if(!flag){
            printf("-1s\n");
            continue;
        }
        for(int i=1;i<=pgn;i++){
            if(t>gn[i].a){
                t+=gn[i].b;
            }else{
                flag=false;
                break;
            }
            if(t<=0){
                flag=false;
                break;
            }
        }
        if(!flag){
            printf("-1s\n");
        }
        else{
            printf("+1s\n");
        }
    }
    return 0;
}