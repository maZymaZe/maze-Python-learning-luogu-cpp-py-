#include<iostream>
using namespace std;
typedef long long ll;
const int NMAX=3e5+10;
ll n,mod,a[NMAX],ans=0;
int main(){
    cin>>n>>mod;
    a[0]=1;
    for(int i=1;i<=n;i++){
        a[i]=a[i-1]*i%mod;
    }
    ans=n*a[n]%mod;
    for(int i=1;i<n;i++){
        (ans+=(n-i)*(n-i)%mod*a[i+1]%mod*a[n-i-1]%mod)%=mod;
    }
    cout<<ans<<endl;
    return 0;
}