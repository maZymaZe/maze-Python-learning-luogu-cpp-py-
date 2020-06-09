#include<string>
#include<iostream>
#include<algorithm>
using namespace std;
string s[110],st[110];
bool m[110];
int n,f=0,d=0;
int main(){
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>s[i]>>st[i];
        if(st[i][0]=='S')m[i]=true;
    }
    for(int i=0; i<n; i++){
        if(m[i])cout<<s[i]<<endl;
        else{
            if(f==0){
                while(d<n&&st[d][0]!='D'){
                    d++;
                }
                if(d<n){
                    cout<<s[d]<<endl;
                    d++;
                }
                else{
                    f=1;d=0;
                }
            }
            if(f==1){
                while(d<n&&st[d][0]!='U'){
                    d++;
                }
                if(d<n){
                    cout<<s[d]<<endl;
                    d++;
                }
            }
        }
    }
    return 0;
}