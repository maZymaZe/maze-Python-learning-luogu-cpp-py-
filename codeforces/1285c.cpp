#include<algorithm>
#include<iostream>
#include<cmath>
using namespace std;
long long x,a,b,s;
int main(){
    cin>>x;
    s=sqrt(x);
    for(long long i=s;i>0;i--){
        if(x%i==0){
            a=i;
            b=x/a;
            if(__gcd(a,b)==1){
                cout<<a<<" "<<b<<endl;
                return 0;
            }
        }
    }
    return 0;
}