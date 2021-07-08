#include<cstdio>
#include<algorithm>
#include<stack>
using namespace std;
const int NMAX=1e6+ 10;
int n,cnt=0;
struct NODE{
    int l,r;
    double val;
};
stack<NODE> s;
double a[NMAX],tot=0,ans[NMAX];
double sum(NODE&a){
    return a.val*(a.r-a.l+1);
}
void update(int x){
    NODE p={s.top().l,x,(sum(s.top())+a[x])/(x-s.top().l+1)};
    s.pop();
    while(!s.empty()&&p.val<s.top().val){
        NODE cur=s.top();
        s.pop();
        p.val=(sum(p)+sum(cur))/(p.r-cur.l+1);
        p.l=cur.l;
    }
    s.push(p);
}
void prnt(){
    if(s.empty())return;
    NODE tmp=s.top();
    s.pop();
    prnt();
    for(int i=tmp.l;i<=tmp.r;i++){
        printf("%.9lf\n",tmp.val);
    }
}
int main(){
    scanf("%d",&n);
    for(int i=1; i <=n; i++){
        scanf("%lf",&a[i]);
    }
    for(int i=1; i <=n; i++){
        if(s.empty()||a[i]>s.top().val){
            s.push({i,i,a[i]});
        }else{
            update(i);
        }
    }
    prnt();
    return 0;
}