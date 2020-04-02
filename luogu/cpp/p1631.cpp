#include<algorithm>
#include<cstdio>
#include<queue>
using namespace std;
struct pr{
    int g;
    long long v;
};
struct cmp{
    bool operator()(pr a,pr b){
        return a.v>b.v;
    }
};

int n,r,a[100007],b[100007],ww[100005];
inline long long fx(int t,int x){
    return a[t]+b[x];
}
priority_queue<pr,vector<pr>,cmp> st;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=n;i++){
        scanf("%d",&b[i]);
    }
    for(int i=1;i<=n;i++){
        pr tt;
        tt.g=i;tt.v=fx(i,1);
        st.push(tt);
        ww[i]=1;
    }
    for(int i=1;i<=n;i++){
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