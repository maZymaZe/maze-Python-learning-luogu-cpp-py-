#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
const int NMAX=3e5+10;
int n,T,a[NMAX],mdelta;
int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        mdelta=n;
        for(int i=1;i<=n; i++){
            scanf("%d",&a[i]);
            int delat=a[i]-min(i-1,n-i);
            mdelta=min(mdelta,delat);
        }
        if(mdelta<0){
            printf("NO\n");
        }
        else {
            if(n%2==0&&a[n/2]==n/2-1&&a[n/2+1]==n/2-1){
                printf("NO\n");
            }
            else printf("YES\n");
        }
    }
    return 0;
}