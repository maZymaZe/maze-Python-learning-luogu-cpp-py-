#include<queue>
#include<cstdio>
#include<vector>
using namespace std;
struct cmp{
    bool operator ()(long long a, long long b){
        return a>b;
    }
};
priority_queue<long long,vector<long long>,cmp>  pq;
int main() {
    int n;
    long long pre=0;
    scanf("%d",&n);
    if(n==0){
        printf("0");
        return 0;
    }
    const int a[]={2,3,5,7};
    pq.push(1);
    n--;
    while(n){
        long long t=pq.top();
        if(t==pre){
            pq.pop();
            continue;
        }
        for(int i=0;i<4;i++){
            if(t*a[i]>t)pq.push(t*a[i]);
        }
        n--;
        pq.pop();
        pre=t;
    }
    while(pq.top()==pre)pq.pop();
    printf("%lld",pq.top());
    return 0;
}
