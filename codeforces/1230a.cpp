#include<iostream>
using namespace std;
int a,b,c,d,sum;
int main(){
    cin>>a>>b>>c>>d;
    sum=a+b+c+d;
    if(sum%2==1){
        cout<<"NO"<<endl;
        return 0;
    }
    sum/=2;
    if(sum==a||sum==b||sum==c||sum==d||sum==a+b||sum==a+c||sum==a+d||sum==b+c||sum==b+d||sum==c+d){
        cout<<"YES"<<endl;
    }else cout<<"NO"<<endl;
    return 0;
}