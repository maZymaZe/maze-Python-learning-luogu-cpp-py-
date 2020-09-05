#include<cstdio>
#include<string>
#include<iostream>
using namespace std;
int main(){
    int a,b,tru;
    string aa;
    cin>>a;cin>>aa;cin>>b;
    int p=1,l=aa.length();
    for(int i=l-1;i>=0;i--){
        if(aa[i]>='A'&&aa[i]<='F')tru+=(aa[i]-'A'+10)*p;
        else tru+=(aa[i]-'0')*p;
        p*=a;
    }
    int stk[40]={0},tp=0;
    while(tru){
        stk[++tp]=tru%b;
        tru/=b;
    }
    for(int i=tp;i>0;i--){
        if(stk[i]>9)printf("%c",stk[i]-10+'A');
        else printf("%d",stk[i]);
    }
    return 0;
}