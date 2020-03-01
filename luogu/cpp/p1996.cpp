#include<iostream> 
#include<cstdlib> 
#include<cstdio> 
#include<cmath> 
using namespace std; 
int main() 
{ 
    int chu=0,bao=0,lun=0,m,n,s[1008]={0};
    cin>>n>>m;
    while(chu!=n)
    {
        lun++;
        if(lun==n+1)lun=1;
        if(s[lun]==0)bao++;
        if(bao==m)
        {
            bao=0;
            s[lun]=1;
            cout<<lun<<' ';
            chu++;
             
             
        }
    }
    return 0; 
} 