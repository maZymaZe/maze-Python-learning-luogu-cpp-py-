#include<string>
#include<iostream>
#include<cstring>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7,NMAX=2005;
ll f[NMAX][NMAX],m,d,ans,bt[NMAX],len;
string l,r;
inline ll dfs(int pos,ll sum,bool flag){
    if(pos==-1)return sum==0;
    if(!flag&&f[pos][sum]!=-1)return f[pos][sum];
    ll res=0;
    for(register int i=0,up=flag?bt[pos]:9;i<=up;i++){
        if((len-pos)&1){if(i==d)continue;}
        else {if(i!=d)continue;}
        (res+=dfs(pos-1,(sum*10+i)%m,flag&&(i==up)))%= MOD;
    }
    return flag?res:f[pos][sum]=res;
}
inline int ck(){
    ll sum=0;len=l.size();
    for(register int i=0;i<len;i++){
        int x=l[i]- '0';
        if((i+1)&1){if(x==d)return 0;}
        else{if(x!=d)return 0;}
        sum=(sum*10+x)%m;
    }
    return sum==0;
}
inline ll cal(string&x){
    len=x.size();
    for(register int i=0;i<len; i++)bt[len-i-1]=x[i]-'0';
    return dfs(len-1,0,1);
}
int main(){
    memset(f,-1,sizeof(f));
    cin>>m>>d>>l>>r;
    ans=cal(r)-cal(l);
    ans+=ck();
    cout<<(ans+MOD)% MOD<<endl;
    return 0;
}