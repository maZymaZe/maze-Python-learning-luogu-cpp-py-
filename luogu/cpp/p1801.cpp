#include<queue>
#include<iostream>
#include<cstdio>
using namespace std;
int a[200003],n,g,m;
priority_queue<int> big,small;
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    scanf("%d",&g);
    m--;
    for(int i=1;i<=n;i++){
        small.push(-a[i]);
        if(!big.empty()){
            if(small.top()*(-1)<big.top()){
                int t1=(-1)*small.top(),t2=(big.top());
                big.pop();small.pop();
                big.push(t1);small.push(-1*t2);
            }
        }

        while(i==g){
            printf("%d\n",-1*small.top());
            int t3=-1*small.top();
            small.pop();
            big.push(t3);
            if(m==0)break;
            if(m!=0)scanf("%d",&g),m--;
            
        } 
    }
    return 0;
}