#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
ll dp[25][2521][50];
ll lcm(ll a, ll b){
    return a/__gcd(a,b)*b;
}
int T,dic[2521],bp=0;
ll l,r;
vector<int> digits;

ll dfs(int pos,int sum,int lc,int sp){
    if(pos==-1)return sum%lc==0;
    if(sp==0&&dp[pos][sum][dic[lc]]!=-1)return dp[pos][sum][dic[lc]];
    ll ans=0;
    int MA=(sp?digits[pos]:9);
    for(int i=0;i<=MA;i++){
        int nx=(sum*10+i)%2520;
        int nlc=lc;
        if(i)nlc=lcm(lc,i);
        ans+=dfs(pos-1,nx,nlc,sp&&i==MA);
    }
    if(sp==0){
        dp[pos][sum][dic[lc]]=ans;
    }
    return ans;
}

ll work(ll x){
    digits.clear();
    while(x){
        digits.push_back(x%10);
        x/=10;
    }
    return dfs(digits.size()-1,0,1,1);
}
int main(){
    memset(dp,-1,sizeof(dp));
    for(int i=1;i<=2520;i++){
        if(2520%i==0)dic[i]=++bp;
    }
    cin>>T;
    while(T--){
        cin>>l>>r;
        cout<<work(r)-work(l-1)<<endl;
    }
    return 0;
}