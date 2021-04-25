#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int NMAX=2e5+10;
struct stp2{
    int x,time;
    bool operator<(const stp2& other)const{
        return time<other.time;
    }
};
stp2 swt[NMAX];
int n,ori[NMAX],op,tx,ty,q;
vector<stp2> v;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&ori[i]);
    }
    scanf("%d",&q);
    for(int i=1;i<=q;i++){
        scanf("%d",&op);
        if(op==2){
            scanf("%d",&tx);
            while(!v.empty()&&v.back().x<=tx){
                v.pop_back();
            }
            v.push_back({tx,i});
        }else{
            scanf("%d%d",&tx,&ty);
            swt[tx]={ty,i};
        }
    }
    for(int i=1;i<=n;i++){
        if(swt[i].time==0){
            if(!v.empty()&&ori[i]<v[0].x){
                printf("%d ",v[0].x);
            }else{
                printf("%d ",ori[i]);
            }
        }else{
            if(v.empty()){
                printf("%d ",swt[i].x);
            }else{
                auto it=lower_bound(v.begin(),v.end(),(stp2){0,swt[i].time});
                if(it==v.end()){
                    printf("%d ",swt[i].x);
                }else{
                    if(it->x>swt[i].x){
                        printf("%d ",it->x);
                    }else{
                        printf("%d ",swt[i].x);
                    }
                }
            }
        }
        
    }
    return 0;
}