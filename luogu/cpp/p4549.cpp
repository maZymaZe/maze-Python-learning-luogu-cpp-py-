#include<cstdio>
int gcd(int a, int b){
    if(a%b==0)return b;
    return gcd(b,a%b);
}
int main(){
    int ans,t,n;
    scanf("%d%d",&n,&ans);
    int p=1;while(ans==0){
        p++;scanf("%d",&ans);
    }
    if(ans<0)ans=-ans;
    
    for(int i=p;i<n;i++){
        scanf("%d",&t);
        if(t==0)continue;
        if(t<0)t=-t;
        ans=gcd(ans,t);
    }
    printf("%d\n",ans);
    return 0;
}