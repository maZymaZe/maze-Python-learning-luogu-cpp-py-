#include<iostream>
#include<string>
using namespace std;
const int NMAX= 1e5 + 10,INF=0x3f3f3f3f;
string s,t;
int nx[NMAX][26],T;
int main() {
    cin>>T;
    while(T--){
        cin>>s>>t;
        int ls=s.length(), lt=t.length();
        for(int i=0;i<26;i++)nx[ls][i]=INF;
        for(int i=ls-1;i>=0;i--){
            for(int j=0;j<26;j++){
                nx[i][j]=nx[i+1][j];
            }
            nx[i][s[i]- 'a']=i+1;
        }
        int f=0,ans=0,p=ls;
        for(int i=0;i<lt;i++){
            if(nx[0][t[i]- 'a']==INF){
                f=1;break;
            }
            if(nx[p][t[i]- 'a']==INF){
                p=0;
                ans++;
            }
            p=nx[p][t[i]- 'a'];
        }
        if(f==1)ans=-1;
        cout<<ans<<endl;
    }
    return 0;
}