#include <cstdio>
#include <deque>
#include <iostream>
using namespace std;
int n, m, indegree[10010], h[10010],t1,t2,t3,t[10010],pe=0,est[10010],ans=0;
struct edge {
    int u, v, nx;
}e[1000004];
int topo() {
    deque<int> dq;
    int tot = 0;
    for (int i = 1; i <= n; i++) {
        if (indegree[i] == 0) dq.push_back(i),est[i]=t[i];
    }
    while (!dq.empty()) {
        int hd = dq.front();
        for (int i = h[hd]; i; i = e[i].nx) {
            indegree[e[i].v]--;
            if(est[e[i].v]<est[hd])est[e[i].v]=est[hd];
            if (indegree[e[i].v] == 0) {
                dq.push_back(e[i].v),est[e[i].v]+=t[e[i].v];
            }
            
        }
        dq.pop_front();
    }
    for(int i=1;i<=n;i++){
        if(ans<est[i])ans=est[i];
    }
    return ans;
}
int main() {
    scanf("%d", &n);
    for(int i = 1; i<=n;i++){
        scanf("%d%d%d",&t1,&t2,&t3);
        t[t1]=t2;
        while(t3){
            e[++pe].v=t1;
            e[pe].u=t3;
            e[pe].nx=h[t3];
            h[t3]=pe;
            indegree[t1]++;
            scanf("%d",&t3);
        }
    }
    printf("%d",topo());
    return 0;
}