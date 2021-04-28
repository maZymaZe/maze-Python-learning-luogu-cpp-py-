#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
string str,s1="Monocarp",s2="Bicarp";
int cql,cqr,l,r;
int main(){
    int n;
    cin>>n>>str;
    for(int i=0;i<n;i++){
        if(str[i]!='?'){
            if(i<n/2)l+=str[i]-'0';
            else r+=str[i]-'0';
        }else{
            if(i<n/2)cql++;
            else cqr++;
        }
    }
    if(cql==cqr){
        if(l==r)cout<<s2<<endl;
        else cout<<s1<<endl;
    }else if(cql>cqr){
        cql-=cqr;
        if((r-l)!=cql/2*9)cout<<s1<<endl;
        else cout<<s2<<endl;
    }else {
        cqr-=cql;
        if((l-r)!=cqr/2*9)cout<<s1<<endl;
        else cout<<s2<<endl;
    }
    return 0;
}