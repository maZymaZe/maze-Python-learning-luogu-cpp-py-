#include<cstdio>
#include<algorithm>
using namespace std;
int a[40],k,n,f[20005];
int main()
{
 
    scanf("%d%d",&k,&n);
      
    for(int i=1;i<=n;i++)
    scanf("%d",&a[i]);
      
    for(int j=1;j<=n;j++)
    {
        for(int i=k;i>=a[j];i--)
        {
            f[i]=max(f[i],f[i-a[j]]+a[j]);
        }
    }
    printf("%d",k-f[k]);
    return 0;
}