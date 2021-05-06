#include<cstdio>
#include<unordered_map>
#include<vector>
using namespace std;
typedef long long ll;
const int NMAX=7020;
int n;
vector<ll> ckl;
ll a[NMAX],b[NMAX],ans=0,tot;
unordered_map<ll,int> mp;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        if(mp.count(a[i])){
            if(mp[a[i]]==1){
                ckl.push_back(a[i]);
                mp[a[i]]=2;
            }
        }else mp[a[i]]=1;
    }
    for(int i=1;i<=n;i++){
        scanf("%lld",&b[i]);
    }
    int l=ckl.size();
    if(!l){
        printf("0\n");
        return 0;
    }
    mp.clear();
    for(int i=0;i<l;i++){
        mp[ckl[i]]=1;
    }
    for(int i=1;i<=n;i++){
        if(mp.count(a[i]))tot+=b[i];
        else for(int j=0;j<l;j++){
            if((ckl[j]|a[i])==ckl[j]){
                tot+=b[i];
                break;
            }
        }
    }
    printf("%lld\n", tot);
    return 0;
}