#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
long long a,b,c,ans=1ll<<62,ret=1ll<<62;
void ck(long long x){
    long long ta=ceil((double)(a)/x)*x;
    long long tb=ta+c;
    long long tmp=ta*tb/x;
    if(tmp==ret){
        if(ta-a<ans)ans=ta-a;
    }else if(tmp<ret)ans=ta-a,ret=tmp;
}
int main(){
    
    cin>>a>>b;
    if(a==b){
        cout<<0<<endl;
        return 0;
    }
    if(a>b)swap(a,b);
    c=b-a;
    long long sq=sqrt(c);
    for(int i=1;i<=sq;i++){
        if(c%i==0){
            ck(i);
            ck(c/i);
        }
    }
    cout<<ans<<endl;
    return 0;
}