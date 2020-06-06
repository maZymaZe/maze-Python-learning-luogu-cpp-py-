#include<cstdio>
#include<algorithm>
using namespace std;
int a[501][501]={0},ans=0;
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<n;i++){
        for(int j=i+1;j<=n;j++){
            scanf("%d",&a[i][j]);
            a[j][i] =a[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        sort(a[i]+1,a[i]+n+1);
        ans=max(ans,a[i][n-1]);
    }
    printf("1\n%d",ans);
    return 0;
}