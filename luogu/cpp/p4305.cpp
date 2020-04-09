#include<set>
#include<unordered_set>
#include<iostream>
#include<cstdio>
using namespace std;
unordered_set<int> s;
int n,m,t;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        s.clear();
        scanf("%d",&m);
        for(int j=1;j<=m;j++){
            scanf("%d",&t);
            if(!s.count(t)){
                printf("%d ",t);
                s.insert(t);
            }
        }
        printf("\n");
    }
    return 0;
}