#include<algorithm>
#include<cstdio>
#include<queue>
using namespace std;
struct func{
    int a,b,c;
}f[10005];
struct pr{
    int g;
    long long v;
    
};
struct cmp{
    bool operator()(pr a,pr b){
        return a.v>b.v;
    }
};
/*
bool cmp(pr a,pr b){
    return a.v>b.v;
};*/

int n,m,l,r,ww[10005];
inline long long fx(int t,int x){
    return (long long)f[t].a*x*x+(long long)f[t].b*x+f[t].c;
}
priority_queue<pr,vector<pr>,cmp> st;
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d%d%d",&f[i].a,&f[i].b,&f[i].c);
    }
    for(int i=1;i<=n;i++){
        pr tt;
        tt.g=i;tt.v=fx(i,1);
        st.push(tt);
        ww[i]=1;
    }
    for(int i=1;i<=m;i++){
        r=st.top().g;
        printf("%lld ",st.top().v);
        st.pop();
        pr tt;
        tt.g=r;
        tt.v=fx(r,++ww[r]);
        st.push(tt);
    }
    return 0;
}