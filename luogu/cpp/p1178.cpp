#include<iostream>
#include<algorithm>
using namespace std;
int nums[66666],ans=0;
double t;
int f[]={0,0,31,60,91,121,152,182,213,244,274,305,335};
int main(){
    int a,b,n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a>>b;
        nums[i]=f[a]+b;
    }
    sort(nums+1,nums+1+n);
    nums[n+1]=367;
    for(int i=1;i<=n+1;i++){
        ans=max(nums[i]-nums[i-1]-1,ans);
    }
    t=(1.0*ans*24*3600/366)+0.5;
    ans=t;
    cout<<ans<<endl;
    return 0;
}