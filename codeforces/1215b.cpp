#include<cstdio>
int n,a[200002];
long long cnt1,cnt2,cnt3,cnt4,t;
int main(){
    scanf("%d",&n);
    for(int i=1; i <= n; i++)scanf("%d",&a[i]);
    if(a[n]>0)cnt2++,cnt4++;
    else cnt1++,cnt3++;
    for(int i=n-1;i>0; i--){
        if(a[i]>0)cnt4=cnt4+1;
        else if(a[i]<0){
            t=cnt4;
            cnt4=cnt3;
            cnt3=t+1;
        }
        cnt1+=cnt3,cnt2+=cnt4;
    }
    printf("%lld %lld",cnt1,cnt2);
    return 0;
}