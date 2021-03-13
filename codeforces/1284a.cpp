#include<iostream>
#include<string>
using namespace std;
string a[21],b[21];
int n,m,q,t;
int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<m;i++)cin>>b[i];
    cin>>q;
    while(q--){
        cin>>t;
        t--;
        cout<<a[t%n]<<b[t%m]<<endl;
    }
    return 0;
}