#include<string>
#include<cstdio>
#include<iostream>
#include<stack>
using namespace std;
stack<int> lf;
string ip;
int main(){
    cin>>ip;
    int i=0;
    while(i!=ip.size()){
        if(ip[i]=='['){
            ip=ip.substr(0,i)+ip.substr(i+1,ip.size());
            lf.push(i);
        }
        if(ip[i]==']'){
            int p=lf.top();lf.pop();
            if(ip[p+1]<='9'&&ip[p+1]>='0'){
                int tm=(ip[p]-'0')*10+(ip[p+1]-'0');
                string t=ip.substr(p+2,i-p-2);
                string o=ip.substr(0,p);
                string e=ip.substr(i+1,ip.size()-i-1);
                for(int j=1;j<=tm;j++){
                    o=o+t;
                }
                i=o.size()-1;
                ip=o+e;
            }
            else{
                int tm=(ip[p]-'0');
                string t=ip.substr(p+1,i-p-1);
                string o=ip.substr(0,p);
                string e=ip.substr(i+1,ip.size()-i-1);
                for(int j=1;j<=tm;j++){
                    o=o+t;
                }
                i=o.size()-1;
                ip=o+e;
            }
        }
        i++;
    }
    cout<<ip<<endl;
    return 0;
}