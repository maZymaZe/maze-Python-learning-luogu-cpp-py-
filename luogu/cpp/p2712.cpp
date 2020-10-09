#include<cstdio>
#include<queue>
using namespace std;
int n ,t ,a[503][503]={0},tp,h,indo[503]={0},cnt=0,pls[503];
queue<int> q;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d%d",&pls[i],&t);
        for(int j=0;j<t;j++){
            scanf("%d",&tp);
            a[pls[i]][tp]=1;
            indo[tp]++;
        }
    }
    for(int i=1;i<=n;i++){
        if(!indo[pls[i]])cnt++,q.push(i);
    }
    while(!q.empty()){
        int w= q.front();
        q.pop();
        for(int i=1;i<=n;i++){
            if(a[pls[w]][pls[i]]){
                indo[pls[i]]--;
                if(!indo[pls[i]])cnt++,q.push(i);
            }
        }
    }
    printf(cnt==n?"YES":"%d",n-cnt);
    return 0;
}