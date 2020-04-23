#include<unordered_map>
#include<cstdio>
using namespace std;
int main(){
    int n,m,t;
    scanf("%d",&n);
    unordered_map<int,int> mp;
    for(int i=1;i<=n;i++){
        scanf("%d",&t);
        mp.insert({t,i});
    }
    scanf("%d",&m);
    for(int i=1;i<=m;i++){
        scanf("%d",&t);
        if(mp.find(t)!=mp.end()){
            printf("%d\n",(mp.find(t))->second);
        }
        else printf("0\n");
    }
    return 0;
}