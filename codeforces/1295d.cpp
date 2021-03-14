#include<algorithm>
#include<iostream>
using namespace std;
long long a,b,t,c;
long long query(long long x){
    long long ans=x;
    for(long long i=2;i*i<=x;i++){
        if(x%i==0){
            ans=ans/i*(i-1);
            while(x%i==0)x/=i;
        }
    }
    if(x>1)ans=ans/x*(x-1);
    return ans;
}
int main(){
    cin>>t;
    while(t--){
        cin>>a>>b;
        c=__gcd(a,b);
        b/=c;
        cout<<query(b)<<endl;
    }
    return 0;
}