#include<cstdio>
void swap(int &a,int &b){int temp=a;a=b;b=temp;}
int main(){
    int a1,a2,k1,k2,n;
    scanf("%d%d%d%d%d",&a1,&a2,&k1,&k2,&n);
    int mi=(k1-1)*a1+(k2-1)*a2;
    int ans1=n-mi,ans2=0;
    if(ans1<0)ans1=0;
    if(k1>k2)swap(k1,k2),swap(a1,a2);
    if(n>=a1*k1){
        ans2=a1;
        n-=a1*k1;
        ans2+=n/k2;
    }else{
        ans2=n/k1;
    }
    printf("%d %d\n",ans1,ans2);
    return 0;
}