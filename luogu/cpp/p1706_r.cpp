#include<algorithm>
#include<cstdio>
#include<iostream>
using namespace std;
int n,a[20],s=1,k;
void reverse(int l,int r){
    r--;
    while(l<r){
        swap(a[l],a[r]);
        l++;r--;
    }
}
void next_p(int l,int r){
    int i,j;
    i=r-2;
    while(i>=l&&a[i]>=a[i+1])i--;
    if(i==l-1)reverse(l,r);
    else{
        j=r-1;
        while(a[j]<=a[i])j--;
        swap(a[i],a[j]);
        reverse(i+1,r);
    }
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        a[i]=i;s*=i;
    }
    for(int i=1;i<=s;i++){
        for(int j=1;j<=n;j++){
            printf("%5d",a[j]);
        }
        printf("\n");
        next_p(1,n+1);
    }
    return 0;
}