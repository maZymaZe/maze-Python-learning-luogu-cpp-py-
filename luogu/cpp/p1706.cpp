#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
int a[20],n,s=1;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)a[i]=i,s*=i;
    for(int i=1;i<=s;i++){
        for(int j=1;j<=n;j++){
            printf("%5d",a[j]);
        }
        printf("\n");
        next_permutation(a+1,a+1+n);
    }
    return 0;
}