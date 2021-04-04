#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
typedef long long ll;
ll a,b;
ll ten[20],f[20],cnta[20],cntb[20];
int d[20],pd;
void query(ll x,ll* v){
    pd=0;
    while(x){
        d[++pd]=x%10;
        x/=10;
    }
    for(int i=pd;i>=1;i--){
        for(int j=0;j<10;j++){
            v[j]+=f[i-1]*d[i];
        }
        for(int j=0;j<d[i];j++){
            v[j]+=ten[i-1];
        }
        ll n2=0;
        for(int j=i-1;j>=1;j--){
            n2=n2*10+d[j];
        }
        v[d[i]]+=n2+1;
        v[0]-=ten[i-1];
    }

}
int main(){
    cin>>a>>b;
    ten[0]=1;
    for(int i=1;i<16;i++){
        f[i]=f[i-1]*10+ten[i-1];
        ten[i]=10*ten[i-1];
    }
    query(a-1,cnta);
    query(b,cntb);
    for(int i=0;i<10;i++){
        cout<<cntb[i]-cnta[i]<<' ';
    }
    return 0;
}