#include<iostream> 
#include<cstdlib> 
#include<cstdio> 
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;
int a[1003][1003],n;
 int main()
{
    
     
    cin>>n;
     
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    for(int i=n-1;i>=1;i--)
    {
        for(int j=1;j<=i;j++)
        {
            a[i][j]+=max(a[i+1][j],a[i+1][j+1]);
        }
    }
    cout<<a[1][1];
    return 0; 
} 