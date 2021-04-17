#include<iostream>
using namespace std;
string a;
long long b,c;
int ans[10000],tp=0;
int main(){
    cin>>a>>b;
    int l=a.length();
    c=0;
    for(int i=0;i<l;i++){
        c=c*10+a[i]- '0';
        ans[++tp]=c/b;
        c%=b;
    }
    int f=1;
    for(f=1;f<tp;f++)if(ans[f]!=0)break;
    for(int i=f;i<=tp;i++)cout<<ans[i];
    return 0;
}