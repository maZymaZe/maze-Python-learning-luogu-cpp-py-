#include<iostream>
using namespace std;
long long ans=0,n,ts[20];
int p,d[30],ps[20];

int main(){
    cin>>n;
    long long t=n;
    while(t){
        d[++p]=t% 10;
        t/=10;
    }
    for(int i=1;i<10;i++){
        ps[i]=ps[i-1]+i;
    }
    ts[0]=1;
    for(int i=1;i<12;i++){
        ts[i]=ts[i-1]*10;
    }
    t=n;
    long long ct=0;
    for(int i=1;i<=p;i++){
       long long pr=t/ts[i];
       ans+=(ct+1)*d[i];
       if(d[i])ans+=ts[i-1]*ps[d[i]-1];
       if(pr)ans+=(pr)*ts[i-1]*ps[9];
       ct+=d[i]*ts[i-1];
    }
    cout<<ans<<endl;
    return 0;
}