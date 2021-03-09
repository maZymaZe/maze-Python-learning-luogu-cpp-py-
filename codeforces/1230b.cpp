#include<cstdio>
const int NMAX=2e5+10;
int n,k,a[NMAX];
int main() {
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)scanf("%1d",&a[i]);
    if(n==1&&k){
        k--;
        a[1]=0;
    }
    else{
        if(a[1]!=1&&k){
            a[1]=1,k--;
        }
        for(int i=2;i<=n&&k;i++){
            if(a[i]!=0){
                a[i]=0;
                k--;
            }
        }
    }
    for(int i=1;i<=n;i++)printf("%d",a[i]);
    return 0;
}