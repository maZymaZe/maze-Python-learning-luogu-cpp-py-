#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
int n,t,ans=0;
struct build {
    int f,d;
}b[150004];
int cmp(const build&a,const build&b){
    return a.d< b.d;
}
priority_queue<int> q;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d%d",&b[i].f,&b[i].d);
    }
    sort(b+1,b+1+n,cmp);
    for(int i=1;i<=n;i++){
        if(t+b[i].f<=b[i].d){
            t+=b[i].f;
            ans++;
            q.push(b[i].f);
        }
        else{
            if(!q.empty()&&q.top()>b[i].f){
                t-=q.top()-b[i].f;;
                q.pop();
                q.push(b[i].f);
            }
        }
    }
    printf("%d",ans);
    return 0;
}