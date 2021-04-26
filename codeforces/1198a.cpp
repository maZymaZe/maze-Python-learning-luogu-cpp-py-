#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;
const int NMAX=4e5+10;
typedef long long ll;
int n,t,k;
int lm[50],a[NMAX];
vector<int> ct;
int main(){
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    sort(a+1,a+1+n);
    int maxtp=pow(2,min(k*8/n,20));
    int cnt=1,pre=a[1],ans=n;
    for(int i=2;i<=n;i++){
        if(a[i]==pre){
            cnt++;
        }else{
            ct.push_back(cnt);
            cnt=1;
            pre=a[i];
        }
    }
    ct.push_back(cnt);
    int vl=0,len=ct.size();
    for(int i=0;i<len&&i<maxtp;i++){
        vl+=ct[i];
    }
    ans=min(ans,n-vl);
    for(int i=maxtp;i<len;i++){
        vl-=ct[i-maxtp];
        vl+=ct[i];
        ans=min(ans,n-vl);
    }
    printf("%d\n",ans);
    return 0;
}