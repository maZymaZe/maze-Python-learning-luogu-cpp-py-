#include<cstdio>
const int NMAX=1e5 + 10;
int a[NMAX],b[NMAX],ans=0,pre=0,n,t;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d%d",&a[i],&b[i]);
    }
    for(int i=1;i<=5;i++){
        pre=0;
        for(int j=1;j<=n;j++){
            if(a[j]==i||b[j]==i){
                pre++;
                if(pre>ans)ans=pre,t=i;
            }else{
                pre=0;
            }
        }
    }
    printf("%d %d",ans,t);
    return 0;
}