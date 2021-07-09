#include<string>
#include<iostream>
#include<cstdio>
using namespace std;
const int MMAX=2e5+10;
int ps[MMAX][27]={0},u,v,n;
string s; 
int main(){
    cin>>s;
    scanf("%d",&n);
    int l=s.length();
    for(int i=0; i<l;i++){
        for(int j=0; j<26;j++){
            ps[i+1][j]=ps[i][j];
        }
        ps[i+1][s[i]- 'a']++;
    }
    while(n--){
        scanf("%d%d",&u,&v);
        if(u==v||s[u-1]!=s[v-1]){
            printf("YES\n");
            continue;
        }else{
            int cnt=0;
            for(int i=0;i<26;i++){
                if(ps[v][i]-ps[u-1][i])cnt++;
            }
            if(cnt>2)printf("YES\n");
            else printf("NO\n");
        }
    }
    return 0;
}